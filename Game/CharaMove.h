#pragma once
#include "character/CharacterController.h"
class Enemy;

class CharaMove
{
public:
	CharaMove();
	~CharaMove();
	
	enum joutai
	{
		tansa,
		osou,

	};
	
	CVector3 EneMove(CVector3 epos,Enemy* enemy);				//�G�l�~�[�̈ړ������B
	CQuaternion EneTurn();										//�G�l�~�[�̉�]�����B
	int chatate = 0;
	int chayoko = 0;
	
	void Setjoutai(joutai osou)
	{
		kinmu = osou;
	}

private:

	joutai kinmu = tansa;

	CVector3 tansak = CVector3::Zero();				//�T���̈ړ��B
	CVector3 m_moveSpeed = CVector3::Zero();		//�ړ����x�B
	CVector3 plpo = CVector3::Zero();               //NPC��Player�̋����B
};

