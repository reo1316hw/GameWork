/*
@brief	�C���N���[�h
*/
#include "pch.h"

/*
@fn		�R���X�g���N�^
@param	_pos �f�X�G�t�F�N�g�̐����ꏊ
@param	_vel �N���A�G�t�F�N�g�̑��x
@param	_objectTag �A�^�b�`�����Q�[���I�u�W�F�N�g�̃^�O
@param	_sceneTag �V�[���̃^�O
*/
DeathEffect::DeathEffect(Vector3 _pos, Vector3 _vel, const Tag& _objectTag, SceneBase::Scene _sceneTag)
	:ParticleEffectBase(_pos, _vel, 40, "Assets/miniGlass.png", _sceneTag, _objectTag)
{
	mAlpha = 1.0f;
	mScale = 16.0f;
	mParticle->SetAlpha(mAlpha);
	mParticle->SetScale(mScale);
	//particle->SetColor(Vector3(0.0f,0.72f,0.79f));
	mParticle->SetColor(Color::White);
	mParticle->SetBlendMode(ParticleComponent::PARTICLE_BLEND_ENUM_ALPHA);
	mVelocity = _vel;
	mSpeed = 1.15f;
}

/*
@fn		�f�X�G�t�F�N�g�̃A�b�v�f�[�g
@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
*/
void DeathEffect::UpdateGameObject(float _deltaTime)
{
	ParticleEffectBase::LifeCountDown();

	if (mLifeCount > 0)
	{
		mAlpha -= 0.01f;
		mScale += 1.0f;
		mParticle->SetAlpha(mAlpha);
		mParticle->SetScale(mScale);
		/*if (lifeCount <= 15)
		{
			velocity = velocity * speed;
			velocity.y *= -1.0f;
		}
		else
		{
			velocity = velocity * speed;
		}*/

		mVelocity = mVelocity * mSpeed;
		mPosition = mPosition + mVelocity;
		SetPosition(mPosition);
	}

	if (mLifeCount <= 0)
	{
		mParticle->SetVisible(false);
	}
}
