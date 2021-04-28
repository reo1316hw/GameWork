/*
@brief	インクルード
*/
#include "Mesh.h"
#include "Renderer.h"
#include "Texture.h"
#include "VertexArray.h"
#include <fstream>
#include <sstream>
#include <document.h>
#include <SDL_log.h>
#include "Math.h"
#include "Collision.h"
#include "RapidJsonHelper.h"

/*
@fn		テクスチャステージを読み込み
@param	_doc rapidJsonオブジェクト
@param	_texStage テクスチャステージ
@param	_stgString メンバ名
@return	テクスチャのID(int型)
*/
int LoadStageTextures(const rapidjson::Document& _doc, TextureStage _texStage, const char* _stgString);

namespace
{
	union Vertex
	{
		float f;
		uint8_t b[4];
	};
}

/*
@fn	コンストラクタ
*/
Mesh::Mesh()
	: mVertexArray(nullptr)
	, mRadius(0.0f)
	, mSpecPower(100.0f)
	, mLuminance(1.0f)
	, mAlpha(1.0f)
	, mBox(Vector3::Infinity, Vector3::NegInfinity)
{
	mStageDefTexture.emplace(TextureStage::DiffuseMap, 0);
	mStageDefTexture.emplace(TextureStage::NormalMap, 0);
	mStageDefTexture.emplace(TextureStage::SpecularMap, 0);
	mStageDefTexture.emplace(TextureStage::EmissiveMap, 0);
}

/*
@fn		メッシュデータの読み込み
@param	_fileName ロードしたいメッシュのファイル名
@param	_renderer Rendererクラスのポインタ
@return true : 成功 , false : 失敗(bool型)
*/
bool Mesh::Load(const std::string & _fileName, Renderer* _renderer)
{
	std::ifstream file(_fileName);
	if (!file.is_open())
	{
		SDL_Log("File not found: Mesh %s", _fileName.c_str());
		return false;
	}

	std::stringstream fileStream;
	fileStream << file.rdbuf();
	std::string contents = fileStream.str();
	rapidjson::StringStream jsonStr(contents.c_str());
	rapidjson::Document doc;
	doc.ParseStream(jsonStr);

	if (!doc.IsObject())
	{
		SDL_Log("Mesh %s is not valid json", _fileName.c_str());
		return false;
	}

	int ver = doc["version"].GetInt();

	// バージョンのチェック
	if (ver != 1)
	{
		SDL_Log("Mesh %s not version 1", _fileName.c_str());
		return false;
	}

	mShaderName = doc["shader"].GetString();

	// Skip the vertex format/shader for now
	// (This is changed in a later chapter's code)
	// 頂点レイアウトとサイズをファイルからセット
	VertexArray::Layout layout = VertexArray::PosNormTex;
	size_t vertSize = 8;

	std::string vertexFormat = doc["vertexformat"].GetString();
	if (vertexFormat == "PosNormSkinTex")
	{
		layout = VertexArray::PosNormSkinTex;
		// This is the number of "Vertex" unions, which is 8 + 2 (for skinning)s　1個の頂点の集合の数　８　＋　２（スキニング分）
		// 3 (位置xyz) + 3(法線xyz) + 2(Boneと重み）＋　2(UV)  の計　10個分（40byte) 　
		vertSize = 10;
	}

	// テクスチャのロード
	const rapidjson::Value& readTextures = doc["textures"];
	if (!readTextures.IsArray() || readTextures.Size() < 1)
	{
		SDL_Log("Mesh %s has no textures, there should be at least one", _fileName.c_str());
		return false;
	}
	mSpecPower = static_cast<float>(doc["specularPower"].GetDouble());

	// エミッシブ強度値（定義されていれば)
	if (IsExistMember(doc, "luminance"))
	{
		mLuminance = ForceGetFloat(doc["luminance"]);
	}

	// 透明度
	if (IsExistMember(doc, "alpha"))
	{
		mAlpha = ForceGetFloat(doc["alpha"]);
	}

	for (rapidjson::SizeType i = 0; i < readTextures.Size(); i++)
	{
		// すでにロードされたテクスチャじゃないか調べる
		std::string texName = readTextures[i].GetString();
		Texture* t = _renderer->GetTexture(texName);
		if (t == nullptr)
		{
			// テクスチャをロードする
			t = _renderer->GetTexture(texName);
			if (t == nullptr)
			{
				// テクスチャがロードできなかった場合、デフォルトのテクスチャを使用
				t = _renderer->GetTexture("Assets/Default.png");
			}
		}
		mTextures.emplace_back(t);

		if (readTextures.Size() == 1)
		{
			mStageDefTexture[TextureStage::DiffuseMap] = t->GetTextureID();
		}
	}

	// テクスチャ読み込み(新ファイル形式)
	if (IsExistMember(doc, "diffusemap"))
	{
		mStageDefTexture[TextureStage::DiffuseMap] = LoadStageTextures(doc, TextureStage::DiffuseMap, "diffusemap");
	}
	mStageDefTexture[TextureStage::NormalMap] = LoadStageTextures(doc, TextureStage::NormalMap, "normalmap");
	mStageDefTexture[TextureStage::SpecularMap] = LoadStageTextures(doc, TextureStage::SpecularMap, "specularmap");
	mStageDefTexture[TextureStage::EmissiveMap] = LoadStageTextures(doc, TextureStage::EmissiveMap, "emissivemap");

	// 頂点配列データをロード
	const rapidjson::Value& vertsJson = doc["vertices"];
	if (!vertsJson.IsArray() || vertsJson.Size() < 1)
	{
		SDL_Log("Mesh %s has no vertices", _fileName.c_str());
		return false;
	}

	std::vector<Vertex> vertices;
	vertices.reserve(vertsJson.Size() * vertSize);
	mRadius = 0.0f;
	for (rapidjson::SizeType i = 0; i < vertsJson.Size(); i++)
	{
		// 今のところは８つの要素とする
		const rapidjson::Value& vert = vertsJson[i];
		if (!vert.IsArray())
		{
			SDL_Log("Unexpected vertex format for %s", _fileName.c_str());
			return false;
		}
		///////////////////////////////////////////////////////////////////////////////
		Vector3 pos(static_cast<float>(vert[0].GetDouble()),
			static_cast<float>(vert[1].GetDouble()),
			static_cast<float>(vert[2].GetDouble()));
		//verts.push_back(pos);
		mRadius = Math::Max(mRadius, pos.LengthSq());

		if (i == 0)
		{
			mBox.InitMinMax(pos);
		}
		mBox.UpdateMinMax(pos);

		// 頂点レイアウトが PosNormTexなら（ボーンが無い）
		if (layout == VertexArray::PosNormTex)
		{
			Vertex v;
			// Add the floats　float値を追加
			for (rapidjson::SizeType j = 0; j < vert.Size(); j++)
			{
				v.f = static_cast<float>(vert[j].GetDouble());
				vertices.emplace_back(v);
			}
		}
		else
		{
			Vertex v;
			// Add pos/normal　頂点と法線を追加　6個分
			for (rapidjson::SizeType j = 0; j < 6; j++)
			{
				v.f = static_cast<float>(vert[j].GetDouble());
				vertices.emplace_back(v);
			}

			// Add skin information　スキン情報追加（ボーン番号:unsigned charの1バイト分）
			for (rapidjson::SizeType j = 6; j < 14; j += 4)  //ループとしては2回転する　1回転目はボーン番号、2回転目はボーンウェイトをintとして取ってくる（使用時に浮動小数化するっぽい）
			{
				v.b[0] = vert[j].GetUint();
				v.b[1] = vert[j + 1].GetUint();
				v.b[2] = vert[j + 2].GetUint();
				v.b[3] = vert[j + 3].GetUint();
				vertices.emplace_back(v);
			}

			// Add tex coords　テクスチャ座標
			for (rapidjson::SizeType j = 14; j < vert.Size(); j++)
			{
				v.f = static_cast<float>(vert[j].GetDouble());
				vertices.emplace_back(v);
			}
		}
	}

	// 半径を2乗する
	mRadius = Math::Sqrt(mRadius);

	// 要素配列データのロード
	const rapidjson::Value& indJson = doc["indices"];
	if (!indJson.IsArray() || indJson.Size() < 1)
	{
		SDL_Log("Mesh %s has no indices", _fileName.c_str());
		return false;
	}

	std::vector<unsigned int> indices;
	indices.reserve(indJson.Size() * 3);
	for (rapidjson::SizeType i = 0; i < indJson.Size(); i++)
	{
		const rapidjson::Value& ind = indJson[i];
		if (!ind.IsArray() || ind.Size() != 3)
		{
			SDL_Log("Invalid indices for %s", _fileName.c_str());
			return false;
		}

		indices.emplace_back(ind[0].GetUint());
		indices.emplace_back(ind[1].GetUint());
		indices.emplace_back(ind[2].GetUint());
	}

	// ここでVertexArrayクラスの作成
	mVertexArray = new VertexArray(vertices.data(), static_cast<unsigned>(vertices.size()) / vertSize,
		layout,indices.data(), static_cast<unsigned>(indices.size()));
	return true;
}

/*
@fn	ロードしたメッシュデータの解放
*/
void Mesh::Unload()
{
	delete mVertexArray;
	mVertexArray = nullptr;
}

/*
@param	_index テクスチャサイズ
@return Textureクラスのポインタ(class Texture)
*/
Texture* Mesh::GetTexture(size_t _index)
{
	if (_index < mTextures.size())
	{
		return mTextures[_index];
	}
	else
	{
		return nullptr;
	}
}

/*
@param	_stage テクスチャステージ
@return テクスチャのID(int型)
*/
int Mesh::GetTextureID(TextureStage _stage)
{
	return mStageDefTexture[_stage];
}

/*
@fn		テクスチャステージを読み込み
@param	_doc rapidJsonオブジェクト
@param	_texStage テクスチャステージ
@param	_stgString メンバ名
@return	テクスチャのID(int型)
*/
int LoadStageTextures(const rapidjson::Document& _doc, TextureStage _texStage, const char* _stgString)
{
	std::string noneTexture("none");
	std::string texName;
	Texture* t;
	if (IsExistMember(_doc, _stgString))
	{
		texName = _doc[_stgString].GetString();
		if (texName != noneTexture)
		{
			t = RENDERER->GetTexture(texName);
			if (t == nullptr)
			{
				t = RENDERER->GetTexture("Assets/Default.png");
			}
			return t->GetTextureID();
		}
	}
	return 0;
}
