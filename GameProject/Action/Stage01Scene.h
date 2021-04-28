/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include "SceneBase.h"

class Stage01Scene : public SceneBase
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_nowScene ���݂̃V�[��
	*/
	Stage01Scene(const Scene& _nowScene);

	/*
	@fn	�f�X�g���N�^
	*/
	~Stage01Scene();
 
	/*
	@fn	���݂̃V�[�����ɖ��t���[���X�V����������
	*/
	SceneBase* update() override;

	static bool GetContinueStage01Flag() { return mSendContinueStage01Flag; };
	static void SetContinueStage01Flag(bool _continue) { mSendContinueStage01Flag = _continue; };

private:

	static bool mSendContinueStage01Flag;

	//�R���e�B�j���[�V�[���Ɉڍs���邩�̃t���O
	bool mContinueStage01Flag;
};

