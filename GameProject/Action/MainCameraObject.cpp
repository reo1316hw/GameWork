#include "MainCameraObject.h"
#include "Renderer.h"
#include "ColliderComponent.h"

/*
@fn	�R���X�g���N�^
*/
MainCameraObject::MainCameraObject() 
	: GameObject(SceneBase::other,Tag::Camera,true)
{
	SetPosition(Vector3(0,0,-110000));
	mTag = Tag::Camera;
}

/*
@fn	�f�X�g���N�^
*/
MainCameraObject::~MainCameraObject()
{
}

/*
@fn		���̃N���X�̓|�[�Y���ɕʃN���X����X�V�֐����Ă΂�邱�Ƃ�����
@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
*/
void MainCameraObject::UpdateGameObject(float _deltaTime)
{
	Vector3 pos = mOffsetPos + mPosition;
	pos.x = mLerpObject.x + mOffsetPos.x;
	pos.y = mLerpObject.y + mOffsetPos.y;
	pos.z = mLerpObject.z + mOffsetPos.z;
	mPosition = pos;/*Vector3::Lerp(position, pos, _deltaTime * 6.0f);*/

	SetPosition(mPosition);
	Matrix4 view = Matrix4::CreateLookAt(mPosition, mLerpObject, Vector3::UnitY);
	RENDERER->SetViewMatrix(view);
}

/*
@param _offset�@���������W�Ƃ̍�
@param _parentPos�@������W
*/
void MainCameraObject::SetViewMatrixLerpObject(const Vector3 & _offset, const Vector3 & _parentPos)
{
	mHasParentObject = true;
	mOffsetPos = _offset;
	mLerpObject = _parentPos;
}
