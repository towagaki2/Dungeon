#include "stdafx.h"
#include "Title.h"


Title::Title()
{
	m_titleModel.Init(L"Assets/modelData/tiitel.cmo");
	m_titleModel.UpdateWorldMatrix(m_position, m_rotation, {10.0f,10.0f,10.0f});
}


Title::~Title()
{
}
void Title::Update()
{

	if (titleF == false &&g_pad[0].IsTrigger(enButtonA))
	{
		titleF = true;
	}
	
}
void Title::Draw()
{
	if (titleF == false) {
		m_titleModel.Draw(
			g_camera3D.GetViewMatrix(),
			g_camera3D.GetProjectionMatrix()
		);
		m_font.BeginDraw();	//フォントの描画開始。
		wchar_t toubatu[256];
		swprintf_s(toubatu, L"不思議にしたかったダンジョン。");	//タイトルを表示する。
		m_font.Draw(
			toubatu,		//表示する文字列。
			{ -400.0f,100.0f },			//表示する座標。0.0f, 0.0が画面の中心。
			{ 1.0f,0.0f,0.0f,1.0f }, 0.0, 4.0, { 1.0f,1.0f }
		);
		swprintf_s(toubatu, L"Aボタンを押してね。");	//Aボタンを押してねを表示する。
		m_font.Draw(
			toubatu,		//表示する文字列。
			{ 0.0f,-200.0f },			//表示する座標。0.0f, 0.0が画面の中心。
			{ 1.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
		);
		m_font.EndDraw();		//フォントの描画終了。
	}
}