#include "stdafx.h"
#include "Player.h"
#include "Game.h"


Player::Player()
{
	
	//cmo�t�@�C���̓ǂݍ��݁B
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	//tka�t�@�C���̓ǂݍ��݁B
	m_animationClips[0].Load(L"Assets/animData/walk.tka");
	m_animationClips[0].SetLoopFlag(true);

	m_animationClips[1].Load(L"Assets/animData/run.tka");
	m_animationClips[1].SetLoopFlag(true);
	//�A�j���[�V�����̏������B
	m_animation.Init(
		m_model,			//�A�j���[�V�����𗬂��X�L�����f���B
							//����ŃA�j���[�V�����ƃX�L�����f�����֘A�t�������B
		m_animationClips,	//�A�j���[�V�����N���b�v�̔z��B
		2					//�A�j���[�V�����N���b�v�̐��B
	);

	m_position.y = 0.0f;
	m_charaCon.Init(10.0f, 50.0f, m_position);


}


Player::~Player()
{
}

void Player::PlStatus()
{
	HP;
	HUN;
}

void Player::Move()
{

	if (Game::GetGame().GetPhase()->GetTaan() == Phase::plTaan) {

		//�ړ������B
		float XF = 0;
		float ZF = 0;
		if (g_pad[0].IsTrigger(enButtonUp))
		{
			ZF = 1;
			moveF = 1;
		}
		if (g_pad[0].IsTrigger(enButtonDown))
		{
			ZF = -1;
			moveF = 1;
		}
		if (g_pad[0].IsTrigger(enButtonLeft))
		{
			XF = -1;
			moveF = 1;
		}
		if (g_pad[0].IsTrigger(enButtonRight))
		{
			XF = 1;
			moveF = 1;
		}
		m_moveSpeed.z = ZF * 1000.0f;
		m_moveSpeed.x = XF * 1000.0f;
		m_position = m_charaCon.Execute(1.0f / 30.0f, m_moveSpeed);

		//m_moveSpeed.y -= 980.0f * (1.0f / 30.0f);

		//�U�������B
		if (g_pad[0].IsTrigger(enButtonA))
		{
			if (m_Length > enpo.Length())
			{

			}
			attackF = 1;
		}
		//�ҋ@�����B
		if (g_pad[0].IsTrigger(enButtonX))
		{
			standF = 1;
		}
		if (moveF == 1 || attackF == 1 || standF == 1)
		{
			summaryF = 1;
			moveF = 0;
			attackF = 0;
			standF = 0;
		}
		
	}

	CVector3 cameraForward = g_camera3D.GetForward();
	CVector3 cameraRight = g_camera3D.GetRight();
	//XZ���ʂł̑O�������A�E�����ɕϊ�����B
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	cameraRight.y = 0.0f;
	cameraRight.Normalize();
}

void Player::Turn()
{

}
void Player::Update()
{
	//�X�e�[�^�X�����B
	PlStatus();
	//�ړ������B
	Move();
	//��]����
	Turn();

	//���[���h�s��̍X�V�B
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);

}

void Player::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}