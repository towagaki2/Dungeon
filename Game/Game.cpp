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
	//カメラの更新。
	g_camera3D.Update();
	//プレイヤーの更新。
	player.Update();
	//エネミーの更新。
	enemy.Update();
	//バックグランドの更新。
	background.Update();
	//ターンの更新。
	phase.Update();
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