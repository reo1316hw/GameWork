/*
@brief	�C���N���[�h
*/
#include "OperationExplanationBoard.h"

/*
@fn		�R���X�g���N�^
@param	_pos ������@�p�l���̍��W
@param	_vel ������@�p�l���̑��x
@param	_objectTag �A�^�b�`�����Q�[���I�u�W�F�N�g�̃^�O
@param	_sceneTag �V�[���̃^�O
*/
OperationExplanationBoard::OperationExplanationBoard(const Vector3& _pos, const Vector3& _vel, const Tag& _objectTag, const SceneBase::Scene _sceneTag)
	:ParticleEffectBase(_pos, _vel, 0, "Assets/operation.png", _sceneTag, _objectTag)
{
	mScale = 400.0f;
	mAlpha = 1.0f;
	mParticle->SetScale(mScale);
	mParticle->SetAlpha(mAlpha);
	mParticle->SetColor(Vector3(1.0f, 1.0f, 1.0f));
}

/*
@fn		������@�p�l���̃A�b�v�f�[�g
@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
*/
void OperationExplanationBoard::UpdateGameObject(float _deltaTime)
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
