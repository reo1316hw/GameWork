/*
@brief	�v���v���Z�b�T
*/
#pragma once

class Sprite;
class InputSystem;
class MapCreate;
class HeartUI;
class GoalLine;
class CheckpointBoard;
class Player;

class SceneBase
{
public:

    /*
    @fn	�R���X�g���N�^
    */
    SceneBase() {};

    /*
    @fn	�f�X�g���N�^
    */
    virtual ~SceneBase() {};

    /*
    @fn	���݂̃V�[�����ɖ��t���[���X�V����������
    */
    virtual SceneBase* update() = 0;

    /*
    @enum �V�[���̎��
    */
    enum Scene
    {
        // ���̑�
        other,
        // �^�C�g��
        title,
        // �`���[�g���A��
        tutorial,
        // �X�e�[�W�Z���N�g���
        stageSelect,
        // �X�e�[�W1
        stage01,
        // �X�e�[�W2
        stage02,
        // �Q�[���N���A
        gameClear,
        // �Q�[���I�[�o�[
        gameOver,
        // �R���e�B�j���[ 
        Continue
    };

protected:

    //�w�i
    Sprite*      mSprite;
    //���͊Ǘ��N���X
    InputSystem* mInputSystem;
    //�}�b�v����
    MapCreate*   mMapCreate;
    //�v���C���[�̃|�C���^
    Player*      mPlayer;
    //�S�[�����C��
    GoalLine*        mGoalLine;
    //�`�F�b�N�|�C���g�{�[�h
    CheckpointBoard* mCheckPointBoard;
    //�v���C���[�̗̑�UI
    HeartUI*     mHeartUI;
    //�Q�[���N���A������
    bool         mClearFlag;
    //���̃V�[���ɑJ�ڂ��鎞�̑ҋ@����
    int          mNextSceneCount;

private:

    //���݂̃V�[��
    static int   mIsScene;

public://�Q�b�^�[�Z�b�^�[

    /*
    @return ���݂̃V�[��(int�^)
    */
    static int  GetScene() { return mIsScene; };

    /*
    @param _isScene ���݂̃V�[��
    */
    virtual void SetScene(int _isScene) { mIsScene = _isScene; };
};