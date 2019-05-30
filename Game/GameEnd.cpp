#include "stdafx.h"
#include "GameEnd.h"



GameEnd::GameEnd()
{
	
}


GameEnd::~GameEnd()
{
}
void GameEnd::PostDraw(bool END)
{
	m_font.BeginDraw();	//フォントの描画開始。
	wchar_t toubatu[256];
	if (END == true)
	{
		swprintf_s(toubatu, L"ゲームクリア！");	//敵を倒したときに表示する。

		m_font.Draw(
			toubatu,		//表示する文字列。
			{ FRAME_BUFFER_W / 4.0f,-FRAME_BUFFER_H / 4.0f },			//表示する座標。0.0f, 0.0が画面の中心。
			{ 1.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }

		);
		swprintf_s(toubatu, L"Aを押すとタイトルに戻る");	//敵を倒したときに表示する。

		m_font.Draw(
			toubatu,		//表示する文字列。
			{ FRAME_BUFFER_W / 4.0f,-FRAME_BUFFER_H / 4.0f },			//表示する座標。0.0f, 0.0が画面の中心。
			{ -200.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 200.0f,1.0f }
			
		);
	}
	if (END == false)
	{
		swprintf_s(toubatu, L"ゲームオーバー！");	//プレイヤーが死んだときに表示する。

		m_font.Draw(
			toubatu,		//表示する文字列。
			{ FRAME_BUFFER_W / 4.0f,-FRAME_BUFFER_H / 4.0f },			//表示する座標。0.0f, 0.0が画面の中心。
			{ 1.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
		);
	}
	m_font.EndDraw();		//フォントの描画終了。
}
