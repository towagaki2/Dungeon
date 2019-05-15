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

	//�G�l�~�[HP�̃Q�b�^�[�B
	int GetenHP()
	{
		return enHP;
	}
	//�G�l�~�[HP�̃Z�b�^�[�B
	void SetenHP(int enenHP)
	{
		enHP += enenHP;
	}
	//�G�l�~�[DEF�̃Q�b�^�[�B
	int GetenDEF()
	{
		return enDEF;
	}
	//�G�l�~�[�̏ꏊ�ƌ����̃Q�b�^�[�B
	const CVector3& GetPosition()
	{
		return m_position;
	}
	CQuaternion GetRotation()
	{
		return m_rotation;
	}
	/// <summary>
	/// �G�l�~�[�̃t���O�����̃Q�b�^�[�B
	/// </summary>
	/// <returns></returns>
	int GetEneSummaryF()
	{
		return summaryF;
	}
	/// <summary>
	/// �G�l�~�[�̃t���O�����̃Z�b�^�[�B
	/// </summary>
	/// <param name="eneSummaryF">
	/// �t���O�B
	/// </param>
	void SetEneSummaryF(int eneSummaryF)
	{
		summaryF = eneSummaryF;
	}

private:
	void Move();		//�ړ������B
	void Turn();		//��]�����B

	int enHP = 10;		//�̗͒l�B
	int enATK = 6;		//�U���́B
	int enDEF = 5;		//�h��́B
	

	CharaMove enemyMove;	//�ړ�����B

	int moveF = 0;			//�ړ��t���O�B	
	int attackF = 0;		//�U���t���O�B
	int standF = 0;			//�ҋ@�t���O�B
	int summaryF = 0;		//�t���O�̑����B

	int FrameCounter = 0;		//�t���[���̃J�E���^�[�B

	SkinModel m_model;									//�X�L�����f���B
	Animation m_animation;								//�A�j���[�V�����B
	AnimationClip m_animationClips[5];					//�A�j���[�V�����N���b�v�B
	CVector3 m_position = {masu*10,0.0f,masu*5};		//���W�B
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CVector3 m_moveSpeed = CVector3::Zero();			//�ړ����x�B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B								
	CharacterController m_charaCon;			//�L�����N�^�[�R���g���[���[��ǉ��B
	
};

