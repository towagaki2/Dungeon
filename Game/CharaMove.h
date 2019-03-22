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
	CVector3 m_position = CVector3::Zero();			//座標。
	CVector3 m_moveSpeed = CVector3::Zero();		//移動速度。
	

	int timerX = 0;			//可変タイマーX軸。
	int timerZ = 0;			//可変タイマーZ軸。
	int MoveDirection = 1;		//移動方向。
	int randomX = 1;		//X軸乱数。
	int randomZ = 1;		//Z軸乱数。
};

