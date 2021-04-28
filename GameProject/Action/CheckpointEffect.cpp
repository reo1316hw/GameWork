/*
@brief	�C���N���[�h
*/
#include "CheckpointEffect.h"
#include "Renderer.h"
#include "ParticleComponent.h"
#include "SceneBase.h"
#include "GameObject.h"

/*
@fn		�R���X�g���N�^
@param	_pos �N���A�G�t�F�N�g�̐����ꏊ
@param	_vel �N���A�G�t�F�N�g�̑��x
@param	_objectTag �A�^�b�`�����Q�[���I�u�W�F�N�g�̃^�O
@param	_sceneTag �V�[���̃^�O
*/
CheckpointEffect::CheckpointEffect(Vector3 _pos, Vector3 _vel, const Tag& _objectTag, SceneBase::Scene _sceneTag)
	:ParticleEffectBase(_pos, _vel, 60, "Assets/star.png", _sceneTag, _objectTag)
{
	mAlpha = ALPHA_INITIAL_VALUE;
	mScale = SCALE_INITIAL_VALUE;
	mVelocity.y = VELOCITY_INITIAL_VALUE;
	mSpeed = ACCELERATION_INITIAL_VALUE;
	mParticle->SetAlpha(mAlpha);
	mParticle->SetScale(mScale);
	mParticle->SetColor(Color::Yellow);
	mParticle->SetBlendMode(ParticleComponent::PARTICLE_BLEND_ENUM_ALPHA);
}

/*
@fn		�N���A�G�t�F�N�g�̃A�b�v�f�[�g
@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
*/
void CheckpointEffect::UpdateGameObject(float _deltaTime)
{
	//�������Ԃ��J�E���g
	ParticleEffectBase::LifeCountDown();

	//���C�t�J�E���g��0���傫�������瑬�x�A�����x�A�X�P�[���̒l���X�V
	if (mLifeCount > 0)
	{
		mVelocity = mVelocity * mSpeed;
		mPosition = mPosition + mVelocity;

		mVelocity.y -= VELOCITY_MINUS_VALUE;
		
		if (mScale <= SCALE_MAX_VALUE)
		{
			mScale += SCALE_PLUS_VALUE;
		}

		mParticle->SetScale(mScale);
		SetPosition(mPosition);
	}

	//���C�t�J�E���g��0�ȉ��������猩���Ȃ�����
	if (mLifeCount <= 0)
	{
		mParticle->SetVisible(false);
	}
}
