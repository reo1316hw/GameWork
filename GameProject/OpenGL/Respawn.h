/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/

class Respawn : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos ���X�|�[���n�_�̍��W
	@param	_size ���X�|�[���n�_�̃T�C�Y
	@param	_objectTag ���X�|�[���n�_�̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	Respawn(const Vector3& _pos, const Vector3& _size, const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~Respawn() {};

private:
};