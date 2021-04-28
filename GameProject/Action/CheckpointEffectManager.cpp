/*
@brief	�C���N���[�h
*/
#include "CheckpointEffectManager.h"
#include "CheckpointEffect.h"
#include "Player.h"

/*
@fn		�R���X�g���N�^
@param	_owner �Q�[���I�u�W�F�N�g�N���X�̃|�C���^
@param	_objectTag �A�^�b�`�����Q�[���I�u�W�F�N�g�̃^�O
@param	_sceneTag �V�[���̃^�O
*/
CheckpointEffectManager::CheckpointEffectManager(GameObject* _owner, const Tag& _objectTag, SceneBase::Scene _sceneTag)
	:GameObject(_sceneTag, _objectTag)
{
	mOwner = _owner;
	mState = ParticleState::PARTICLE_DISABLE;
	mSceneTag = _sceneTag;
	mTag = _objectTag;
}

/*
@fn		�G�t�F�N�g�}�l�[�W���[�̃A�b�v�f�[�g
@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
*/
void CheckpointEffectManager::UpdateGameObject(float _deltaTime)
{
	//�`�F�b�N�|�C���g��ʉ߂�����`�F�b�N�|�C���g�G�t�F�N�g���A�N�e�B�u�ɂ���
	if (mPlayer->GetCheckpointFlag())
	{
		mState = ParticleState::PARTICLE_ACTIVE;
	}
	else
	{
		mState = ParticleState::PARTICLE_DISABLE;
	}

	//�`�F�b�N�|�C���g�̃X�e�[�g�𒲂ׂă`�F�b�N�|�C���g�G�t�F�N�g�̏������s��
	switch (mState)
	{
	//�A�N�e�B�u����Ȃ��Ȃ�
	case PARTICLE_DISABLE:
		break;
	//�A�N�e�B�u�Ȃ�
	case PARTICLE_ACTIVE:
		
		//�e�̃|�W�V�������擾
		mPosition = mOwner->GetPosition();

		//8�����Ƀ`�F�b�N�|�C���g�G�t�F�N�g���΂�
		for (int i = 0; i < 8; i++)
		{
			//���x��������
			Vector3 vel = Vector3::Zero;

			//�e�����̑��x�ƌ������v�Z
			switch (i % 8)
			{
			case 0:
				vel.x = DIRECTION * SPEED;
				break;
			case 1:
				vel.z = DIRECTION * SPEED;
				break;
			case 2:
				vel.x = -DIRECTION * SPEED;
				break;
			case 3:
				vel.z = -DIRECTION * SPEED;
				break;
			case 4:
				vel.x = DIRECTION * SPEED;
				vel.z = DIRECTION * SPEED;
				break;
			case 5:
				vel.x = -DIRECTION * SPEED;
				vel.z = -DIRECTION * SPEED;
				break;
			case 6:
				vel.x = DIRECTION * SPEED;
				vel.z = -DIRECTION * SPEED;
				break;
			case 7:
				vel.x = -DIRECTION * SPEED;
				vel.z = DIRECTION * SPEED;
				break;
			}

			//�`�F�b�N�|�C���g�G�t�F�N�g�𐶐�
			mCheckpointEffect = new CheckpointEffect(mPosition, vel, mTag, mSceneTag);
		}

		break;
	}
}
