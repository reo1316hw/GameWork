/*
@brief	プリプロセッサ
*/
#pragma once

/*
@brief	インクルード
*/

class MapCreate : public GameObject
{
public:

	/*
	@fn	コンストラクタ
	*/
	MapCreate();

	/*
	@fn	デストラクタ
	*/
	~MapCreate();

	/*
	@fn		jsonファイルをRapidJsonで読み込んでマップデータを各配列に格納する
	@return	ファイルを開けたか(bool型)
	*/
	bool OpenFile();

	/*
	@fn	床を生成する
	*/
	void CreateGround();

	/*
	@fn	ガラス床を生成する
	*/
	void CreateGlass();

	/*
	@fn	障害物を生成する
	*/
	void CreateBlock();

	/*
	@fn	縦移動床を生成する
	*/
	void CreateVerticalMoveGround();

	/*
	@fn	ジャンプ中を生成する
	*/
	void CreateJump();

	/*
	@fn	横移動床を生成する
	*/
	void CreateLateralMoveGround();

	/*
	@fn	プレイヤーを生成する
	*/
	void CreatePlayer();

	/*
	@fn	上移動ブロックを生成する
	*/
	void CreateUpBlock();

	/*
	@fn	縦長障害物を生成する
	*/
	void CreateVerticalBlock();

	/*
	@fn	空中ブロックを生成する
	*/
	void CreateAerialBlock();

	/*
	@fn	右移動ブロックを生成する
	*/
	void CreateRightBlock();

	/*
	@fn	左移動ブロックを生成する
	*/
	void CreateLeftBlock();

	/*
	@fn	1マス右移動床を生成する
	*/
	void CreateRightGround();

	/*
	@fn	1マス左移動床を生成する
	*/
	void CreateLeftGround();

	/*
	@fn	落下ブロックを生成する
	*/
	void CreateDownBlock();

	/*
	@fn	ゴール柱を生成する
	*/
	void CreateGoal();

	/*
	@fn	リスポーン地点を生成する
	*/
	void CreateRespawn();

private:

	bool readTiledJson(std::vector<std::vector<int>>& _mapData, const char* _fileName, const char* _layerName);

	int  findLayerIndex(rapidjson::GenericArray<false,rapidjson::Value>& _layer,std::string& _layerName);

	//床マップデータ
	std::vector<std::vector<int>> mGroundMapData;
	//プレイヤーマップデータ
	std::vector<std::vector<int>> mPlayerMapData;
	//横移動床マップデータ
	std::vector<std::vector<int>> mLateralMoveGroundMapData;
	//縦移動床マップデータ
	std::vector<std::vector<int>> mVerticalMoveGroundMapData;
	//ジャンプ床マップデータ
	std::vector<std::vector<int>> mJumpMapData;
	//障害物マップデータ
	std::vector<std::vector<int>> mBlockMapData;
	//ガラス床マップデータ
	std::vector<std::vector<int>> mGlassMapData;
	//上移動ブロックマップデータ
	std::vector<std::vector<int>> mUpBlockMapData;
	//縦長障害物マップデータ
	std::vector<std::vector<int>> mVerticalBlockMapData;
	//空中ブロックマップデータ
	std::vector<std::vector<int>> mAerialBlockMapData;
	//右移動ブロックマップデータ
	std::vector<std::vector<int>> mRightBlockMapData;
	//左移動ブロックマップデータ
	std::vector<std::vector<int>> mLeftBlockMapData;
	//1マス右移動床マップデータ
	std::vector<std::vector<int>> mRightGroundMapData;
	//1マス左移動床マップデータ
	std::vector<std::vector<int>> mLeftGroundMapData;
	//落下ブロックマップデータ
	std::vector<std::vector<int>> mDownBlockMapData;
	//ゴール柱マップデータ
	std::vector<std::vector<int>> mGoalBlockMapData;
	//リスポーン地点マップデータ
	std::vector<std::vector<int>> mRespawnMapData;

	//現在のシーン
	int mScene;
	//幅のマップデータ
	int	mSizeX;
	//高さのマップデータ
	int	mSizeY;
	//奥行のマップデータ
	int	mSizeZ;

	//オブジェクトごとの距離
	float mOffset;
};

