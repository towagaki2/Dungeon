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
	//m_moveSpeed�̏������B
	m_moveSpeed = CVector3::Zero();
	//�G�l�~�[����v���C���[�܂ł̋����B
	plpo = Game::GetGame().GetPlayer()->GetPosition() - epos;
	//�G�l�~�[�̈ړ������B
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
			//�ړ������̑���B
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
				//�ړ������̑���B
				m_moveSpeed.x = plpo.x;
				m_moveSpeed.z = plpo.z;
			}
		}
		//�ړ��̌v�Z��Ԃ��B
	}
	return m_moveSpeed;
}
