#include "stdafx.h"
#include "Game.h"
#include "GameEnd.h"
#include "UI.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::Update()
{
	if (ui== nullptr)
	{


		//�����G���W���̍X�V�B
		g_physics.Update();
		//�v���C���[�̍X�V�B
		player.Update();
		//�G�l�~�[�̍X�V�B
		enemy.Update();
		//�o�b�N�O�����h�̍X�V�B
		background.Update();
		//�^�[���̍X�V�B
		phase.Update();
		//�Q�[���G���h�̍X�V�B


		PlayerPos = Game::GetGame().GetPlayer()->GetPosition();
		g_camera3D.SetPosition({ PlayerPos.x + 10.0f,800.0f, PlayerPos.z + 10.0f });
		g_camera3D.SetTarget({ PlayerPos.x + 10.0f,0.0f, PlayerPos.z + 10.1f });
		//�J�����̍X�V�B
		g_camera3D.Update();
		if (Game::GetGame().GetPlayer()->GetplHP() <= 0)
		{
			ui = new UI(false);
		}
		if (Game::GetGame().GetEnemy()->GetenHP() <= 0)
		{
			ui = new UI(true);
		}
	}
}

void Game::Draw()
{
	//�o�b�N�O�����h�̕`��B
	background.Draw();
	//�v���C���[�̕`��B
	player.Draw();
	//�G�l�~�[�̕`��B
	enemy.Draw();
	if(ui != nullptr) {
		ui->Update();
	}
}