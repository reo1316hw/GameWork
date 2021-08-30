/*
@brief	�C���N���[�h
*/
#include <iostream>

#include "pch.h"

/*
@fn		�R���X�g���N�^
@param	_pos �c�ړ����̍��W
@param	_size �c�ړ����̃T�C�Y
@param	_objectTag �c�ړ����̃^�O
@param	_sceneTag �V�[���̃^�O
*/
VerticalMoveGround::VerticalMoveGround(const Vector3& _pos, const Vector3& _size, const std::string _gpmeshName, const Tag& _objectTag, const SceneBase::Scene _sceneTag) :
	GameObject(_sceneTag,_objectTag)
{
	//GameObject�����o�ϐ��̏�����
	mTag = _objectTag;
	SetScale(_size);
	SetPosition(_pos);

	mEndPos = Vector3(_pos.x, _pos.y, _pos.z + 200);

	//��������VerticalMoveGround�̐������Ɠ�����Component���N���X�͎����ŊǗ��N���X�ɒǉ����ꎩ���ŉ�������
	mMeshComponent = new MeshComponent(this);
	//Renderer�N���X����Mesh�ǂݍ��݊֐��𗘗p����Mesh���Z�b�g(.gpmesh)
	mMeshComponent->SetMesh(RENDERER->GetMesh(_gpmeshName));

	// �����蔻��
	mMesh = new Mesh;
	mMesh = RENDERER->GetMesh(_gpmeshName);
	mBoxcollider = new BoxCollider(this, ColliderTag::verticalMoveGroundTag, GetOnCollisionFunc());
	mBoxcollider->SetObjectBox(mMesh->GetBox());

	mOriginalPosFlag = false;
}

/*
@fn		�c�ړ����̃A�b�v�f�[�g
@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
*/
void VerticalMoveGround::UpdateGameObject(float _deltaTime)
{
	if (mPosition.z >= mEndPos.z)
	{
		mVelocity.z = 0;
	}

	if (mOriginalPosFlag)
	{
		if (Player::GetRespawnFlag())
		{
			mPosition.z = mPosition.z - 200;
			mOriginalPosFlag = false;
		}
	}

	// ��ɍ��W�ɑ��x�𑫂�
	mPosition += mVelocity;

	SetPosition(mPosition);
}

/*
@fn		�c�ړ������q�b�g�������̏���
@param	_hitObject �q�b�g�����Ώۂ̃Q�[���I�u�W�F�N�g�̃A�h���X
*/
void VerticalMoveGround::OnCollision(const GameObject& _hitObject)
{
	mOriginalPosFlag = true;
	mVelocity.z = FORWARD_SPEED;
}