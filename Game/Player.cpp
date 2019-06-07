#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include"GameDefine.h"
#include "GameEnd.h"

Player::Player()
{

	//cmo�t�@�C���̓ǂݍ��݁B
	m_model.Init(L"Assets/modelData/player1fbx.cmo");

	//tka�t�@�C���̓ǂݍ��݁B
	m_animationClips[0].Load(L"Assets/animData/pla_idle.tka");
	m_animationClips[0].SetLoopFlag(true);

	m_animationClips[1].Load(L"Assets/animData/pla_run.tka");
	m_animationClips[1].SetLoopFlag(true);

	m_animationClips[2].Load(L"Assets/animData/pla_hit.tka");
	m_animationClips[2].SetLoopFlag(false);
	//�A�j���[�V�����̏������B
	m_animation.Init(
		m_model,			//�A�j���[�V�����𗬂��X�L�����f���B
							//����ŃA�j���[�V�����ƃX�L�����f�����֘A�t�������B
		m_animationClips,	//�A�j���[�V�����N���b�v�̔z��B
		3					//�A�j���[�V�����N���b�v�̐��B
	);

	m_charaCon.Init(10.0f, 50.0f, m_position);
	std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
	std::mt19937 Rand(rnd());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
	std::uniform_int_distribution<> GetRand(0, 1000);        // [0, 99] �͈͂̈�l����

	m_position = Game::GetGame().GetBackGround()->GetMapPosition();
	m_position.y = 50.0f;
}

Player::~Player()
{
}

void Player::PlStatus()
{
	plHP;
	HUN;

}

void Player::Move()
{
	auto enpo = Game::GetGame().GetEnemy()->GetPosition() - m_position;
	if (Game::GetGame().GetPhase()->GetTaan() == Phase::plTaan) {

		//�ړ������B
		float XF = 0;
		float ZF = 0;
		//�\���L�[�����������B
		if (g_pad[0].IsTrigger(enButtonUp))
		{
			ZF = 1;
			moveF = true;
		}
		//�\���L�[������������B
		if (g_pad[0].IsTrigger(enButtonDown))
		{
			ZF = -1;
			moveF = true;
		}
		//�\���L�[������������B
		if (g_pad[0].IsTrigger(enButtonLeft))
		{
			XF = -1;
			moveF = true;
		}
		//�\���L�[�E����������B
		if (g_pad[0].IsTrigger(enButtonRight))
		{
			XF = 1;
			moveF = true;
		}
		m_moveSpeed.z = ZF * masu;
		m_moveSpeed.x = XF * masu;
		m_position += m_moveSpeed;

		//�d��(���񂢂�Ȃ�)
		//m_moveSpeed.y -= 980.0f * (1.0f / 30.0f);

		
		//�U�������B
		if (g_pad[0].IsTrigger(enButtonA)&&RB1F == false)
		{
			m_animation.Play(2);
			if (masu*1.6 > enpo.Length())
			{
				Game::GetGame().GetEnemy() ->SetenHP(Game::GetGame().GetEnemy()->GetenDEF() - plATK);
			}
			
			attackF = true;
		}
		if (g_pad[0].IsPress(enButtonRB1) == true)
		{
			RB1F = true;
			//�񕜖��@�B
			if (g_pad[0].IsTrigger(enButtonA)&&RB1F == true)
			{
				if (plMP > 2) {
					plHP += 6;
					plMP -= 2;
					if (plMaxHP < plHP)
					{
						plHP = plMaxHP;
					}
				}
				attackF = true;
			}
		}
		else
		{
			RB1F = false;
		}
		//�ҋ@�����B
		if (g_pad[0].IsTrigger(enButtonX))
		{
			standF = true;
		}
		if (moveF == true)
		{
			m_animation.Play(1);
		}
		else
		{
			m_animation.Play(0);
		}
		if (moveF == true || attackF == true || standF == true)
		{

			summaryF = true;
			moveF = false;
			attackF = false;
			standF = false;
			
		}	
	}
}

void Player::Turn()
{

}
void Player::Update()
{
		//�v���C���[�̃X�e�[�^�X�����B
		PlStatus();
		//�ړ������B
		Move();
		//��]����
		Turn();
		//�A�j���[�V�����̍X�V�B
		m_animation.Update(1.0f / 30.0f);
		////���[���h�s��̍X�V�B
		m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale*1.0);
}

void Player::Draw()
{

	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);

	m_font.BeginDraw();	//�t�H���g�̕`��J�n�B
	wchar_t toubatu[256];
	swprintf_s(toubatu, L"HP�F%d/%d", plHP,plMaxHP);	//HP��\������B
	m_font.Draw(
		toubatu,		//�\�����镶����B
		{ -300.0f,300.0f },			//�\��������W�B0.0f, 0.0����ʂ̒��S�B
		{ 0.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
	);

	swprintf_s(toubatu, L"�󕠓x�F%d", HUN);	//�󕠓x��\������B
	m_font.Draw(
		toubatu,		//�\�����镶����B
		{ 300.0f,300.0f },			//�\��������W�B0.0f, 0.0����ʂ̒��S�B
		{ 0.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
	);
	swprintf_s(toubatu, L"MP�F%d/%d", plMP,plMaxMP);	//MP��\������B
	m_font.Draw(
		toubatu,		//�\�����镶����B
		{ 0.0f,300.0f },			//�\��������W�B0.0f, 0.0����ʂ̒��S�B
		{ 0.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
	);
	swprintf_s(toubatu, L"LV�F%d", LV);	//LV��\������B
	m_font.Draw(
		toubatu,		//�\�����镶����B
		{ -600.0f,300.0f },			//�\��������W�B0.0f, 0.0����ʂ̒��S�B
		{ 0.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
	);
	m_font.EndDraw();		//�t�H���g�̕`��I���B
}