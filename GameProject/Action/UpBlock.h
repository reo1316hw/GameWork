/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include "GameObject.h"

class UpBlock : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos ��ړ��u���b�N�̍��W
	@param	_size ��ړ��u���b�N�̃T�C�Y
	@param	_objectTag ��ړ��u���b�N�̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	UpBlock(const Vector3& _pos, const Vector3& _size, const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~UpBlock() {};

	/*
	@fn		��ړ��u���b�N�̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

private:

	//��ړ��u���b�N�̏�Ɉړ����鑬�x
	const float UP_SPEED = 10.0f;
};