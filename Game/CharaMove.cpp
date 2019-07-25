#include "stdafx.h"
#include "CharaMove.h"
#include "Game.h"
#include"Enemy.h"

CharaMove::CharaMove()
{
}


CharaMove::~CharaMove()
{
}

CVector3 CharaMove::EneMove(CVector3 epos,Enemy* enemy)
{
	//m_moveSpeedの初期化。
	m_moveSpeed = CVector3::Zero();
	//エネミーからプレイヤーまでの距離。
	plpo = Game::GetGame().GetPlayer()->GetPosition() - epos;
	//エネミーの移動処理。
	switch (kinmu)
	{
	case CharaMove::tansa:
		/*if (masu*5.0f > plpo.Length())
		{
			kinmu = osou;
		}*/
		break;
	case CharaMove::osou:
		//if (masu*5.0f < plpo.Length())
		//{
		//	kinmu = tansa;
		//}
		break;
	}
	if (kinmu == tansa)
	{


		if (!Game::GetGame().GetBackGround()->GetKabeOrYuka(chatate + tansak.z, chayoko + tansak.x, enemy))
		{
			chatate += tansak.z;
			chayoko += tansak.x;
			//移動方向の代入。
			m_moveSpeed.x = tansak.x;
			m_moveSpeed.z = tansak.z;
		}
	}
	if (kinmu == osou)
	{ 
		if (Game::GetGame().GetPhase()->GetTaan() == 1) {
			plpo.Normalize();
			if (plpo.x > 0.001f)
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
			if (!Game::GetGame().GetBackGround()->GetKabeOrYuka(chatate + plpo.z, chayoko + plpo.x, enemy))
			{
				chatate += plpo.z;
				chayoko += plpo.x;
				//移動方向の代入。
				m_moveSpeed.x = plpo.x;
				m_moveSpeed.z = plpo.z;
			}
		}
		//移動の計算を返す。
	}
	return m_moveSpeed;
}
