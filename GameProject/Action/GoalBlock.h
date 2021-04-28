/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include "GameObject.h"

class GoalBlock : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos �S�[�����̍��W
	@param	_size �S�[�����̃T�C�Y
	@param	_objectTag �S�[�����̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	GoalBlock(const Vector3& _pos, const Vector3& _size, const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~GoalBlock() {};

private:

};