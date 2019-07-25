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
	
	CVector3 EneMove(CVector3 epos,Enemy* enemy);				//エネミーの移動処理。
	CQuaternion EneTurn();										//エネミーの回転処理。
	int chatate = 0;
	int chayoko = 0;
	
	void Setjoutai(joutai osou)
	{
		kinmu = osou;
	}

private:

	joutai kinmu = tansa;

	CVector3 tansak = CVector3::Zero();				//探索の移動。
	CVector3 m_moveSpeed = CVector3::Zero();		//移動速度。
	CVector3 plpo = CVector3::Zero();               //NPCとPlayerの距離。
};

