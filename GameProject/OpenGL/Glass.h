/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/

class InvisibleMeshComponent;

class Glass : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos �K���X���̍��W
	@param	_size �K���X���̃T�C�Y
	@param	_objectTag �K���X���̃^�O
	@param	_sceneTag �V�[���̃^�O
	*/
	Glass(const Vector3& _pos, const Vector3& _size, const std::string _gpmeshName, const Tag& _objectTag, const SceneBase::Scene _sceneTag);

	/*
	@fn	�f�X�g���N�^
	*/
	~Glass() {};

	/*
	@fn		�K���X���̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

private:

	//�K���X���̃A���t�@�u�����h���b�V��
	InvisibleMeshComponent* mInvisibleMeshComponent;

	//������܂ł̃J�E���g
	int mDownCount;

	// ������X�s�[�h
	const float DOWN_SPEED = 100.0f;

	/*
	@fn		�K���X�����q�b�g�������̏���
	@param	_hitObject �q�b�g�����Ώۂ̃Q�[���I�u�W�F�N�g�̃A�h���X
	*/
	void OnCollision(const GameObject& _hitObject)override;
};