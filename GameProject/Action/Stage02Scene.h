/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include "SceneBase.h"

class Stage02Scene : public SceneBase
{
public:

	/*
	@fn		�R���X�g���N�^
	@param	_nowScene ���݂̃V�[��
	*/
	Stage02Scene(const Scene& _nowScene);

	/*
	@fn	�f�X�g���N�^
	*/
	~Stage02Scene();

	/*
	@fn	���݂̃V�[�����ɖ��t���[���X�V����������
	*/
	SceneBase* update() override;

	static bool GetContinueStage02Flag() { return mSendContinueStage02Flag; };
	static void SetContinueStage02Flag(bool _continue) { mSendContinueStage02Flag = _continue; };

private:

	static bool mSendContinueStage02Flag;

	//�R���e�B�j���[�V�[���Ɉڍs���邩�̃t���O
	bool mContinueStage02Flag;
};

