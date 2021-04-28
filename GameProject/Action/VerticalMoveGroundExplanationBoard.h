/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include "ParticleEffectBase.h"

class VerticalMoveGroundExplanationBoard : public ParticleEffectBase
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos �c�ړ����̐����p�l���̍��W
	@param	_vel �c�ړ����̐����p�l���̑��x
	@param	_objectTag �A�^�b�`�����Q�[���I�u�W�F�N�g�̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	VerticalMoveGroundExplanationBoard(const Vector3& _pos, const Vector3& _vel, const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~VerticalMoveGroundExplanationBoard() {};

	/*
	@fn		�c�ړ����̐����p�l���̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

private:

};

