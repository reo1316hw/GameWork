#include "UI.h"
#include "Texture.h"
#include "Shader.h"
#include "GameObject.h"
#include "Game.h"
#include "Renderer.h"

UI::UI(GameObject* _owner, int _drawOrder)
	:Component(_owner)
	, texture(nullptr)
	, drawOrder(_drawOrder)
	, textureWidth(0)
	, textureHeight(0)
	, visible(true)
{
	//�����_���[�Ƀ|�C���^�[�𑗂�
	RENDERER->AddUI(this);
}

UI::~UI()
{
	//�����_���[����|�C���^���폜����
	RENDERER->RemoveUI(this);
}

/*
@brief	�`�揈��
@param _shader �g�p����V�F�[�_�[�N���X�̃|�C���^
*/
void UI::Draw(Shader* _shader, const Vector2& _offset)
{
	//�摜��񂪋�łȂ����A�e�I�u�W�F�N�g�����X�V��ԂłȂ���
	if (texture && owner->GetState() != State::Dead)
	{
		Matrix4 scaleMatrix = Matrix4::CreateScale(
			static_cast<float>(textureWidth),
			static_cast<float>(textureHeight),
			1.0f);

		// �X�N���[���ʒu�̕��s�ړ�
		Matrix4 transMat = Matrix4::CreateTranslation(
			Vector3(_offset.x - (textureWidth * 5.5f),
				(textureHeight * 5.0f) - _offset.y, 0.0f));

		Matrix4 world = scaleMatrix * transMat;

		_shader->SetMatrixUniform("uWorldTransform", world);

		texture->SetActive();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

	}
}

/*
@fn �e�N�X�`�����Z�b�g���c���̒������v�Z����
@param _texture �g�p����e�N�X�`���̃|�C���^
*/
void UI::SetTexture(Texture* _texture)
{
	texture = _texture;
	textureWidth = texture->GetWidth();
	textureHeight = texture->GetHeight();
}
