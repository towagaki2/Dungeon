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

private:
	CVector3 m_position = CVector3::Zero();			//���W�B
	CVector3 m_moveSpeed = CVector3::Zero();		//�ړ����x�B
	

	int timerX = 0;			//�σ^�C�}�[X���B
	int timerZ = 0;			//�σ^�C�}�[Z���B
	int MoveDirection = 1;		//�ړ������B
	int randomX = 1;		//X�������B
	int randomZ = 1;		//Z�������B
};

