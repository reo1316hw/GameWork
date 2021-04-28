/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include "GameObject.h"

class RightBlock : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos �E�ړ��u���b�N�̍��W
	@param	_size �E�ړ��u���b�N�̃T�C�Y
	@param	_objectTag �E�ړ��u���b�N�̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	RightBlock(const Vector3& _pos, const Vector3& _size, const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~RightBlock() {};

	/*
	@fn		�E�ړ��u���b�N�̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

private:

	//���]������W
	Vector3 mInversionPos;

	//�h��邩
	bool mShakeFlag;
	//���]���邩
	bool mReversFlag;

	//����(�i�s�x)
	float mElapseTime;
	//�J�n�ƏI���̒l�̍���
	float mDifferencePos;
	//�J�n�̒l
	float mStart;

	//�S�̂̎���
	const float TOTAL_TIME = 1.0f;
	//�E�ړ��u���b�N�̉E�Ɉړ����鑬�x
	const float RIGHT_SPEED = 20.0f;
};