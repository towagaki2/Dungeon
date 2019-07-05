#include "stdafx.h"
#include "Game.h"
#include "GameEnd.h"
#include "UI.h"



Game::Game()
{
	title = new Title;

	//�T�E���h�G���W�����������B
	m_soundEngine.Init();

	//BGM
	m_bgm.Init(L"Assets/music/game_maoudamashii_6_dangeon03.wav");
	m_bgm.Play(true);
}


Game::~Game()
{
	
}

void Game::StartGame()
{
	background = new BackGround;
	stairs = new Stairs;
	player = new Player;
	enemyManager = new EnemyManager;
	phase = new Phase;
	rogueLikeMap = new RogueLikeMap;
	delete title;
}

void Game::EndGame()
{
	delete player;
	delete enemyManager;
	delete background;
	delete phase;
	delete ui;
	delete stairs;
	ui = nullptr;
	title = new Title;
}

void Game::Update()
{
	if (title == nullptr)
	{
		if (ui == nullptr)
		{
				
			//�����G���W���̍X�V�B
			g_physics.Update();
			//�T�E���h�G���W�����X�V�B
			m_soundEngine.Update();
			//�v���C���[�̍X�V�B
			player->Update();
			//�G�l�~�[�}�l�[�W���[�̍X�V�B
			enemyManager->Update();
			//�K�i�̍X�V�B
			stairs->Update();
			//�o�b�N�O�����h�̍X�V�B
			background->Update();
			//�^�[���̍X�V�B
			phase->Update();

			PlayerPos = Game::GetGame().GetPlayer()->GetPosition();
			g_camera3D.SetPosition({ PlayerPos.x + 10.0f,600.0f, PlayerPos.z - 300.0f });
			g_camera3D.SetTarget({ PlayerPos.x + 10.0f,0.0f, PlayerPos.z + 10.1f });

			//�J�����̍X�V�B
			g_camera3D.Update();
			if (Game::GetGame().GetPlayer()->GetplHP() <= 0)
			{
				ui = new UI(false);
			}

			if (stairs->GetStairsF() == true)
			{
				ui = new UI(true);
			}
			
		}

	}
	else {
		title->Update();
		title->Draw();
	}

}


void Game::Draw()
{
	if (title != nullptr) {
		if (title->GetTitleF() == true) {
			StartGame();
			title = nullptr;
		}
	}
	else {		
		//�o�b�N�O�����h�̕`��B
		background->Draw();
		//�K�i�̕`��B
		stairs->Draw();
		//�v���C���[�̕`��B
		player->Draw();
		//�G�l�~�[�̕`��B
		enemyManager->Draw();
		if (ui != nullptr) {
			ui->Update();
		}
	}

}