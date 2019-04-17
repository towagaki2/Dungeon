#pragma once
#include "character/CharacterController.h"


class CharaMove
{
public:
	CharaMove();
	~CharaMove();
	
	
	
	CVector3 EneMove(CVector3 epos);				//�G�l�~�[�̈ړ������B
	CQuaternion EneTurn();							//�G�l�~�[�̉�]�����B

private:
	CVector3 m_moveSpeed = CVector3::Zero();		//�ړ����x�B
	CVector3 plpo;                                  //NPC��Player�̋����B
};

