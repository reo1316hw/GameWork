/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/

class VerticalBlock : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos �c����Q���̍��W
	@param	_size �c����Q���̃T�C�Y
	@param	_objectTag �c����Q���̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	VerticalBlock(const Vector3& _pos, const Vector3& _size, const std::string _gpmeshName, const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~VerticalBlock() {};

private:

};