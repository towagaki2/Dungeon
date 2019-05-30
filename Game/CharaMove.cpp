#include "stdafx.h"
#include "CharaMove.h"
#include "Game.h"


CharaMove::CharaMove()
{
}


CharaMove::~CharaMove()
{
}

CVector3 CharaMove::EneMove(CVector3 epos)
{
	//m_moveSpeedの初期化。

	m_moveSpeed = CVector3::Zero();
	//エネミーからプレイヤーまでの距離。
	plpo = Game::GetGame().GetPlayer()->GetPosition() - epos;
	//エネミーの移動処理。
	if (Game::GetGame().GetPhase()->GetTaan() == 1) {
		//if(masu*)
		plpo.Normalize();
		if (plpo.x  > 0.001f) 
		{
			plpo.x = 1;
		}
		if (plpo.z > 0.001f)
		{
			plpo.z = 1;
		}
		if (plpo.x < -0.001f)
		{
			plpo.x = -1;
		}
		if (plpo.z < -0.001f)
		{
			plpo.z = -1;
		}
		//移動方向の代入。
		m_moveSpeed.x = plpo.x;
		m_moveSpeed.z = plpo.z;
		//移動の計算を返す。
	}
	return m_moveSpeed;
}
