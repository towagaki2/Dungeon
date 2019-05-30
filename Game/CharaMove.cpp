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
	//m_moveSpeed�̏������B

	m_moveSpeed = CVector3::Zero();
	//�G�l�~�[����v���C���[�܂ł̋����B
	plpo = Game::GetGame().GetPlayer()->GetPosition() - epos;
	//�G�l�~�[�̈ړ������B
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
		//�ړ������̑���B
		m_moveSpeed.x = plpo.x;
		m_moveSpeed.z = plpo.z;
		//�ړ��̌v�Z��Ԃ��B
	}
	return m_moveSpeed;
}
