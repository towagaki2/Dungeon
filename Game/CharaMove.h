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
	CVector3 m_position = CVector3::Zero();			//座標。
	CVector3 m_moveSpeed = CVector3::Zero();		//移動速度。
	CVector3 plpo;                                  //NPCとPlayerの距離。
};

