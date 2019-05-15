#pragma once
#include "character/CharacterController.h"
#include "font.h"

class Font;

class Player
{
public:
	Player();
	~Player();
	void PlStatus();
	void Update();
	void Draw();
	//�v���C���[��HP�̃Q�b�^�[�B
	int GetplHP()
	{
		return plHP;
	}
	//�v���C���[��HP�Z�b�^�[�B
	void SetplHP(int plplHP)
	{
		plHP += plplHP;
	}
	//�v���C���[��DEF�̃Q�b�^�[�B
	int GetplDEF()
	{
		return plDEF;
	}
	//�v���C���[�̃|�W�V�����̃Q�b�^�[�B
	CVector3 GetPosition()
	{
		return m_position;
	}
	//�v���C���[�̌����̃Q�b�^�[�B
	CQuaternion GetRotation()
	{
		return m_rotation;
	}
	//�v���C���[�̃^�[���t���O�̃Q�b�^�[�B
	int GetPlSummaryF()
	{
		return summaryF;
	}
	//�v���C���[�̃^�[���t���O�̃Z�b�^�[�B
	void SetPlSummaryF(int plSummaryF)
	{
		summaryF = plSummaryF;
	}
	//�����x�̃Q�b�^�[�B
	int GetHUN()
	{
		return HUN;
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
	AnimationClip m_animationClips[3];					//�A�j���[�V�����N���b�v�B
	CVector3 m_position = CVector3::Zero();				//���W�B
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CVector3 m_moveSpeed = CVector3::Zero();			//�ړ����x�B
	CVector3 enpo;										//NPC��Player�̋����B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B	
	CharacterController m_charaCon;						//�L�����N�^�[�R���g���[���[��ǉ��B
	Font m_font;										////�����\���̃C���X�^���X�B
};

