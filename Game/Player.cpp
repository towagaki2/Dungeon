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

	
	m_position = Game::GetGame().GetBackGround()->GetMapPosition(pltate,plyoko);
	
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
	CVector3 enpo = { 1000000.0f,10000000.0f,0.0f };
	for (int i = 0; i < 10; i++) {
		if (Game::GetGame().GetEnemy(i) != nullptr) {
			enpo = Game::GetGame().GetEnemy(i)->GetPosition() - m_position;
		}
	}
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
		//�i�ޕ������ǂ���Ȃ��Ȃ�i�ށB
		//�ǂȂ�ړ������^�[���͐i�܂Ȃ��B
		if (!Game::GetGame().GetBackGround()->GetKabeOrYuka(pltate+ ZF,plyoko+XF))
		{
			pltate += ZF;
			plyoko += XF;
			m_moveSpeed.z = ZF * masu;
			m_moveSpeed.x = XF * masu;
			m_position += m_moveSpeed;
		}
		else
		{
			moveF = false;
		}
		
		//�d��(���񂢂�Ȃ�)
		//m_moveSpeed.y -= 980.0f * (1.0f / 30.0f);
		
		//�U�������B
		if (g_pad[0].IsTrigger(enButtonA)&&RB1F == false)
		{
			m_animation.Play(2);
			for (int i = 0; i < teki; i++) {
				
				if (Game::GetGame().GetEnemy(i) != nullptr) {
					Game::GetGame().GetEnemy(i)->SetenHP(m_position, Game::GetGame().GetEnemy(i)->GetenDEF() - plATK);
				}
			}
			attackF = true;
		}
		if (g_pad[0].IsPress(enButtonRB1) == true)
		{
			RB1F = true;
			//�z�C�~�[�B
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
		if (EXP >= exp)
		{
			LV++;
			exp += 10;
			//�X�e�[�^�X�A�b�v�B
			plMaxHP += 5;
			plMaxMP += 5;
			plATK += 5 ;
			plDEF += 5;
			//���x���A�b�v�ɂ��񕜁B
			plHP = plMaxHP;
			plMP = plMaxMP;
			HUN = 100;
		}
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