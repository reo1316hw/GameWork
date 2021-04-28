/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include "GameObject.h"

class Ground : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos ���̍��W
	@param	_size ���̃T�C�Y
	@param	_objectTag ���̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	Ground(const Vector3& _pos, const Vector3& _size,const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~Ground() {};

private:

};