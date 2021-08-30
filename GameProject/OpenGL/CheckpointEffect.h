/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/

class CheckpointEffect : public ParticleEffectBase
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos �N���A�G�t�F�N�g�̐����ꏊ
	@param	_vel �N���A�G�t�F�N�g�̑��x
	@param	_objectTag �A�^�b�`�����Q�[���I�u�W�F�N�g�̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	CheckpointEffect(Vector3 _pos, Vector3 _vel, const Tag& _objectTag, SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~CheckpointEffect() {};

	/*
	@fn	�N���A�G�t�F�N�g�̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

private:

	//���x�̏����l
	const float VELOCITY_INITIAL_VALUE = 30.0f;
	//���x�̌����l
	const float VELOCITY_MINUS_VALUE = 1.5f;
	//�����x�̏����l
	const float ACCELERATION_INITIAL_VALUE = 1.0f;
	//�����x�̏����l
	const float ALPHA_INITIAL_VALUE = 1.0f;
	//�X�P�[���̏����l
	const float SCALE_INITIAL_VALUE = 0.0f;
	//�X�P�[���̉����l
	const float SCALE_PLUS_VALUE = 4.0f;
	//�X�P�[���̍ő�l
	const float SCALE_MAX_VALUE = 64.0f;
};