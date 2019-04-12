#pragma once
#include "character/CharacterController.h"


class CharaMove
{
public:
	CharaMove();
	~CharaMove();
	
	
	
	CVector3 EneMove(CVector3 epos);
	CQuaternion EneTurn();

private:
	CVector3 m_moveSpeed = CVector3::Zero();		//移動速度。
	CVector3 plpo;                                  //NPCとPlayerの距離。
};

