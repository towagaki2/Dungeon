#include "stdafx.h"
#include "Stairs.h"
#include "Game.h"



Stairs::Stairs()
{
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/Staire.cmo");
	m_position = Game::GetGame().GetBackGround()->GetMapPosition();
	m_position.y = 51.0f;
}


Stairs::~Stairs()
{
}

void Stairs::Update()
{
	auto move = Game::GetGame().GetPlayer()->GetPosition() - m_position;
	if(masu > move.Length() )
	{
		stairsF = true;
	}
	////ワールド行列の更新。
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale*1.0);
}

void Stairs::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}