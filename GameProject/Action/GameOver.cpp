/*
@brief	�C���N���[�h
*/
#include "GameOver.h"
#include "TitleScene.h"
#include "Renderer.h"
#include "Sprite.h"
#include "InputSystem.h"

/*
@fn		�R���X�g���N�^
@param	_nowScene ���݂̃V�[��
*/
GameOver::GameOver(const Scene& _nowScene)
{
	// ���C�g��ݒ�(�ݒ肵�Ȃ��Ɖ����f��Ȃ�)
	RENDERER->SetAmbientLight(Vector3(0.4f, 0.4f, 0.4f));
	DirectionalLight& dir = RENDERER->GetDirectionalLight();
	dir.m_direction = Vector3(1.0f, 0.7f, -0.7f);
	//dir.diffuseColor = Vector3(1.0f, 1.0f, 1.0f);
	dir.m_diffuseColor = Vector3(0.78f, 0.88f, 1.0f);
	dir.m_specColor = Vector3(0.8f, 0.8f, 0.8f);

	SetScene(_nowScene);

	mInputSystem = new InputSystem();
	mInputSystem->Initialize();

	mSprite = new Sprite("Assets/GameOver02.png");

	mNextSceneCount = 0;
}

/*
@fn	�f�X�g���N�^
*/
GameOver::~GameOver()
{
	delete mSprite;
}

/*
@fn	���݂̃V�[�����ɖ��t���[���X�V����������
*/
SceneBase* GameOver::update()
{
	mNextSceneCount++;
	if (mNextSceneCount >= 160)
	{
		return new TitleScene(title);
	}

	return this;
}
