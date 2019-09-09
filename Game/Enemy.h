#pragma once
#include "character/CharacterController.h"
#include "CharaMove.h"
#include"GameDefine.h"
#include "CharaDeta.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
class Enemy :public CharaDeta
{
public:
	Enemy(int HP, int ATK,int DEF);
	virtual ~Enemy();
	void Update();
	void Draw();


	void RoomIn(std::vector<CharaDeta*> date)
	{
		for (int i = 0; i < date.size(); i++) {
			if (date[i]->GetType() == player)
			{
				enemyMove.Setjoutai(CharaMove::osou);
				break;
			}
		}
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

	//�G�l�~�[HP�̃Q�b�^�[�B
	int GetenHP()
	{
		return enHP;
	}
	//�G�l�~�[HP�̃Z�b�^�[�B
	void SetenHP(CVector3 pos, int enenHP)
	{
		if ((pos - m_position).Length()<=masu*1.6) {
			enHP += enenHP;
		}
	}
	//�G�l�~�[DEF�̃Q�b�^�[�B
	int GetenDEF()
	{
		return enDEF;
	}
	/// <summary>
	/// �G�l�~�[�̃t���O�����̃Q�b�^�[�B
	/// </summary>
	/// <returns></returns>
	bool GetEneSummaryF()
	{
		return summaryF;
	}
	bool GetEneAttackF()
	{
		return attackF;
	}
	int Getnumber()
	{
		return enemynamber;
	}
	bool GetdeathF()
	{
		return deathF;
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
	void Move();				//�ړ������B
	void Turn();				//��]�����B

	int enemynamber = 10;		//�G�l�~�[�̑����B

	CharaMove enemyMove;		//�ړ�����B

	bool moveF = false;			//�ړ��t���O�B	
	bool attackF = false;		//�U���t���O�B
	bool standF = false;		//�ҋ@�t���O�B
	bool summaryF = false;		//�t���O�̑����B
	bool deathF = false;		//���S�t���O�B�@�@�@�����̐킢���I�������E�E�E�E

	int FrameCounter = 0;		//�t���[���̃J�E���^�[�B
	int enHP = 10;				//�̗͒l�B
	int enATK = 7;				//�U���́B
	int enDEF = 5;				//�h��́B

	CSoundSource m_AtkSE;								//�U��SE�B
	SkinModel m_model;									//�X�L�����f���B
	Animation m_animation;								//�A�j���[�V�����B
	AnimationClip m_animationClips[5];					//�A�j���[�V�����N���b�v�B
	CVector3 m_position = {masu*10.0f,0.0f,masu*5.0f};	//���W�B
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CVector3 m_moveSpeed = CVector3::Zero();			//�ړ����x�B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B								
	
};

