/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/

class DownBlock : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos �����u���b�N�̍��W
	@param	_size �����u���b�N�̃T�C�Y
	@param	_objectTag �����u���b�N�̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	DownBlock(const Vector3& _pos, const Vector3& _size, const std::string _gpmeshName, const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~DownBlock() {};

	/*
	@fn		�����u���b�N�̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

private:

	//�����u���b�N�̗����鑬�x
	const float DOWN_SPEED = 25.0f;
};