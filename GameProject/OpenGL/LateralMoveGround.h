/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/

class LateralMoveGround : public GameObject
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_pos ���ړ����̍��W
	@param	_size ���ړ����̃T�C�Y
	@param	_objectTag ���ړ����̃^�O
	@param	_sceneTag �V�[���̃^�O
	@param _distance ���ړ����̈ړ����鋗��
	*/
	LateralMoveGround(const Vector3& _pos, const Vector3& _size, const std::string _gpmeshName, const Tag& _objectTag, const SceneBase::Scene _sceneTag, const float _distance);

	/*
	@fn	�f�X�g���N�^
	*/
	~LateralMoveGround() {};

	/*
	@fn		���ړ����̃A�b�v�f�[�g
	@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
	*/
	void UpdateGameObject(float _deltaTime)override;

private:



	static Vector3 mSendVel;



	//���]�t���O
	bool mReversFlag;

	//���ړ�����Ƃ��̑��x
	const float MOVE_SPEED = 10.0f;

public://�Q�b�^�[�Z�b�^�[
	


	Vector3 GetVelocity() { return mSendVel; };



};