/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/
#include"GameObject.h"
#include "RapidJsonHelper.h"
#include <vector>

class MapCreate : public GameObject
{
public:

	/*
	@fn	�R���X�g���N�^
	*/
	MapCreate();

	/*
	@fn	�f�X�g���N�^
	*/
	~MapCreate();

	/*
	@fn		json�t�@�C����RapidJson�œǂݍ���Ń}�b�v�f�[�^���e�z��Ɋi�[����
	@return	�t�@�C�����J������(bool�^)
	*/
	bool OpenFile();

	/*
	@fn	���𐶐�����
	*/
	void CreateGround();

	/*
	@fn	�K���X���𐶐�����
	*/
	void CreateGlass();

	/*
	@fn	��Q���𐶐�����
	*/
	void CreateBlock();

	/*
	@fn	�c�ړ����𐶐�����
	*/
	void CreateVerticalMoveGround();

	/*
	@fn	�W�����v���𐶐�����
	*/
	void CreateJump();

	/*
	@fn	���ړ����𐶐�����
	*/
	void CreateLateralMoveGround();

	/*
	@fn	�v���C���[�𐶐�����
	*/
	void CreatePlayer();

	/*
	@fn	��ړ��u���b�N�𐶐�����
	*/
	void CreateUpBlock();
	void CreateUpBlock_02();

	/*
	@fn	�c����Q���𐶐�����
	*/
	void CreateVerticalBlock();

	/*
	@fn	�󒆃u���b�N�𐶐�����
	*/
	void CreateAerialBlock();

	/*
	@fn	�E�ړ��u���b�N�𐶐�����
	*/
	void CreateRightBlock();

	/*
	@fn	���ړ��u���b�N�𐶐�����
	*/
	void CreateLeftBlock();

	/*
	@fn	1�}�X�E�ړ����𐶐�����
	*/
	void CreateRightOneBlock();
	void CreateRightOneBlock_02();

	/*
	@fn	1�}�X���ړ����𐶐�����
	*/
	void CreateLeftOneBlock();
	void CreateLeftOneBlock_02();

	/*
	@fn	�����u���b�N�𐶐�����
	*/
	void CreateDownBlock();

	/*
	@fn	�S�[�����𐶐�����
	*/
	void CreateGoal();

	/*
	@fn	���X�|�[���n�_�𐶐�����
	*/
	void CreateRespawn01();
	void CreateRespawn02();
	void CreateRespawn03();

private:

	bool readTiledJson(std::vector<std::vector<int>>& _mapData, const char* _fileName, const char* _layerName);

	int  findLayerIndex(rapidjson::GenericArray<false,rapidjson::Value>& _layer,std::string& _layerName);

	//���}�b�v�f�[�^
	std::vector<std::vector<int>> mGroundMapData;
	//�v���C���[�}�b�v�f�[�^
	std::vector<std::vector<int>> mPlayerMapData;
	//���ړ����}�b�v�f�[�^
	std::vector<std::vector<int>> mLateralMoveGroundMapData;
	//�c�ړ����}�b�v�f�[�^
	std::vector<std::vector<int>> mVerticalMoveGroundMapData;
	//�W�����v���}�b�v�f�[�^
	std::vector<std::vector<int>> mJumpMapData;
	//��Q���}�b�v�f�[�^
	std::vector<std::vector<int>> mBlockMapData;
	//�K���X���}�b�v�f�[�^
	std::vector<std::vector<int>> mGlassMapData;
	//��ړ��u���b�N�}�b�v�f�[�^
	std::vector<std::vector<int>> mUpBlockMapData;
	std::vector<std::vector<int>> mUpBlock02MapData;
	//�c����Q���}�b�v�f�[�^
	std::vector<std::vector<int>> mVerticalBlockMapData;
	//�󒆃u���b�N�}�b�v�f�[�^
	std::vector<std::vector<int>> mAerialBlockMapData;
	//�E�ړ��u���b�N�}�b�v�f�[�^
	std::vector<std::vector<int>> mRightBlockMapData;
	//���ړ��u���b�N�}�b�v�f�[�^
	std::vector<std::vector<int>> mLeftBlockMapData;
	//1�}�X�E�ړ����}�b�v�f�[�^
	std::vector<std::vector<int>> mRightOneBlockMapData;
	std::vector<std::vector<int>> mRightOneBlock02MapData;
	//1�}�X���ړ����}�b�v�f�[�^
	std::vector<std::vector<int>> mLeftOneBlockMapData;
	std::vector<std::vector<int>> mLeftOneBlock02MapData;
	//�����u���b�N�}�b�v�f�[�^
	std::vector<std::vector<int>> mDownBlockMapData;
	//�S�[�����}�b�v�f�[�^
	std::vector<std::vector<int>> mGoalBlockMapData;
	//���X�|�[���n�_�}�b�v�f�[�^
	std::vector<std::vector<int>> mRespawn01MapData;
	std::vector<std::vector<int>> mRespawn02MapData;
	std::vector<std::vector<int>> mRespawn03MapData;

	//���݂̃V�[��
	int mScene;
	//���̃}�b�v�f�[�^
	int	mSizeX;
	//�����̃}�b�v�f�[�^
	int	mSizeY;
	//���s�̃}�b�v�f�[�^
	int	mSizeZ;

	//�I�u�W�F�N�g���Ƃ̋���
	float mOffset;
};

