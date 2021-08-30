/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/

class TutorialScene;
class Stage01Scene;
class Stage02Scene;

class ContinueScene : public SceneBase
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_nowScene ���݂̃V�[��
	*/
	ContinueScene(const Scene& _nowScene);

	/*
	@fn	�f�X�g���N�^
	*/
	~ContinueScene();

	/*
	@fn	���݂̃V�[�����ɖ��t���[���X�V����������
	*/
	SceneBase* update() override;

private:

	//�`���[�g���A���V�[���̃|�C���^
	TutorialScene*	  mTutorial;
	//�X�e�[�W01�V�[���̃|�C���^
	Stage01Scene* mStage01;
	//�X�e�[�W02�V�[���̃|�C���^
	Stage02Scene* mStage02;
};

