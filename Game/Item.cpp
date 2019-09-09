#include "stdafx.h"
#include "Item.h"
#include "Game.h"


Item::Item()
{
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/Bread.cmo");
	m_position = Game::GetGame().GetBackGround()->GetMapPosition();
	m_position.y = 51.0f;
}


Item::~Item()
{
}

void Item::Update()
{
	auto itpo = Game::GetGame().GetPlayer()->GetPosition() - m_position;
	if (masu > itpo.Length())
	{
		Game::GetGame().GetPlayer()->SetHUN(50);
	}
	////ワールド行列の更新。
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale*1.0);
}

void Item::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}