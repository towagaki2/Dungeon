#include "stdafx.h"
#include "system/system.h"
#include "Game.h"
#include"title.h"
#include"AutoMap.h"

///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");

	//カメラを初期化。
	AutoMap k;
	g_camera3D.SetTarget({10.0f,10.0f,10.0f});
	g_camera3D.SetPosition({ 10.0f,800.0f,10.10f });
	g_camera3D.SetFar(10000.0f);
	//カメラの更新。
	g_camera3D.Update();
	title Title;
	while (DispatchWindowMessage() == true)
	{
		
		//描画開始。
		g_graphicsEngine->BegineRender();
		//ゲームパッドの更新。	
		for (auto& pad : g_pad) {
			pad.Update();
		}	
		if (Title.GetTitleF()==true) {
			//ゲームの更新。

			Game::GetGame().Update();
			//ゲームの描画。
			Game::GetGame().Draw();
		}
		Title.Update();
		Title.Draw();

		//描画終了。
		g_graphicsEngine->EndRender();
	}
}