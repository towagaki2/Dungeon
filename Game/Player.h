#pragma once
#include "character/CharacterController.h"
#include "font.h"
#include "CharaDeta.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

class Font;

class Player:public CharaDeta
{
public:
	Player();
	~Player();
	void PlStatus();
	void Update();
	void Draw();
	void NewPos();
	void RoomIn(std::vector<CharaDeta*> date)
	{

	}
	//�v���C���[��HP�̃Q�b�^�[�B
	int GetplHP()
	{
		return plHP;
	}
	//�v���C���[��HP�̃Z�b�^�[�B
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
	bool GetPlSummaryF()
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
	//�o���l�̃Z�b�^�[�B
	void SetEXP(int SetExp)
	{
		EXP += SetExp;
	}

	int pltate = 0;
	int plyoko = 0;

private:

	int LV = 1;				//���x���B
	int EXP = 0;			//�o���l�B
	int exp = 10;			//���x���A�b�v����̂ɂ���o���l�B
	int plMaxHP = 10;		//�ő�HP�B
	int plHP = plMaxHP;		//���݂�HP�B
	int plMaxMP = 5;		//�ő�MP�B
	int plMP = plMaxMP;		//���݂�MP�B
	int iniATK = 10;		//�����U���́B
	int plATK = iniATK;		//���݂̍U���́B
	int iniDEF = 50;		//�����h��́B
	int plDEF = iniDEF;		//���݂̖h��́B
	int HUN = 100000;		//�����x�B


	void Move();			//�ړ������B
	void Turn();			//��]�����B�@

	bool moveF = false;			//�ړ��t���O�B	
	bool attackF = false;		//�U���t���O�B
	bool standF = false;			//�ҋ@�t���O�B
	bool summaryF = false;		//�t���O�̑����B
	bool RB1F = false;		//RB1�����Ă邩�̃t���O�B



	CSoundEngine m_soundEngine;							//�T�E���h�G���W���B
	CSoundSource m_MoveSE;								//�ړ�SE�B
	CSoundSource m_AtkSE;								//�U��SE�B
	CSoundSource m_CureSE;								//��SE�B
	SkinModel m_model;									//�X�L�����f���B
	Animation m_animation;								//�A�j���[�V�����B
	AnimationClip m_animationClips[3];					//�A�j���[�V�����N���b�v�B
	CVector3 m_position = CVector3::Zero();				//���W�B
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CVector3 m_moveSpeed = CVector3::Zero();			//�ړ����x�B
	CVector3 enpo;										//NPC��Player�̋����B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B	
	Font m_font;										//�����\���̃C���X�^���X�B
};

