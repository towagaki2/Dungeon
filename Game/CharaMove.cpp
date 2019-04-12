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
	m_moveSpeed = CVector3::Zero();
	plpo = Game::GetGame().GetPlayer()->GetPosition() - epos;
	if (Game::GetGame().GetPhase()->GetTaan() == 1) {
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
		m_moveSpeed.x = plpo.x;
		m_moveSpeed.z = plpo.z;
		//ˆÚ“®‚ÌŒvŽZ‚ð•Ô‚·B
	}
	return m_moveSpeed;
}
