#include "stdafx.h"
#include "Enemy.h"
#include "Game.h"


Enemy::Enemy()
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

	m_charaCon.Init(25.0f, 50.0f, m_position); 
	enemyMove.Getpos(m_position);
	m_position = { 10.0f,0.0f,0.0f };
}

Enemy::~Enemy()
{
}

void Enemy::Move()
{
	//�ړ������B
	enemyMove.Getpos(m_position);
	m_moveSpeed = enemyMove.EneMove();
	m_moveSpeed *= 100.0f;
	m_position += m_moveSpeed;
	m_position = m_charaCon.Execute(1.0f / 30.0f, m_moveSpeed);
	//�U�������B

	if (moveF == 1 || attackF == 1 || standF == 1)
	{
		summaryF = 1;
		moveF = 0;
		attackF = 0;
		standF = 0;
	}
}

void Enemy::Turn()
{

}

void Enemy::Update()
{

	//�ړ������B
	Move();
	//��]����
	Turn();

	//���[���h�s��̍X�V�B
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);

}

void Enemy::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}