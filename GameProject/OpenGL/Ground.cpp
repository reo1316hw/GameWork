/*
@brief	�C���N���[�h
*/
#include "pch.h"

/*
@fn		�R���X�g���N�^
@param	_pos ���̍��W
@param	_size ���̃T�C�Y
@param	_objectTag ���̃^�O
@param	_sceneTag �V�[���̃^�O
*/
Ground::Ground(const Vector3& _pos, const Vector3& _size, const std::string _gpmeshName, const Tag& _objectTag, const SceneBase::Scene _sceneTag)
	: GameObject(_sceneTag, _objectTag)
{
	//GameObject�����o�ϐ��̏�����
	mTag = _objectTag;
	SetScale(_size);
	SetPosition(_pos);

	//��������Ground�̐������Ɠ�����Component���N���X�͎����ŊǗ��N���X�ɒǉ����ꎩ���ŉ�������
	mMeshComponent = new MeshComponent(this);
	//Renderer�N���X����Mesh�ǂݍ��݊֐��𗘗p����Mesh���Z�b�g(.gpmesh)
	mMeshComponent->SetMesh(RENDERER->GetMesh(_gpmeshName));

	// �����蔻��
	mMesh = new Mesh;
	mMesh = RENDERER->GetMesh(_gpmeshName);
	mBoxcollider = new BoxCollider(this, ColliderTag::groundTag, GetOnCollisionFunc());
	mBoxcollider->SetObjectBox(mMesh->GetBox());
}
