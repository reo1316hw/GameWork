#include "pch.h"

VerticalMoveGroundExplanationBoard::VerticalMoveGroundExplanationBoard(const Vector3& _pos, const Vector3& _velocity, const Tag& _objectTag, const SceneBase::Scene _sceneTag)
	: ParticleEffectBase(_pos, _velocity, 0, "Assets/tutorial01.png", _sceneTag, _objectTag)
{
	mScale = 400.0f;
	mAlpha = 1.0f;
	mParticle->SetScale(mScale);
	mParticle->SetAlpha(mAlpha);
	mParticle->SetColor(Vector3(1.0f, 1.0f, 1.0f));
}

void VerticalMoveGroundExplanationBoard::UpdateGameObject(float _deltaTime)
{	
	/*ParticleEffectBase::LifeCountDown();

	if (lifeCount >= 0)
	{
		position += velocity * 10.0f;

		mScale += 5.0f;
		mAlpha -= 0.05f;
		particle->SetScale(mScale);
		particle->SetAlpha(mAlpha);
		SetPosition(position);
	}

	if (lifeCount <= 0)
	{
		state = State::Dead;
	}*/
}
