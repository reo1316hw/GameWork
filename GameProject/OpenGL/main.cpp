//-----------------------------------------------------------------------------
//	@brief	�C���N���[�h
//-----------------------------------------------------------------------------
#include "pch.h"

#include "Windows.h"

/*
�N���X���ł̐錾���Ԃ�public>protected>private>public(GetSet)�̏�
*/

/*
 @file ��.h
 @brief �ȒP�Ȑ���
*/

/*
   @fn �����Ɋ֐��̐���������
   @brief �v�����
   @param ������ ����
   @return �߂�l�̐���
   @sa �Q�Ƃ��ׂ��֐��������΃����N���\���
   @detail �ڍׂȐ���
 */

/*
	@param ������ ����
*/

/*
  @fn
  @brief
*/

/*
  @fn
*/

/*
   @fn
   @brief
   @return
*/

/*
	 @enum Enum
	 ����
*/

///*
//@fn		�����`���[(Launcher.exe)�Ăяo���֐� 
//@param	_path Launcher.exe�ւ̑��΃p�X�ւ̕����������
//*/
//void runLauncher(const char* _path)
//{
//
//	char fullPathexe[512];
//#pragma warning (disable:4996)
//	sprintf(fullPathexe, "%s%s", _path, "Launcher.exe");
//
//	// �v���Z�X�N������
//	PROCESS_INFORMATION pi = { 0 };
//	STARTUPINFO si = { 0 };
//	si.cb = sizeof(STARTUPINFO);
//
//	CreateProcess(fullPathexe, (LPSTR)"", NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, _path, &si, &pi);
//}


/*
@fn		main�֐�
@param  argc �R�}���h���C�������̐�
@param  argv �R�}���h���C������
*/
int main(int argc, char** argv)
{
	//�Q�[���N���X�̒�`
	Game game;
	//�Q�[���N���X�̏�����������������
	bool success = game.Initialize();
	game.SetFirstScene(new TitleScene(SceneBase::title));
	if (success)
	{
		game.GameLoop();
	}
	//�Q�[���N���X�̏I������
	game.Termination();

	//runLauncher("../../");

	return 0;
}