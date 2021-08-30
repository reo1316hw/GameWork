/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/

class CheckpointBoard : public ParticleEffectBase
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos �`�F�b�N�|�C���g�{�[�h�̍��W
	@param	_vel �`�F�b�N�|�C���g�{�[�h������@�p�l���̑��x
	@param	_objectTag �A�^�b�`�����Q�[���I�u�W�F�N�g�̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	CheckpointBoard(const Vector3& _pos, const Vector3& _vel, const std::string& _particleFileName ,const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~CheckpointBoard() {};

	/*
	@fn		������@�p�l���̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

private:
	AABB mCehckpointBoardAABB;
};