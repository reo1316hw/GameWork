/*
@brief	�C���N���[�h
*/
#include "pch.h"



Vector3 LateralMoveGround::mSendVel = Vector3::Zero;




/*
@fn		�R���X�g���N�^
@param	_pos ���ړ����̍��W
@param	_size ���ړ����̃T�C�Y
@param	_objectTag ���ړ����̃^�O
@param	_sceneTag �V�[���̃^�O
@param _distance ���ړ����̈ړ����鋗��
*/
LateralMoveGround::LateralMoveGround(const Vector3& _pos, const Vector3& _size, const std::string _gpmeshName, const Tag& _objectTag, const SceneBase::Scene _sceneTag, const float _distance)
	: GameObject(_sceneTag, _objectTag)
{
	//GameObject�����o�ϐ��̏�����
	mTag = _objectTag;
	SetScale(_size);
	SetPosition(_pos);

	// �ړ���̍��W
	mEndPos = Vector3(_pos.x - _distance, _pos.y, _pos.z) ;
	// �����̍��W
	mInitPos = _pos;

	//��������LateralMoveGround�̐������Ɠ�����Component���N���X�͎����ŊǗ��N���X�ɒǉ����ꎩ���ŉ�������
	mMeshComponent = new MeshComponent(this);
	//Renderer�N���X����Mesh�ǂݍ��݊֐��𗘗p����Mesh���Z�b�g(.gpmesh)
	mMeshComponent->SetMesh(RENDERER->GetMesh(_gpmeshName));

	// �����蔻��
	mMesh = new Mesh;
	mMesh = RENDERER->GetMesh(_gpmeshName);
	mBoxcollider = new BoxCollider(this, ColliderTag::lateralMoveGroundTag, GetOnCollisionFunc());
	mBoxcollider->SetObjectBox(mMesh->GetBox());

	// ���]�t���O
	mReversFlag = false;
	mOriginalPosFlag = false;
}

/*
@fn		���ړ����̃A�b�v�f�[�g
@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
*/
void LateralMoveGround::UpdateGameObject(float _deltaTime)
{
	if (mInitPos.x != mPosition.x)
	{
		mOriginalPosFlag = true;
	}

	if (Player::GetDeathFlag())
	{
		mVelocity.x = 0.0f;
		mOriginalPosFlag = false;
	}

	if (mOriginalPosFlag)
	{
		if (Player::GetRespawnFlag())
		{
			mVelocity.x = 0.0f;
			mPosition.x = mInitPos.x;
			mOriginalPosFlag = false;
		}
	}

	if (mPosition.x <= mEndPos.x)
	{
		mReversFlag = true;
	}
	else if (mPosition.x >= mInitPos.x)
	{
		mReversFlag = false;
	}

	if (mReversFlag == true )
	{
		mVelocity.x = MOVE_SPEED;
		
	}
	else if(mReversFlag == false)
	{
		mVelocity.x = -MOVE_SPEED;
	}

	mSendVel = mVelocity;
	mPosition += mVelocity;

	SetPosition(mPosition);
}