#include "stdafx.h"
#include "CharaMove.h"
#include "Game.h"


CharaMove::CharaMove()
{
}


CharaMove::~CharaMove()
{
}

CVector3 CharaMove::EneMove()
{
	m_moveSpeed = CVector3::Zero();
	plpo = Game::GetGame().GetPlayer()->GetPosition() - m_position;
	if (Game::GetGame().GetPhase()->GetTaan() == 1) {
		plpo.Normalize();
		m_moveSpeed.x = plpo.x;
		m_moveSpeed.z = plpo.z;
		//ˆÚ“®‚ÌŒvZ‚ğ•Ô‚·B
	}
	return m_moveSpeed;
}
