/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include "GameObject.h"

class LeftOneBlock : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos 1�}�X���ړ����̍��W
	@param	_size 1�}�X���ړ����̃T�C�Y
	@param	_objectTag 1�}�X���ړ����̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	LeftOneBlock(const Vector3& _pos, const Vector3& _size, const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~LeftOneBlock() {};

	/*
	@fn		1�}�X���ړ����̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

private:

	//1�}�X���ړ����̍��Ɉړ����鑬�x
	const float LEFT_SPEED = 10.0f;
};