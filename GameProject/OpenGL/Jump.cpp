/*
@brief	�C���N���[�h
*/
#include "pch.h"

/*
@fn		�R���X�g���N�^
@param	_pos �W�����v���̍��W
@param	_size �W�����v���̃T�C�Y
@param	_objectTag �W�����v���̃^�O
@param	_sceneTag �V�[���̃^�O
*/
Jump::Jump(const Vector3& _pos, const Vector3& _size, const std::string _gpmeshName, const Tag& _objectTag, const SceneBase::Scene _sceneTag) :
	GameObject(_sceneTag, _objectTag)
{
	//GameObject�����o�ϐ��̏�����
	mTag = _objectTag;
	SetScale(_size);
	SetPosition(_pos);

	degree = 0.0f;
	mVelocity = Vector3::Zero;

	//��������Jump�̐������Ɠ�����Component���N���X�͎����ŊǗ��N���X�ɒǉ����ꎩ���ŉ�������
	mMeshComponent = new MeshComponent(this);
	//Renderer�N���X����Mesh�ǂݍ��݊֐��𗘗p����Mesh���Z�b�g(.gpmesh)
	mMeshComponent->SetMesh(RENDERER->GetMesh(_gpmeshName));

	// �����蔻��
	mMesh = new Mesh;
	mMesh = RENDERER->GetMesh(_gpmeshName);
	mBoxcollider = new BoxCollider(this, ColliderTag::jumpTag, GetOnCollisionFunc());
	mBoxcollider->SetObjectBox(mMesh->GetBox());
}

void Jump::UpdateGameObject(float _deltaTime)
{
	if (mHitFlag)
	{
		// sin�J�[�u
		mVelocity.y = sinf(degree) * 8.0f;
		mVelocity.z = sinf(degree) * 8.0f;
		degree += 0.2f;

		if (degree >= 6.5f)
		{
			degree = 0.0f;
			mVelocity.y = 0.0f;
			mVelocity.z = 0.0f;
			mHitFlag = false;
		}
	}

	// ��ɍ��W�ɑ��x�𑫂�
	mPosition += mVelocity;

	SetPosition(mPosition);
}

void Jump::OnCollision(const GameObject& _hitObject)
{
	mHitFlag = true;
}