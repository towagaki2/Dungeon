#include "stdafx.h"
#include "Game.h"
#include "GameEnd.h"
#include "UI.h"



Game::Game()
{
	title = new Title;

	//サウンドエンジンを初期化。
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
	phase = new Phase;
	rogueLikeMap = new RogueLikeMap;
	enemyManager = new EnemyManager;
	player = new Player;
	if (title != nullptr) {
		delete title;
	}
}

void Game::EndAndStrat()
{
	delete enemyManager;
	delete background;
	delete rogueLikeMap;
	delete phase;
	delete stairs;
	background = new BackGround;
	stairs = new Stairs;
	phase = new Phase;
	rogueLikeMap = new RogueLikeMap;
	enemyManager = new EnemyManager;
	player->NewPos();
	
}

void Game::EndGame()
{
	
		delete player;
		delete enemyManager;
		delete background;
		delete rogueLikeMap;
		delete phase;
		delete ui;
		delete stairs;
		ui = nullptr;
		title = new Title;
		kai = 0;
}

void Game::Update()
{
	if (title == nullptr)
	{
		if (ui == nullptr)
		{
				
			//物理エンジンの更新。
			g_physics.Update();
			//プレイヤーの更新。
			player->Update();
			//エネミーマネージャーの更新。
			enemyManager->Update();
			//階段の更新。
			stairs->Update();
			//バックグランドの更新。
			background->Update();
			//ターンの更新。
			phase->Update();

			PlayerPos = Game::GetGame().GetPlayer()->GetPosition();
			g_camera3D.SetPosition({ PlayerPos.x + 10.0f,600.0f, PlayerPos.z - 300.0f });
			g_camera3D.SetTarget({ PlayerPos.x + 10.0f,0.0f, PlayerPos.z + 10.1f });

			//カメラの更新。
			g_camera3D.Update();
			//サウンドエンジンを更新。
			m_soundEngine.Update();
			if (Game::GetGame().GetPlayer()->GetplHP() <= 0)
			{
				ui = new UI(false);
			}

			if (stairs->GetStairsF() == true)
			{
				if (kai >= Last) {
					ui = new UI(true);
				}else
				{
					kai++;
					EndAndStrat();
				}

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
		//バックグランドの描画。
		background->Draw();
		//階段の描画。
		stairs->Draw();
		//プレイヤーの描画。
		player->Draw();
		//エネミーの描画。
		enemyManager->Draw();
		if (ui != nullptr) {
			ui->Update();
		}
	}

}