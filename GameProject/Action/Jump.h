/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include "GameObject.h"

class Jump : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos �W�����v���̍��W
	@param	_size �W�����v���̃T�C�Y
	@param	_objectTag �W�����v���̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	Jump(const Vector3& _pos, const Vector3& _size, const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~Jump() {};

	/*
	@fn		�W�����v���̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

	/*
	@fn		�W�����v�����q�b�g�������̏���
	@param	_hitObject �q�b�g�����Ώۂ̃Q�[���I�u�W�F�N�g�̃A�h���X
	*/
	void OnCollision(const GameObject& _hitObject)override;

private:

	//�p�x
	float degree;
};