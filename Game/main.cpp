#include "stdafx.h"
#include "system/system.h"
#include "Game.h"
 

///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{

	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");
	//ゲーム。
	//Game::Create();

	//カメラを初期化。
	
	g_camera3D.SetTarget({0.0f,0.0f,0.0f});
	g_camera3D.SetFar(10000.0f);


	//ゲームループ。
	while (DispatchWindowMessage() == true)
	{
		
		//描画開始。
		g_graphicsEngine->BegineRender();
		
		//ゲームの更新。
		Game::GetGame().Update();
		//ゲームの描画。
		Game::GetGame().Draw();

		//描画終了。
		g_graphicsEngine->EndRender();
	}
	//Game::Destroy();
}