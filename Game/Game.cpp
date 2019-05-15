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


		//物理エンジンの更新。
		g_physics.Update();
		//プレイヤーの更新。
		player.Update();
		//エネミーの更新。
		enemy.Update();
		//バックグランドの更新。
		background.Update();
		//ターンの更新。
		phase.Update();
		//ゲームエンドの更新。


		PlayerPos = Game::GetGame().GetPlayer()->GetPosition();
		g_camera3D.SetPosition({ PlayerPos.x + 10.0f,800.0f, PlayerPos.z + 10.0f });
		g_camera3D.SetTarget({ PlayerPos.x + 10.0f,0.0f, PlayerPos.z + 10.1f });
		//カメラの更新。
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
	//バックグランドの描画。
	background.Draw();
	//プレイヤーの描画。
	player.Draw();
	//エネミーの描画。
	enemy.Draw();
	if(ui != nullptr) {
		ui->Update();
	}
}