#include "stdafx.h"
#include "Player.h"
#include "Enemy.h"
#include "Phase.h"

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

void Player::Move()
{
	if (phase.GetTaan() == 0) {
		float lStickXF = g_pad[0].GetLStickXF();
		float lStickYF = g_pad[0].GetLStickYF();
		CVector3 cameraForward = g_camera3D.GetForward();
		CVector3 cameraRight = g_camera3D.GetRight();
		//XZ���ʂł̑O�������A�E�����ɕϊ�����B
		cameraForward.y = 0.0f;
		cameraForward.Normalize();
		cameraRight.y = 0.0f;
		cameraRight.Normalize();

		m_moveSpeed.y -= 980.0f * (1.0f / 60.0f);
		//�v���C���[�̈ړ������B
		if (phase.GetTaan() == 0) {
			m_moveSpeed.z = lStickYF * 1000.0f;	//�c�����ւ̈ړ����x�����B
			m_moveSpeed.x = lStickXF * 1000.0f;		//�������ւ̈ړ����x�����Z�B
		}
		m_position = m_charaCon.Execute(1.0f / 30.0f, m_moveSpeed);
	}
}

void Player::Turn()
{

}

void Player::Update()
{
	
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