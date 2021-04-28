/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include "GameObject.h"

class VerticalMoveGround : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos �c�ړ����̍��W
	@param	_size �c�ړ����̃T�C�Y
	@param	_objectTag �c�ړ����̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	VerticalMoveGround(const Vector3& _pos, const Vector3& _size, const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~VerticalMoveGround() {};

	/*
	@fn		�c�ړ����̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

private:

	//�c�ړ����̑O�Ɉړ����鑬�x
	const float FORWARD_SPEED = 10.0f;

	/*
	@fn		�c�ړ������q�b�g�������̏���
	@param	_hitObject �q�b�g�����Ώۂ̃Q�[���I�u�W�F�N�g�̃A�h���X
	*/
	void OnCollision(const GameObject& _hitObject)override;
};
