/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/

class AerialBlock : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos �󒆃u���b�N�̍��W
	@param	_size �󒆃u���b�N�̃T�C�Y
	@param	_objectTag �󒆃u���b�N�̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	AerialBlock(const Vector3& _pos, const Vector3& _size, const std::string _gpmeshName, const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~AerialBlock() {};

private:
};