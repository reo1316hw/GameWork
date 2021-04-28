/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include "ParticleEffectBase.h"

class ClearEffect : public ParticleEffectBase
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos �N���A�G�t�F�N�g�̐����ꏊ
	@param	_vel �N���A�G�t�F�N�g�̑��x
	@param	_objectTag �A�^�b�`�����Q�[���I�u�W�F�N�g�̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	ClearEffect(Vector3 _pos, Vector3 _vel, const Tag& _objectTag ,SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~ClearEffect() {};

	/*
	@fn	�N���A�G�t�F�N�g�̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

private:

};

