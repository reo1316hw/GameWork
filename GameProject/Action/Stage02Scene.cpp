/*
@brief	�C���N���[�h
*/
#include "Stage02Scene.h"
#include "GameClear.h"
#include "GameOver.h"
#include "ContinueScene.h"
#include "Stage01Scene.h"
#include "Renderer.h"
#include "GameObjectManager.h"
#include "HeartUI.h"
#include "Sprite.h"
#include "GoalLine.h"
#include "CheckpointBoard.h"
#include "MapCreate.h"

bool	Stage02Scene::mSendContinueStage02Flag = false;

/*
@fn		�R���X�g���N�^
@param	_nowScene ���݂̃V�[��
*/
Stage02Scene::Stage02Scene(const Scene& _nowScene)
{
	// ���C�g��ݒ�(�ݒ肵�Ȃ��Ɖ����f��Ȃ�)
	RENDERER->SetAmbientLight(Vector3(0.4f, 0.4f, 0.4f));
	DirectionalLight& dir = RENDERER->GetDirectionalLight();
	dir.m_direction = Vector3(0.0f, 1.0f, 0.0f);
	//dir.diffuseColor = Vector3(1.0f, 1.0f, 1.0f);
	dir.m_diffuseColor = Vector3(0.5f, 0.6f, 0.8f);
	dir.m_specColor = Vector3(0.8f, 0.8f, 0.8f);

	SetScene(_nowScene);

	mGoalLine = new GoalLine(Vector3(800, 150, -2200), Vector3::Zero, Tag::Other, Scene::stage02);

	for (int i = 0; i < 3; i++)
	{
		if (i <= 1)
		{
			mCheckPointBoard = new CheckpointBoard(Vector3(800.0f, 500.0f,( -81500.0f + i * 21200.0f)), Vector3::Zero, "Assets/checkpoint_stage02.png", Tag::checkpoint, Scene::stage02);

		}
		else
		{
			mCheckPointBoard = new CheckpointBoard(Vector3(800.0f, 500.0f, -29300.0f), Vector3::Zero, "Assets/checkpoint_stage02.png", Tag::checkpoint, Scene::stage02);
		}
	}

	mSprite = new Sprite("Assets/stage04.png");

	mMapCreate = new MapCreate();
	if (!mMapCreate->OpenFile())
	{
		mMapCreate->CreateGround();
		mMapCreate->CreateGlass();
		mMapCreate->CreateBlock();
		mMapCreate->CreateVerticalMoveGround();
		mMapCreate->CreateJump();
		mMapCreate->CreateLateralMoveGround();
		mMapCreate->CreatePlayer();
		mMapCreate->CreateUpBlock();
		mMapCreate->CreateUpBlock_02();
		mMapCreate->CreateVerticalBlock();
		mMapCreate->CreateAerialBlock();
		mMapCreate->CreateRightBlock();
		mMapCreate->CreateLeftBlock();
		mMapCreate->CreateRightOneBlock();
		mMapCreate->CreateRightOneBlock_02();
		mMapCreate->CreateLeftOneBlock();
		mMapCreate->CreateLeftOneBlock_02();
		mMapCreate->CreateDownBlock();
		mMapCreate->CreateGoal();
		mMapCreate->CreateRespawn01();
		mMapCreate->CreateRespawn02();
		mMapCreate->CreateRespawn03();
	}

	for (int i = 0; i < 3; i++)
	{
		mHeartUI = new HeartUI(Vector2(i * 100.0f, 50.0f), Tag::Other, Scene::stage02);
	}

	mClearFlag = false;

	mContinueStage02Flag = false;
	mNextSceneCount = 0;
}

/*
@fn	�f�X�g���N�^
*/
Stage02Scene::~Stage02Scene()
{
	GAME_OBJECT_MANAGER->RemoveGameObjects(stage02);
	delete mSprite;
	delete mMapCreate;
}

/*
@fn	���݂̃V�[�����ɖ��t���[���X�V����������
*/
SceneBase* Stage02Scene::update()
{
	if (mPlayer->GetClearFlag())
	{
		mNextSceneCount++;

		if (mNextSceneCount >= 80)
		{
			return new GameClear(gameClear);
		}
	}

	if (mPlayer->GetDeathFlag())
	{
		mNextSceneCount++;

		if (mNextSceneCount >= 80)
		{
			mContinueStage02Flag = true;
			mSendContinueStage02Flag = mContinueStage02Flag;

			return new ContinueScene(Continue);
		}
	}

	return this;
}