/*
@brief	�C���N���[�h
*/
#include "pch.h"

/*
@fn		�R���X�g���N�^
@param	_pos ���ړ����̍��W
@param	_size ���ړ����̃T�C�Y
@param	_objectTag ���ړ����̃^�O
@param	_sceneTag �V�[���̃^�O
*/
LeftBlock::LeftBlock(const Vector3& _pos, const Vector3& _size, const float _addPosX, const std::string _gpmeshName, const Tag& _objectTag, const ColliderTag& _colliderTag, const SceneBase::Scene _sceneTag)
	: GameObject(_sceneTag, _objectTag)
	, mElapseTime(0.0f)
	, mDifferencePos(0.0f)
	, mStart(0.0f)
	, mInversionPos(Vector3::Zero)
	, mShakeFlag(false)
	, mReversFlag(false)
{
	//GameObject�����o�ϐ��̏�����
	mTag = _objectTag;
	SetScale(_size);
	SetPosition(_pos);
	
	mInitPos = Vector3(_pos.x, _pos.y, _pos.z);
	mEndPos = Vector3(_pos.x - _addPosX, _pos.y, _pos.z);
	mInversionPos = Vector3(_pos.x + 60, _pos.y, _pos.z);

	//��������LeftBlock�̐������Ɠ�����Component���N���X�͎����ŊǗ��N���X�ɒǉ����ꎩ���ŉ�������
	mMeshComponent = new MeshComponent(this);
	//Renderer�N���X����Mesh�ǂݍ��݊֐��𗘗p����Mesh���Z�b�g(.gpmesh)
	mMeshComponent->SetMesh(RENDERER->GetMesh(_gpmeshName));

	// �����蔻��
	mMesh = new Mesh;
	mMesh = RENDERER->GetMesh(_gpmeshName);
	mBoxcollider = new BoxCollider(this, _colliderTag, GetOnCollisionFunc());
	mBoxcollider->SetObjectBox(mMesh->GetBox());

	mOriginalPosFlag = false;
}

/*
@fn		���ړ����̃A�b�v�f�[�g
@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
*/
void LeftBlock::UpdateGameObject(float _deltaTime)
{
	Vector3 playerPos = Player::GetPos();

	//////////////////////////////////////
	//�\�m���쏈��
	if (playerPos.z >= mPosition.z - 2040.0f)
	{
		mShakeFlag = true;
	}

	if (mShakeFlag)
	{
		if (mPosition.x >= mInversionPos.x)
		{
			mReversFlag = true;
		}
		else if (mPosition.x <= mInitPos.x)
		{
			mReversFlag = false;
		}

		if (mReversFlag == true)
		{
			mVelocity.x = -LEFT_SPEED;
		}
		else if (mReversFlag == false)
		{
			mVelocity.x = LEFT_SPEED;
		}
		
	}
	/////////////////////////////////////////

	if (playerPos.z >= mPosition.z - 1800.0f)
	{
		mShakeFlag = false;
		mElapseTime += _deltaTime;
		mDifferencePos = mEndPos.x - mInitPos.x;
		mVelocity.x = -Quartic::EaseIn(mElapseTime, mStart, -mDifferencePos, TOTAL_TIME) * 0.02f;
	}


	if (mInitPos.x > mPosition.x)
	{
		mOriginalPosFlag = true;
	}

	if (mPosition.x <= mEndPos.x)
	{
		mVelocity.x = 0;
	}

	if (Player::GetDeathFlag())
	{
		mElapseTime = 0.0f;
		mVelocity.x = 0;
		mOriginalPosFlag = false;
	}

	if (mOriginalPosFlag)
	{
		if (Player::GetRespawnFlag())
		{
			mElapseTime = 0.0f;
			mVelocity.x = 0;
			mPosition.x = mInitPos.x;
			mOriginalPosFlag = false;
		}
	}
	
	// ��ɍ��W�ɑ��x�𑫂�
	mPosition += mVelocity;

	SetPosition(mPosition);
}