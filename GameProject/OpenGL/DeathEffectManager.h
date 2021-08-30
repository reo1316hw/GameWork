/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/

#include "ParticleEffectBase.h"

class DeathEffect;
class Player;

class DeathEffectManager : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_owner �Q�[���I�u�W�F�N�g�N���X�̃|�C���^
	@param	_objectTag �A�^�b�`�����Q�[���I�u�W�F�N�g�̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	DeathEffectManager(GameObject* _owner, const Tag& _objectTag, SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~DeathEffectManager() {};

	/*
	@fn		�G�t�F�N�g�}�l�[�W���[�̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

private:

	//�Q�[���I�u�W�F�N�g�N���X�̃|�C���^
	GameObject* mOwner;
	//�p�[�e�B�N���̏��
	ParticleState	 mState;
	//�V�[���̃^�O
	SceneBase::Scene mSceneTag;
	//�A�^�b�`�����Q�[���I�u�W�F�N�g�̃^�O
	Tag				 mTag;
	//�f�X�G�t�F�N�g
	DeathEffect* mDeathEffect;
	//�v���C���[�̃|�C���^
	Player* mPlayer;

	//�C�ӂ̃^�C�~���O�Ńf�X�G�t�F�N�g�𐶐����邽�߂̃J�E���g
	int				 mCreateDeathEffectCount;

	//�p�x
	float			 mAngle;

	//�f�X�G�t�F�N�g����x�����������邽�߂̃t���O
	bool			 OneCreateDeathFlag;
};

