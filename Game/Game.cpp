#include "stdafx.h"
#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::Update()
{
	//ゲームパッドの更新。	
	for (auto& pad : g_pad) {
		pad.Update();
	}
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
	PlayerPos = Game::GetGame().GetPlayer()->GetPosition();
	g_camera3D.SetPosition({ PlayerPos.x + 10.0f,800.0f, PlayerPos.z + 10.0f });
	g_camera3D.SetTarget({ PlayerPos.x + 10.0f,0.0f, PlayerPos.z + 10.1f });
	//カメラの更新。
	g_camera3D.Update();
}

void Game::Draw()
{
	//プレイヤーの描画。
	player.Draw();
	//エネミーの描画。
	enemy.Draw();
	//バックグランドの描画。
	background.Draw();
}