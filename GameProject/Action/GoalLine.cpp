/*
@brief	�C���N���[�h
*/
#include "GoalLine.h"

/*
@fn		�R���X�g���N�^
@param	_pos �S�[�����C���̐����ꏊ
@param	_vel �S�[�����C���̑��x
@param	_objectTag �A�^�b�`�����Q�[���I�u�W�F�N�g�̃^�O
@param	_sceneTag �V�[���̃^�O
*/
GoalLine::GoalLine(const Vector3& _pos, const Vector3& _vel, const Tag& _objectTag, const SceneBase::Scene _sceneTag)
	: ParticleEffectBase(_pos, _vel, 0, "Assets/Goal.png", _sceneTag, _objectTag)
{
	mScale = 1000.0f;
	mAlpha = 0.5f;
	mParticle->SetScale(mScale);
	mParticle->SetAlpha(mAlpha);
	mParticle->SetColor(Vector3(1.0f, 1.0f, 1.0f));
}

/*
@fn		�S�[�����C���̃A�b�v�f�[�g
@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
*/
void GoalLine::UpdateGameObject(float _deltaTime)
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
