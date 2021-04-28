/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include "GameObject.h"

class RightOneBlock : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos 1�}�X�E�ړ����̍��W
	@param	_size 1�}�X�E�ړ����̃T�C�Y
	@param	_objectTag 1�}�X�E�ړ����̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	RightOneBlock(const Vector3& _pos, const Vector3& _size, const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~RightOneBlock() {};

	/*
	@fn		1�}�X�E�ړ����̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

private:

	//1�}�X�E�ړ����̉E�Ɉړ����鑬�x
	const float RIGHT_SPEED = 10.0f;
};