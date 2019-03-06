#include "stdafx.h"
#include "system/system.h"
#include "Game.h"
#include "Player.h"



///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");

	//プレイヤー。
	//Player player;

	//ゲーム。
	Game game;

	//カメラを初期化。
	
	g_camera3D.SetTarget({0.0f,0.0f,0.0f});
	g_camera3D.SetFar(10000.0f);

	CVector3 PlayerPos;
	//ゲームループ。
	while (DispatchWindowMessage() == true)
	{
		PlayerPos = game.GetPlayer()->GetPosition();
		g_camera3D.SetPosition({ PlayerPos.x+10.0f,1000.0f, PlayerPos.z+10.0f });

		g_camera3D.SetTarget({ PlayerPos.x + 10.0f,0.0f, PlayerPos.z+10.1f});
		//描画開始。
		g_graphicsEngine->BegineRender();
		
		//ゲームの更新。
		game.Update();
		//ゲームの描画。
		game.Draw();

		//描画終了。
		g_graphicsEngine->EndRender();
	}
}