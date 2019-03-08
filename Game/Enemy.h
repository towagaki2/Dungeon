#pragma once
#include "character/CharacterController.h"
#include "Phase.h"
#include "CharaMove.h"
class Enemy
{
public:
	Enemy();
	~Enemy();
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
	//�G�l�~�[�̈ړ��̃t���O
	int GetEnemoveF()
	{
		return moveF;
	}
	//�G�l�~�[�̍U���̃t���O
	int GetEneatttackF()
	{
		return atttackF;
	}
	//�G�l�~�[�̑ҋ@�̃t���O
	int GetEnestandF()
	{
		return standF;
	}

private:
	void Move();		//�ړ������B
	void Turn();		//��]�����@

	Phase phase;			//�^�[������B
	CharaMove enemyMove;		//�ړ�����B

	int moveF = 0;			//�ړ��t���O�B	
	int atttackF = 0;		//�U���t���O�B
	int standF = 0;			//�ҋ@�t���O�B

	SkinModel m_model;									//�X�L�����f���B
	Animation m_animation;								//�A�j���[�V�����B
	AnimationClip m_animationClips[2];					//�A�j���[�V�����N���b�v�B
	CVector3 m_position = CVector3::Zero();				//���W�B
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CVector3 m_moveSpeed = CVector3::Zero();			//�ړ����x�B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B								
	CharacterController m_charaCon;			//�L�����N�^�[�R���g���[���[��ǉ��B

};

