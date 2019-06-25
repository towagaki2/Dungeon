#include "stdafx.h"
#include "Game.h"
#include "GameEnd.h"
#include "UI.h"



Game::Game()
{
	title = new Title;
}


Game::~Game()
{
	
}

void Game::StartGame()
{
	background = new BackGround;
	stairs = new Stairs;
	player = new Player;
	enemy[0] = new Enemy(7,7,5);
	enemy[1] = new HorrorMan(7,7,5);
	enemyManager = new EnemyManager;
	phase = new Phase;
	rogueLikeMap = new RogueLikeMap;
	delete title;
}

void Game::EndGame()
{
	delete player;
	for (int i = 0; i < 2; i++) {
		delete enemy[i];
	}
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

			//物理エンジンの更新。
			g_physics.Update();
			//プレイヤーの更新。
			player->Update();
			//エネミーの更新。
			enemy[1]->Update();
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
			if (Game::GetGame().GetPlayer()->GetplHP() <= 0)
			{
				ui = new UI(false);
			}
			if (stairs->GetStairsF() == true)
			{
				ui = new UI(true);
			}
				if (Game::GetGame().GetEnemy()->GetenHP() <= 0)
				{
					
						delete enemy[1];
					
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
		enemy[1]->Draw();

		if (ui != nullptr) {
			ui->Update();
		}
	}

}