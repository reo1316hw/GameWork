/*
@brief	�C���N���[�h
*/
#include "RightOneBlock.h"
#include "MeshComponent.h"
#include "Mesh.h"
#include "Renderer.h"
#include "BoxCollider.h"
#include "Player.h"

/*
@fn		�R���X�g���N�^
@param	_pos 1�}�X�E�ړ����̍��W
@param	_size 1�}�X�E�ړ����̃T�C�Y
@param	_objectTag 1�}�X�E�ړ����̃^�O
@param	_sceneTag �V�[���̃^�O
*/
RightOneBlock::RightOneBlock(const Vector3& _pos, const Vector3& _size, const Tag& _objectTag, const SceneBase::Scene _sceneTag)
	: GameObject(_sceneTag, _objectTag)
{
	//GameObject�����o�ϐ��̏�����
	mTag = _objectTag;
	SetScale(_size);
	SetPosition(_pos);

	mInitPos = Vector3(_pos.x, _pos.y, _pos.z);
	mEndPos = Vector3(_pos.x + 200, _pos.y, _pos.z);

	switch (_sceneTag)
	{
	case SceneBase::Scene::tutorial:

		//��������RightOneBlock�̐������Ɠ�����Component���N���X�͎����ŊǗ��N���X�ɒǉ����ꎩ���ŉ�������
		mMeshComponent = new MeshComponent(this);
		//Renderer�N���X����Mesh�ǂݍ��݊֐��𗘗p����Mesh���Z�b�g(.gpmesh)
		mMeshComponent->SetMesh(RENDERER->GetMesh("Assets/box_06.gpmesh"));

		// �����蔻��
		mMesh = new Mesh;
		mMesh = RENDERER->GetMesh("Assets/box_06.gpmesh");
		mBoxcollider = new BoxCollider(this, ColliderTag::rightOneBlockTag, GetOnCollisionFunc());
		mBoxcollider->SetObjectBox(mMesh->GetBox());

		break;

	case SceneBase::Scene::stage02:

		//��������RightOneBlock�̐������Ɠ�����Component���N���X�͎����ŊǗ��N���X�ɒǉ����ꎩ���ŉ�������
		mMeshComponent = new MeshComponent(this);
		//Renderer�N���X����Mesh�ǂݍ��݊֐��𗘗p����Mesh���Z�b�g(.gpmesh)
		mMeshComponent->SetMesh(RENDERER->GetMesh("Assets/box_18.gpmesh"));

		// �����蔻��
		mMesh = new Mesh;
		mMesh = RENDERER->GetMesh("Assets/box_18.gpmesh");
		mBoxcollider = new BoxCollider(this, ColliderTag::rightOneBlockTag, GetOnCollisionFunc());
		mBoxcollider->SetObjectBox(mMesh->GetBox());

		break;
	}

	mOriginalPosFlag = false;
}

/*
@fn		1�}�X�E�ړ����̃A�b�v�f�[�g
@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
*/
void RightOneBlock::UpdateGameObject(float _deltaTime)
{
	Vector3 playerPos = Player::GetPos();

	if (playerPos.z >= mPosition.z - 600.0f)
	{
		mVelocity.x = RIGHT_SPEED;
	}

	if (mPosition.x >= mEndPos.x)
	{
		mVelocity.x = 0;
	}

	if (mInitPos.x < mPosition.x)
	{
		mOriginalPosFlag = true;
	}

	if (Player::GetDeathFlag())
	{
		mVelocity.x = 0;
		mOriginalPosFlag = false;
	}

	if (mOriginalPosFlag)
	{
		if (Player::GetRespawnFlag())
		{
			mVelocity.x = 0;
			mPosition.x = mInitPos.x;
			mOriginalPosFlag = false;
		}
	}

	// ��ɍ��W�ɑ��x�𑫂�
	mPosition += mVelocity;

	SetPosition(mPosition);
}
