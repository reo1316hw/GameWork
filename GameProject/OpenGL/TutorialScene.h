/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/

class VerticalMoveGroundExplanationBoard;
class OperationExplanationBoard;

class TutorialScene : public SceneBase
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_nowScene ���݂̃V�[��
	*/
	TutorialScene(const Scene& _nowScene);

	/*
	@fn	�f�X�g���N�^
	*/
	~TutorialScene();

	/*
	@fn	���݂̃V�[�����ɖ��t���[���X�V����������
	*/
	SceneBase* update() override;

	static bool GetContinueTutorialFlag() { return mSendContinueTutorialFlag; };
	static void SetContinueTutorialFlag(bool _continue) { mSendContinueTutorialFlag = _continue; };

private:

	//�`���[�g���A���V�[�����̏c�ړ����̐����p�l��
	VerticalMoveGroundExplanationBoard* mVerticalMoveGroundExplanationBoard;
	//�`���[�g���A���V�[�����̑�������p�l��
	OperationExplanationBoard* mOperationExplanationBoard;

	static bool mSendContinueTutorialFlag;

	//�R���e�B�j���[�V�[���Ɉڍs���邩�̃t���O
	bool mContinueTutorialFlag;
};

