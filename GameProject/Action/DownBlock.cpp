/*
@brief	�C���N���[�h
*/
#include "DownBlock.h"
#include "MeshComponent.h"
#include "Mesh.h"
#include "Renderer.h"
#include "BoxCollider.h"
#include "Player.h"

/*
@fn		�R���X�g���N�^
@param	_pos �����u���b�N�̍��W
@param	_size �����u���b�N�̃T�C�Y
@param	_objectTag �����u���b�N�̃^�O
@param	_sceneTag �V�[���̃^�O
*/
DownBlock::DownBlock(const Vector3& _pos, const Vector3& _size, const Tag& _objectTag, const SceneBase::Scene _sceneTag)
	: GameObject(_sceneTag, _objectTag)
{
	//GameObject�����o�ϐ��̏�����
	mTag = _objectTag;
	SetScale(_size);
	SetPosition(_pos);

	mEndPos = Vector3(_pos.x, _pos.y - 1600, _pos.z);

	//��������DownBlock�̐������Ɠ�����Component���N���X�͎����ŊǗ��N���X�ɒǉ����ꎩ���ŉ�������
	mMeshComponent = new MeshComponent(this);
	//Renderer�N���X����Mesh�ǂݍ��݊֐��𗘗p����Mesh���Z�b�g(.gpmesh)
	mMeshComponent->SetMesh(RENDERER->GetMesh("Assets/box_13.gpmesh"));

	// �����蔻��
	mMesh = new Mesh;
	mMesh = RENDERER->GetMesh("Assets/box_13.gpmesh");
	mBoxcollider = new BoxCollider(this, ColliderTag::downBlockTag, GetOnCollisionFunc());
	mBoxcollider->SetObjectBox(mMesh->GetBox());
}

/*
@fn		�����u���b�N�̃A�b�v�f�[�g
@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
*/
void DownBlock::UpdateGameObject(float _deltaTime)
{
	Vector3 playerPos = Player::GetPos();

	if (playerPos.z >= mPosition.z - 3000.0f)
	{
		mVelocity.y = -DOWN_SPEED;
	}

	if (mPosition.y <= mEndPos.y)
	{
		mVelocity.y = 0;
	}

	if (Player::GetRespawnFlag())
	{
		mPosition.y = 1600;
	}

	// ��ɍ��W�ɑ��x�𑫂�
	mPosition += mVelocity;

	SetPosition(mPosition);
}