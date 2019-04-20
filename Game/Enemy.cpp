#include "stdafx.h"
#include "Enemy.h"
#include "Game.h"
#include "GameEnd.h"


Enemy::Enemy()
{
	//cmo�t�@�C���̓ǂݍ��݁B
	m_model.Init(L"Assets/modelData/Skeleton@Skin.cmo");

	//tka�t�@�C���̓ǂݍ��݁B
	m_animationClips[0].Load(L"Assets/animData/SkeletonIDLE.tka");		//�ҋ@�A�j���[�V�����B
	m_animationClips[0].SetLoopFlag(true);

	m_animationClips[1].Load(L"Assets/animData/SkeletonWALK.tka");		//�����A�j���[�V�����B
	m_animationClips[1].SetLoopFlag(true);

	m_animationClips[2].Load(L"Assets/animData/SkeletonATK.tka");		//�U���A�j���[�V�����B
	m_animationClips[2].SetLoopFlag(true);

	m_animationClips[3].Load(L"Assets/animData/SkeletonDEATH.tka");		//���S�A�j���[�V�����B
	m_animationClips[3].SetLoopFlag(true);

	m_animationClips[4].Load(L"Assets/animData/SkeletonDAMAGE.tka");		//�_���[�W�A�j���[�V�����B
	m_animationClips[4].SetLoopFlag(true);
	//�A�j���[�V�����̏������B
	m_animation.Init(
		m_model,			//�A�j���[�V�����𗬂��X�L�����f���B
							//����ŃA�j���[�V�����ƃX�L�����f�����֘A�t�������B
		m_animationClips,	//�A�j���[�V�����N���b�v�̔z��B
		5					//�A�j���[�V�����N���b�v�̐��B
	);

	m_charaCon.Init(25.0f, 50.0f, m_position); 
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
}

Enemy::~Enemy()
{
}

void Enemy::EnStatus()
{
	enHP;

}

void Enemy::Move()
{		
	if (Game::GetGame().GetPhase()->GetTaan() == Phase::enTaan) { 
		FrameCounter++;
		if (FrameCounter > 15) {
			//���ꏈ��


			auto move = Game::GetGame().GetPlayer()->GetPosition() - m_position;
				//�U������
			if (masu*1.3 > move.Length())
			{
				Game::GetGame().GetPlayer()->SetplHP(Game::GetGame().GetPlayer()->GetplDEF() - enATK);
				attackF = 1;
			}
			if (attackF == 1)
			{
				m_animation.Play(2);
			}
			else
				//�ړ�����
			{
				m_moveSpeed = enemyMove.EneMove(m_position);
				m_moveSpeed *= masu;
				m_position += m_moveSpeed;
				moveF = 1;

				if (moveF == 1)
				{
					m_animation.Play(1);
				}
				else
				{
					m_animation.Play(0);
				}

			}		
			if (moveF == 1 || attackF == 1 || standF == 1)
			{
				summaryF = 1;
				moveF = 0;
				attackF = 0;
				standF = 0;
				FrameCounter = 0;
			}
		}
	}
}

void Enemy::Turn()
{

}

void Enemy::Update()
{
		//�G�l�~�[�̃X�e�[�^�X�����B
		EnStatus();
		//�ړ������B
		Move();
		//��]����
		Turn();
		//�A�j���[�V�����̍X�V�B
		m_animation.Update(1.0f / 30.0f);

	//���[���h�s��̍X�V�B
		m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale * 8);
	
}

void Enemy::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}