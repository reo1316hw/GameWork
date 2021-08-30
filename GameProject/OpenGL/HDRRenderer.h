/*
@brief	�v���v���Z�b�T
*/
#pragma once

/*
@brief	�C���N���[�h
*/

class HDRRenderer
{
public:
	
	/*
	@fn		�R���X�g���N�^
	@param	_fboWidth �o�b�t�@�[�̕�
	@param	_fboHeight �o�b�t�@�[�̍���
	@param	_bloomLevel �_�E���T���v�����O���̒i�K
	*/
	HDRRenderer(int _fboWidth, int _fboHeight, int _bloomLevel);

	/*
	@fn	�f�X�g���N�^
	*/
	~HDRRenderer();

	/*
	@fn	HDR�J�n
	*/
	void HdrRecordBegin();

	/*
	@fn	HDR�I��
	*/
	void HdrRecordEnd();

	/*
	@fn	�_�E���T���v�����O�{�K�E�X�ڂ���
	*/
	void HiBrightBlurCreate();

	/*
	@fn	�g�[���}�b�s���O�{�u���[������
	*/
	void HdrTonemapAndBrightBlurCombine();

	/*
	@fn	�u���[�����ɐ[�x���������Č���ʒu�����߂�
	*/
	void CopyDepthToScreen();

private:

	/*
	@fn	HDR�o�b�t�@�[�̓o�^
	*/
	void  InitHDRBuffers();

	/*
	@fn	�ڂ����o�b�t�@�[�̓o�^
	*/
	void  InitBlurBuffers();

	/*
	@fn	��ʑS�̂�`���l�p�`�p���_�z��̓o�^
	*/
	void  InitScreenQuadVAO();

	float GaussianDistribution(const Vector2& _pos, float _rho);

	/*
	@fn	�K�E�X�ڂ����v�Z
	*/
	void  CalcGaussBlurParam(int _w, int _h, Vector2 _dir, float _deviation);

	//�K�E�X�ڂ����V�F�[�_�[
	class Shader*             mGaussianBlurShader;
	//�_�E���T���v�����O�V�F�[�_�[
	class Shader*             mDownSamplingShader;
	//�g�[���}�b�v&�u���[�������V�F�[�_�[
	class Shader*             mHdrToneAndBlurBlendShader;

	//��ʑS�̂�`���l�p�`�p���_�z��
	unsigned int              mQuadScreenVAO;
	//��ʑS�̂�`���l�p�`�p���_�o�b�t�@�[
	unsigned int              mQuadScreenVBO;
	//�o�b�t�@�[�̕�
	unsigned int              mBufferWidth;
	//�o�b�t�@�[�̍���
	unsigned int              mBufferHeight;
	//�_�E���T���v�����O���̒i�K
	unsigned int              mBloomBufferLevel;
	//���������_�t���[���o�b�t�@�I�u�W�F�N�g
	unsigned int              mHdrFBO;
	//�����_�[�o�b�t�@
	unsigned int              mHdrRBO;
	//2�̃J���[�o�b�t�@
	unsigned int              mHdrColorBuffers[2];

	//�u���[�p�̃t���[���o�b�t�@�I�u�W�F�N�g
	std::vector<unsigned int> mBlurFBOs;
	// �u���[���ʂ̃e�N�X�`��ID
	std::vector<unsigned int> mBlurBufferTexs;

	//�K�E�X�ڂ����̃T���v�����O�_
	const int                 mSampleCount = 15;
	//�T���v�����O�_�̍��W(u,v) & w:�d��
	Vector3                   mOffset[15];
};