/*
@brief	�C���N���[�h
*/
#include "pch.h"

#include "CheckpointEffectManager.h"
#include "SandEffectManager.h"
#include "ClearEffectManager.h"
#include "DeathEffectManager.h"

Vector3 Player::mSendPos = Vector3::Zero;
bool	Player::mSendClearFlag = false;
bool	Player::mSendDeathFlag = false;
bool    Player::mSendRespawnFlag = false;
bool	Player::mSendCheckpointFlag = false;
int     Player::mSendLife = 0;

/*
@fn		�R���X�g���N�^
@param	_pos �v���C���[�̍��W
@param	_size �v���C���[�̃T�C�Y
@param	_objectTag �v���C���[�̃^�O
@param	_sceneTag �V�[���̃^�O
*/
Player::Player(const Vector3& _pos, const Vector3& _size, const std::string _gpmeshName, const Tag& _objectTag, const SceneBase::Scene _sceneTag)
	: GameObject(_sceneTag, _objectTag)
	, mPlayerSphere(Vector3::Zero,0.0f)
	, mVisibleFrameCount(0)
	, mLife(0)
	, mCheckpointEffectCount(0)
	, mAngle(0.0f)
	, mScene(SceneBase::other)
	, mDeathFlag(false)
	, mDamageFlag(false)
	, mStopFlag(false)
	, mClearFlag(false)
	, mJumpFlag(false)
	, mScaleFlag(false)
	, mGroundFlag(false)
	, mCollisionFlag(true)
	, mCheckpointFlag(false)
{
	//GameObject�����o�ϐ��̏�����
	mTag = _objectTag;
	SetScale(_size);
	SetPosition(_pos);

	// ���x�̒l
	mMoveSpeed = PLAYER_CONSTANT_SPEED;
	mGravity   = GRAVITY_ACCEL;
	mLife	  = PLAYER_LIFE;
	mRespawnState = RespawnState::respawnNone;

	//��������Player�̐������Ɠ�����Component���N���X�͎����ŊǗ��N���X�ɒǉ����ꎩ���ŉ�������
	mMeshComponent = new MeshComponent(this);

	//Renderer�N���X����Mesh�ǂݍ��݊֐��𗘗p����Mesh���Z�b�g(.gpmesh)
	mMeshComponent->SetMesh(RENDERER->GetMesh(_gpmeshName));

	//�G�t�F�N�g
	mSandEffectManager = new SandEffectManager(this, _objectTag, _sceneTag);
	mCheckpointEffectManager = new CheckpointEffectManager(this, _objectTag, _sceneTag);
	mClearEffectManager = new ClearEffectManager(this, _objectTag, _sceneTag);
	mDeathEffectManager = new DeathEffectManager(this, _objectTag, _sceneTag);
	mCheckpointEffectManager = new CheckpointEffectManager(this, _objectTag, _sceneTag);

	//�v���C���[���g�̓����蔻��
	mSelfSphereCollider = new SphereCollider(this, ColliderTag::playerTag, GetOnCollisionFunc());
	Sphere sphere = { Vector3::Zero,30.0f };
	mSelfSphereCollider->SetObjectSphere(sphere);

	mLateralMoveVelocity = Vector3::Zero;

	mButtonFlag = false;
}

/*
@fn		�v���C���[�̃A�b�v�f�[�g
@param	_deltaTime �Ō�̃t���[������������̂ɗv��������
*/
void Player::UpdateGameObject(float _deltaTime)
{
	//�v���C���[�̎΂ߌ��ɃJ�������Z�b�g
	mMainCamera->SetViewMatrixLerpObject(Vector3(0, 500, -550), mPosition);

	mScene = SceneBase::GetScene();

	//�X�e�[�W�N���A������v���C���[�̍X�V���~�߂�
	if (mClearFlag)
	{
		SetState(State::Dead);
	}

	//�v���C���[��������̍��W�܂ŗ�������_���[�W���󂯂�
	if (mPosition.y <= -700.0f)
	{
		mPosition.y = -699.0f;
		mDamageFlag = true;
	}

	//�_���[�W���󂯂���̗͂����炷
	if (mDamageFlag)
	{
		mLife -= 1;
		mRespawnFlag = true;
		mDamageFlag  = false;
	}

	//�`���[�g���A��
	if (mScene == SceneBase::tutorial)
	{
		//�`���[�g���A�����̑O���ړ����x
		mMoveSpeed = TUTORIAL_MOVE_SPEED;
		//�`���[�g���A�����̃W�����v��
		if (mJumpFlag)
		{
			mLateralMoveVelocity = Vector3::Zero;
			mVelocity.y = TUTORIAL_JUMP_SPEED;
			mScaleFlag = true;
			mJumpFlag = false;
		}

		//�`���[�g���A�����̃��X�|�[������
		if (mRespawnState == RespawnState::respawnNone)
		{
			if (mRespawnFlag)
			{
				if (mLife >= 1)
				{
					mPosition = Vector3(800.0f, 500.0f, -99800.0f);
				}
			}
		}

		//�`���[�g���A�����̃S�[���̍��W
		if (mPosition.z >= -75700)
		{
			mClearFlag = true;
		}
	}

	//�X�e�[�W01
	if (mScene == SceneBase::stage01)
	{
		//�X�e�[�W01�̃W�����v��
		if (mJumpFlag)
		{
			mLateralMoveVelocity = Vector3::Zero;
			mVelocity.y = JUMP_SPEED;
			mScaleFlag = true;
			mJumpFlag = false;
		}

		//�X�e�[�W01�̃��X�|�[������
		switch (mRespawnState)
		{
		//�X�e�[�W01�̏������X�|�[���n�_
		case RespawnState::respawnNone:
			if (mRespawnFlag)
			{
				if (mLife >= 1)
				{
					mPosition = Vector3(800.0f, 500.0f, -99800.0f);
				}
			}
			break;
		//�X�e�[�W01�̃��X�|�[���n�_01
		case RespawnState::respawnComplete01:

			if (mRespawnFlag)
			{
				if (mLife >= 1)
				{
					mPosition = Vector3(800.0f, 500.0f, -81000.0f);
				}
			}

			break;
		//�X�e�[�W01�̃��X�|�[���n�_02
		case RespawnState::respawnComplete02:

			if (mRespawnFlag)
			{
				if (mLife >= 1)
				{
					mPosition = Vector3(800.0f, 500.0f, -56500.0f);
				}
			}

			break;
		//�X�e�[�W01�̃��X�|�[���n�_03
		case RespawnState::respawnComplete03:

			if (mRespawnFlag)
			{
				if (mLife >= 1)
				{
					mPosition = Vector3(1100.0f, 500.0f, -37500.0f);
				}
			}

			break;
		}

		//�X�e�[�W01�̃S�[�����W
		if (mPosition.z >= -8900)
		{
			mClearFlag = true;
		}
	}

	//�X�e�[�W02
	if (mScene == SceneBase::stage02)
	{
		//�X�e�[�W02�̃W�����v��
		if (mJumpFlag)
		{
			mLateralMoveVelocity = Vector3::Zero;
			mVelocity.y = JUMP_SPEED;
			mScaleFlag = true;
			mJumpFlag = false;
		}

		//�X�e�[�W02�̃��X�|�[������
		switch (mRespawnState)
		{
		//�X�e�[�W02�̏������X�|�[���n�_
		case RespawnState::respawnNone:
			if (mRespawnFlag)
			{
				if (mLife >= 1)
				{
					mPosition = Vector3(800.0f, 500.0f, -99800.0f);
				}
			}
			break;
		//�X�e�[�W02�̃��X�|�[���n�_01
		case RespawnState::respawnComplete01:

			if (mRespawnFlag)
			{
				if (mLife >= 1)
				{
					mPosition = Vector3(800.0f, 500.0f, -83000.0f);
				}
			}

			break;
		//�X�e�[�W02�̃��X�|�[���n�_02
		case RespawnState::respawnComplete02:

			if (mRespawnFlag)
			{
				if (mLife >= 1)
				{
					mPosition = Vector3(800.0f, 500.0f, -61500.0f);
				}
			}

			break;
		//�X�e�[�W02�̃��X�|�[���n�_03
		case RespawnState::respawnComplete03:

			if (mRespawnFlag)
			{
				if (mLife >= 1)
				{
					mPosition = Vector3(800.0f, 500.0f, -30000.0f);
				}
			}

			break;
		}

		//�X�e�[�W02�̃S�[���̍��W
		if (mPosition.z >= -2100)
		{
			mClearFlag = true;
		}
	}

	//�S�X�e�[�W���ʂ̃��X�|�[������
	if (mRespawnFlag)
	{
		mLateralMoveVelocity = Vector3::Zero;
		mCollisionFlag = true;

		if (mLife >= 1)
		{
			mStopFlag = true;
		}
	}

	//���X�|�[����̑ҋ@���Ԓ�����
	if (mStopFlag)
	{
		mAngle = 0.0f;

		mVisibleFrameCount++;
		if (mVisibleFrameCount % 10 == 0)
		{
			mMeshComponent->SetVisible(false);
		}

		if (mVisibleFrameCount % 10 == 5)
		{
			mMeshComponent->SetVisible(true);
		}

		mVelocity = Vector3::Zero;
		if (mVisibleFrameCount >= 40)
		{
			mVisibleFrameCount = 0;
			mVelocity.z = mMoveSpeed;
			mVelocity.y = mMoveSpeed;
			mStopFlag = false;

			mMeshComponent->SetVisible(true);
		}
	}
	
	//�̗�0�ɂȂ������̏���
	if (mLife <= 0)
	{
		mDeathFlag = true;
		SetState(State::Dead);
	}

	///////////////////////////////////////////////////////
	//�X�P�[���k������
	if (mScaleFlag)
	{
		mScale.y = 1.2f + (mPosition.y - 120.0f) * 0.0015f;
		mScale.z = 1.2f + (mPosition.y - 120.0f) * 0.0015f;
	}
	if (mPosition.y <= 120.0f && mVelocity.y <= 0.0f)
	{
		mScaleFlag = false;
		mScale.x = 1.2f;
		mScale.y = 1.2f;
		mScale.z = 1.2f;
	}
	///////////////////////////////////////////////////////

	//�W�����v�����Ƃ��ɉ�]��x�����鏈��
	if (mPosition.y >= 200)
	{
		if (mStopFlag == false)
		{
			mAngle = 2.0f;
		}
	}
	else
	{
		mAngle = 10.0f;
	}

	//��]����
	float radian = Math::ToRadians(mAngle);
	Quaternion rot = this->GetRotation();
	Quaternion inc(Vector3::UnitX, radian);
	Quaternion target = Quaternion::Concatenate(rot, inc);
	SetRotation(target);
	
	//�E�ړ��̍ő呬�x
	if (mVelocity.x >= PLAYER_MAX_SPEED)
	{
		mVelocity.x = PLAYER_MAX_SPEED;
	}
	//���ړ��̍ő呬�x
	if (mVelocity.x <= -PLAYER_MAX_SPEED)
	{
		mVelocity.x = -PLAYER_MAX_SPEED;
	}

	// ��ɑO�ɐi��
	if (mStopFlag == false)
	{
		mVelocity.z = mMoveSpeed;
	}

	//�{�^���������Ă��Ȃ��Ƃ��̌�������
	if (mButtonFlag == false)
	{
		//���x��0���傫�������ꍇ�ɉE�Ɍ���
		if (mVelocity.x > 0.0f)
		{
			mVelocity.x += -PLAYER_SPEED_DOWN;
		}
		//���x��0��菬���������ꍇ�ɍ��Ɍ���
		else if (mVelocity.x < 0.0f)
		{
			mVelocity.x += PLAYER_SPEED_DOWN;
		}
		
		//���x�������x�̒l�ƈꏏ�ɂȂ����瑬�x��0�ɌŒ肷��
		if (mVelocity.x <= PLAYER_SPEED_DOWN && mVelocity.x > 0.0f ||
			mVelocity.x >= -PLAYER_SPEED_DOWN && mVelocity.x < 0.0f)
		{
			mVelocity.x = 0.0f;
		}

	}

	//�ڒn���Ă��Ȃ������X�|�[�����̑ҋ@���Ԃ���Ȃ����ɏd�͏������s��
	if (mGroundFlag == false && mStopFlag == false)
	{
		mVelocity.y -= mGravity;
	}

	//�v���C���[��������̍��W�܂ŗ������瓖���蔻��𖳌��ɂ���
	if (mPosition.y < 30.0f)
	{
		mCollisionFlag = false;
	}

	//�`�F�b�N�|�C���g�G�t�F�N�g������̐������Ԃ�1�ɂȂ�����`�F�b�N�|�C���g�G�t�F�N�g�𔭐������Ȃ��悤�ɂ���
	if (mCheckpointEffectCount == 1)
	{
		mCheckpointFlag = false;
		mCheckpointEffectCount = 0;
	}

	//�`�F�b�N�|�C���g��ʉ߂�����`�F�b�N�|�C���g�G�t�F�N�g������̐������Ԃ��J�E���g����
	if (mCheckpointFlag)
	{
		mCheckpointEffectCount++;
	}

	////�`�F�b�N�|�C���g�G�t�F�N�g������̐������Ԃ�1�ɂȂ�����`�F�b�N�|�C���g�G�t�F�N�g�𔭐������Ȃ��悤�ɂ���
	//if (mCheckpointEffectCount == 1)
	//{
	//	mCheckpointFlag = false;
	//	mCheckpointEffectCount = 0;
	//}

	////�`�F�b�N�|�C���g��ʉ߂�����`�F�b�N�|�C���g�G�t�F�N�g������̐������Ԃ��J�E���g����
	//if (mCheckpointFlag)
	//{
	//	mCheckpointEffectCount++;
	//}

	////�`�F�b�N�|�C���g�G�t�F�N�g������̐������Ԃ�1�ɂȂ�����`�F�b�N�|�C���g�G�t�F�N�g�𔭐������Ȃ��悤�ɂ���
	//if (mCheckpointEffectCount == 1)
	//{
	//	mCheckpointFlag = false;
	//	mCheckpointEffectCount = 0;
	//}

	////�`�F�b�N�|�C���g��ʉ߂�����`�F�b�N�|�C���g�G�t�F�N�g������̐������Ԃ��J�E���g����
	//if (mCheckpointFlag)
	//{
	//	mCheckpointEffectCount++;
	//}

	// ��ɍ��W�ɑ��x�𑫂�
 	mPosition += (mVelocity + mLateralMoveVelocity)/* * _deltaTime*/;


	mSendPos					= mPosition;
	mSendClearFlag				= mClearFlag;
	mSendDeathFlag				= mDeathFlag;
	mSendRespawnFlag			= mRespawnFlag;
	mSendCheckpointFlag			= mCheckpointFlag;
	mSendLife					= mLife;

	mRespawnFlag = false;
	mGroundFlag = false;

	// ���W���Z�b�g
	SetPosition(mPosition);

}

/*
@fn		���͂������Ŏ󂯎��X�V�֐�
@brief	��{�I�ɂ����œ��͏���ϐ��ɕۑ���UpdateGameObject�ōX�V���s��
@param	_keyState �e���͋@��̓��͏��
@brief	�L�[�{�[�h�A�}�E�X�A�R���g���[���[
*/
void Player::GameObjectInput(const InputState& _keyState)
{

	//// �R���g���[���[�̏\����������̓L�[�{�[�h�AW�����͂��ꂽ��z�𑫂�
	//if (_keyState.m_controller.GetButtonValue(SDL_CONTROLLER_BUTTON_DPAD_UP) == 1 ||
	//	_keyState.m_keyboard.GetKeyValue(SDL_SCANCODE_W) == 1)
	//{
	//	mVelocity.z = mMoveSpeed;
	//}
	//// �R���g���[���[�̏\�����������́A�L�[�{�[�hS�����͂��ꂽ��-z�𑫂�
	//else if (_keyState.m_controller.GetButtonValue(SDL_CONTROLLER_BUTTON_DPAD_DOWN) == 1 ||
	//		 _keyState.m_keyboard.GetKeyValue(SDL_SCANCODE_S) == 1)
	//{
	//	mVelocity.z = -mMoveSpeed;
	//}
	//// �R���g���[���[�̏\���ォ�R���g���[���[�̏\�������L�[�{�[�hW���L�[�{�[�hS�����͂���Ȃ������瑬�x��0�ɂ���
	//else if (_keyState.m_controller.GetButtonValue(SDL_CONTROLLER_BUTTON_DPAD_UP) == 0  ||
	//		 _keyState.m_controller.GetButtonValue(SDL_CONTROLLER_BUTTON_DPAD_DOWN) == 0||
	//		 _keyState.m_keyboard.GetKeyValue(SDL_SCANCODE_W) == 0 ||
	//		 _keyState.m_keyboard.GetKeyValue(SDL_SCANCODE_S) == 0)
	//{
	//	mVelocity.z *= 0;
	//}

	 //�R���g���[���[�̏\�����������́A�L�[�{�[�hA�����͂��ꂽ��-x�𑫂�
	if (_keyState.m_controller.GetButtonValue(SDL_CONTROLLER_BUTTON_DPAD_LEFT) == 1 ||
		_keyState.m_keyboard.GetKeyValue(SDL_SCANCODE_A) == 1)
	{
		mVelocity.x += -PLAYER_SPEED_UP;
	}
	// �R���g���[���[�̏\���E�������́A�L�[�{�[�hD�����͂��ꂽ��x�𑫂�
	else if (_keyState.m_controller.GetButtonValue(SDL_CONTROLLER_BUTTON_DPAD_RIGHT) == 1 ||
		_keyState.m_keyboard.GetKeyValue(SDL_SCANCODE_D) == 1)
	{
		mVelocity.x += PLAYER_SPEED_UP;
	}

	// �R���g���[���[�̏\�������R���g���[���[�̏\���E���L�[�{�[�hA���L�[�{�[�hD�����͂���Ȃ�������mButtonFlag��false�ɂ���
	else if (_keyState.m_controller.GetButtonValue(SDL_CONTROLLER_BUTTON_DPAD_LEFT) == 0 ||
		_keyState.m_controller.GetButtonValue(SDL_CONTROLLER_BUTTON_DPAD_RIGHT) == 0 ||
		_keyState.m_keyboard.GetKeyValue(SDL_SCANCODE_A) == 0 ||
		_keyState.m_keyboard.GetKeyValue(SDL_SCANCODE_D) == 0)
	{
		mButtonFlag = false;
	}

	/*if (_keyState.m_controller.GetButtonValue(SDL_CONTROLLER_BUTTON_B) == 1  ||
		_keyState.m_keyboard.GetKeyValue(SDL_SCANCODE_SPACE) == 1)
	{
		mVelocity.y = JUMP_SPEED;
	}*/
}

/*
@fn		�v���C���[���q�b�g�������̏���
@param	_hitObject �q�b�g�����Ώۂ̃Q�[���I�u�W�F�N�g�̃A�h���X
*/
void Player::OnCollision(const GameObject& _hitObject)
{
	if (mCollisionFlag)
	{
		//�d�͂�����
		mVelocity.y = 0;

		//�q�b�g�����I�u�W�F�N�g�̃^�O���擾
		mTag = _hitObject.GetTag();

		//�ڒn����
		if (mTag == ground ||
			mTag == glass ||
			mTag == verticalMoveGround ||
			mTag == rightGround ||
			mTag == leftGround ||
			mTag == lateralMoveGround ||
			mTag == jump ||
			mTag == downBlock)
		{
			mGroundFlag = true;
		}

		//�_���[�W����
		if (mTag == block ||
			mTag == verticalBlock ||
			mTag == rightBlock ||
			mTag == leftBlock ||
			mTag == rightOneMoveBlock ||
			mTag == leftOneMoveBlock ||
			mTag == aerialBlock ||
			mTag == upBlock)
		{
			mDamageFlag = true;
		}

		//�W�����v����
		if (mTag == jump)
		{
			mJumpFlag = true;
		}

		//���ړ����̔���
		if (mTag == lateralMoveGround)
		{
			//���ړ����̑��x���擾
			mLateralMoveVelocity = mLateral->GetVelocity();
		}
		else
		{
			mLateralMoveVelocity = Vector3::Zero;
		}

		//���X�|�[������
		if (mTag == respawn01)
		{
			mRespawnState = RespawnState::respawnComplete01;
		}
		if (mTag == respawn02)
		{
			mRespawnState = RespawnState::respawnComplete02;
		}
		if (mTag == respawn03)
		{
			mRespawnState = RespawnState::respawnComplete03;
		}

		if (mTag == checkpoint)
		{
			mCheckpointFlag = true;
		}
	}
}