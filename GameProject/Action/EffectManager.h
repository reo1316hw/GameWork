/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include "ParticleEffectBase.h"

class SandEffect;
class DeathEffect;
class ClearEffect;
class CheckpointEffect;
class Player;

class EffectManager : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_owner �Q�[���I�u�W�F�N�g�N���X�̃|�C���^
	@param	_objectTag �A�^�b�`�����Q�[���I�u�W�F�N�g�̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	EffectManager(GameObject* _owner, const Tag& _objectTag, SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~EffectManager() {};

	/*
	@fn		�G�t�F�N�g�}�l�[�W���[�̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;
	
private:

	//�Q�[���I�u�W�F�N�g�N���X�̃|�C���^
	GameObject*		 mOwner;
	//�p�[�e�B�N���̏��
	ParticleState	 mState;
	//�G�t�F�N�g�}�l�[�W���[�̍��W
	Vector3			 mPos;
	//�V�[���̃^�O
	SceneBase::Scene mSceneTag;
	//�A�^�b�`�����Q�[���I�u�W�F�N�g�̃^�O
	Tag				 mTag;
	//���ڂ���G�t�F�N�g
	SandEffect*		 mSandEffect;
	//�f�X�G�t�F�N�g
	DeathEffect*	 mDeathEffect;
	//�N���A�G�t�F�N�g
	ClearEffect*	 mClearEffect;
	//�v���C���[�̃|�C���^
	Player*			 mPlayer;

	//�C�ӂ̃^�C�~���O�ō��ڂ���G�t�F�N�g�𐶐����邽�߂̃J�E���g
	int				 mCreateSandEffectCount;
	//�C�ӂ̃^�C�~���O�Ńf�X�G�t�F�N�g�𐶐����邽�߂̃J�E���g
	int				 mCreateDeathEffectCount;

	//�p�x
	float			 mAngle;

	//�N���A�G�t�F�N�g�𐶐����邩�̃t���O
	bool			 mClearEffectFlag;
	//�f�X�G�t�F�N�g�𐶐����邩�̃t���O
	bool			 mDeathEffectFlag;
};
