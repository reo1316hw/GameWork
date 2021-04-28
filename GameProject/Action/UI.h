#pragma once

#include "Component.h"

class GameObject;
class Shader;
class Texture;
class Vector2;

/*
@file SpriteComponent.h
@brief �摜�f�[�^�N���X���Ǘ����A�X�N���[����ɕ`�悷��N���X
*/
class UI : public Component
{
public:
	UI(GameObject* _owner, int _drawOrder = 100);
	~UI();

	/*
	@brief	�`�揈��
	@param _shader �g�p����V�F�[�_�[�N���X�̃|�C���^
	*/
	virtual void Draw(Shader* _shader, const Vector2& _offset);
protected:
	//�N���X�̃|�C���^
	Texture* texture;
	//�`�悳��鏇�ԁi���l�����Ȃ��قǑ����X�V�����j
	int drawOrder;
	//�e�N�X�`���̉���
	int textureWidth;
	//�e�N�X�`���̏c��
	int textureHeight;
	//�`����s����
	bool visible;
public://�Q�b�^�[�Z�b�^�[
	/*
	@fn �e�N�X�`�����Z�b�g���c���̒������v�Z����
	@param _texture �g�p����e�N�X�`���̃|�C���^
	*/
	virtual void SetTexture(Texture* _texture);

	/*
	@return �e�N�X�`���̉���
	*/
	int GetTexWidth() const { return textureWidth; }

	/*
	@return �e�N�X�`���̏c��
	*/
	int GetTexHeight() const { return textureHeight; }

	/*
	@return �`�揇
	*/
	int GetDrawOrder() { return drawOrder; }

	/*
	@brief�@�`������邩�ǂ�����ݒ�
	@param	true : �`�悷�� , false : �`�悵�Ȃ�
	*/
	void SetVisible(bool _visible) { visible = _visible; }

	/*
	@brief�@�`������邩�ǂ������擾����
	@return	true : �`�悷�� , false : �`�悵�Ȃ�
	*/
	bool GetVisible() const { return visible; }
};
