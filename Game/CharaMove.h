#pragma once
#include "character/CharacterController.h"


class CharaMove
{
public:
	CharaMove();
	~CharaMove();
	
	void Getpos(const CVector3 EnMoPos)
	{
		m_position = EnMoPos;
	}
	
	CVector3 EneMove();
	CQuaternion EneTurn();

private:
	CVector3 m_position = CVector3::Zero();			//���W�B
	CVector3 m_moveSpeed = CVector3::Zero();		//�ړ����x�B
	CVector3 plpo;                                  //NPC��Player�̋����B
};

