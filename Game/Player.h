#pragma once
#include "character/CharacterController.h"


class Player
{
public:
	Player();
	~Player();
	void PlStatus();
	void Update();
	void Draw();
	//�v���C���[�̃X�e�[�^�X�̃Q�b�^�[�Z�b�^�[�B
	int GetplHP()
	{
		return plHP;
	}
	void SetplHP(int plplHP)
	{
		plHP += plplHP;
	}
	int GetplDEF()
	{
		return plDEF;
	}
	//�v���C���[�̃|�W�V�����ƌ����̃Q�b�^�[�B
	CVector3 GetPosition()
	{
		return m_position;
	}
	CQuaternion GetRotation()
	{
		return m_rotation;
	}
	//�v���C���[�̃^�[���t���O�̃Q�b�^�[�ƃZ�b�^�[�B
	int GetPlSummaryF()
	{
		return summaryF;
	}
	void SetPlSummaryF(int plSummaryF)
	{
		summaryF = plSummaryF;
	}
	//�����x�̃Z�b�^�[�B
	void SetHUN(int SetHun)
	{
		HUN += SetHun;
	}

private:
	
	int plHP = 10;		//�q�b�g�|�C���g�B
	int plATK = 10;		//�U���́B
	int plDEF = 5;		//�h��́B
	int HUN = 100;		//�����x�B
	void Move();		//�ړ������B
	void Turn();		//��]�����B�@

	int moveF = 0;			//�ړ��t���O�B	
	int attackF = 0;		//�U���t���O�B
	int standF = 0;			//�ҋ@�t���O�B
	int summaryF = 0;		//�t���O�̑����B
	

	SkinModel m_model;									//�X�L�����f���B
	Animation m_animation;								//�A�j���[�V�����B
	AnimationClip m_animationClips[2];					//�A�j���[�V�����N���b�v�B
	CVector3 m_position = CVector3::Zero();				//���W�B
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CVector3 m_moveSpeed = CVector3::Zero();			//�ړ����x�B
	CVector3 enpo;										//NPC��Player�̋����B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B	
	CharacterController m_charaCon;						//�L�����N�^�[�R���g���[���[��ǉ��B
};

