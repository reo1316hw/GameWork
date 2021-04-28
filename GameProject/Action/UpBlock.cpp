/*
@brief	�C���N���[�h
*/
#include "UpBlock.h"
#include "MeshComponent.h"
#include "Mesh.h"
#include "Renderer.h"
#include "BoxCollider.h"
#include "Player.h"

/*
@fn		�R���X�g���N�^
@param	_pos ��ړ��u���b�N�̍��W
@param	_size ��ړ��u���b�N�̃T�C�Y
@param	_objectTag ��ړ��u���b�N�̃^�O
@param	_sceneTag �V�[���̃^�O
*/
UpBlock::UpBlock(const Vector3& _pos, const Vector3& _size, const Tag& _objectTag, const SceneBase::Scene _sceneTag)
	: GameObject(_sceneTag, _objectTag)
{
	//GameObject�����o�ϐ��̏�����
	mTag = _objectTag;
	SetScale(_size);
	SetPosition(_pos);

	mInitPos = Vector3(_pos.x, _pos.y, _pos.z);
	mEndPos = Vector3(_pos.x, _pos.y + 200, _pos.z);

	switch (_sceneTag)
	{
	case SceneBase::Scene::tutorial:

		//��������UpBlock�̐������Ɠ�����Component���N���X�͎����ŊǗ��N���X�ɒǉ����ꎩ���ŉ�������
		mMeshComponent = new MeshComponent(this);
		//Renderer�N���X����Mesh�ǂݍ��݊֐��𗘗p����Mesh���Z�b�g(.gpmesh)
		mMeshComponent->SetMesh(RENDERER->GetMesh("Assets/box_03.gpmesh"));

		// �����蔻��
		mMesh = new Mesh;
		mMesh = RENDERER->GetMesh("Assets/box_03.gpmesh");
		mBoxcollider = new BoxCollider(this, ColliderTag::upBlockTag, GetOnCollisionFunc());
		mBoxcollider->SetObjectBox(mMesh->GetBox());

		break;

	case SceneBase::Scene::stage02:

		//��������UpBlock�̐������Ɠ�����Component���N���X�͎����ŊǗ��N���X�ɒǉ����ꎩ���ŉ�������
		mMeshComponent = new MeshComponent(this);
		//Renderer�N���X����Mesh�ǂݍ��݊֐��𗘗p����Mesh���Z�b�g(.gpmesh)
		mMeshComponent->SetMesh(RENDERER->GetMesh("Assets/box_15.gpmesh"));

		// �����蔻��
		mMesh = new Mesh;
		mMesh = RENDERER->GetMesh("Assets/box_15.gpmesh");
		mBoxcollider = new BoxCollider(this, ColliderTag::upBlockTag, GetOnCollisionFunc());
		mBoxcollider->SetObjectBox(mMesh->GetBox());

		break;
	}

	mOriginalPosFlag = false;
}

/*
@fn		��ړ��u���b�N�̃A�b�v�f�[�g
@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
*/
void UpBlock::UpdateGameObject(float _deltaTime)
{
	Vector3 playerPos = Player::GetPos();

	if (playerPos.z >= mPosition.z - 1000.0f)
	{
		mVelocity.y = UP_SPEED;
	}

	if (mInitPos.y < mPosition.y)
	{
		mOriginalPosFlag = true;
	}

	if (mPosition.y >= mEndPos.y)
	{
		mVelocity.y = 0;
	}

	if (Player::GetDeathFlag())
	{
		mVelocity.y = 0;
		mOriginalPosFlag = false;
	}

	if (mOriginalPosFlag)
	{
		if (Player::GetRespawnFlag())
		{
			mVelocity.y = 0;
			mPosition.y = mInitPos.y;
			mOriginalPosFlag = false;
		}
	}

	// ��ɍ��W�ɑ��x�𑫂�
	mPosition += mVelocity;

	SetPosition(mPosition);
}
