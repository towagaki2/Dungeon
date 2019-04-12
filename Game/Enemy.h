#pragma once
#include "character/CharacterController.h"
#include "CharaMove.h"
#include"GameDefine.h"

class Enemy
{
public:
	Enemy();
	~Enemy();
	void EnStatus();
	void Update();
	void Draw();

	const CVector3* GetPosition()
	{
		return &m_position;
	}
	CQuaternion GetRotation()
	{
		return m_rotation;
	}
	//�G�l�~�[�̃^�[���t���O�B
	int GetEneSummaryF()
	{
		return summaryF;
	}
	void SetEneSummaryF(int eneSummaryF)
	{
		summaryF = eneSummaryF;
	}

private:
	void Move();		//�ړ������B
	void Turn();		//��]�����B

	int HP = 10;		//�̗͒l�B
	int ATK = 6;		//�U���́B
	int DEF = 5;		//�h��́B
	

	CharaMove enemyMove;		//�ړ�����B

	int moveF = 0;			//�ړ��t���O�B	
	int attackF = 0;		//�U���t���O�B
	int standF = 0;			//�ҋ@�t���O�B
	int summaryF = 0;			//�t���O�̑����B

	int FrameCounter = 0;		//�t���[���̃J�E���^�[�B

	SkinModel m_model;									//�X�L�����f���B
	Animation m_animation;								//�A�j���[�V�����B
	AnimationClip m_animationClips[2];					//�A�j���[�V�����N���b�v�B
	CVector3 m_position = {masu*10,0.0f,masu*5};				//���W�B
	float m_Length=(1000.0f*(1.0f/30.0f))*sqrt(2);			//1�}�X�̒���
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CVector3 m_moveSpeed = CVector3::Zero();			//�ړ����x�B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B								
	CharacterController m_charaCon;			//�L�����N�^�[�R���g���[���[��ǉ��B
	
};

