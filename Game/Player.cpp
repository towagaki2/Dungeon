#include "stdafx.h"
#include "Player.h"
#include "RogueLikeMap.h"
#include "Game.h"
#include"GameDefine.h"
#include "GameEnd.h"

Player::Player()
{
	RogueLikeMap map;

	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/player1fbx.cmo");

	//tkaファイルの読み込み。
	m_animationClips[0].Load(L"Assets/animData/pla_idle.tka");
	m_animationClips[0].SetLoopFlag(true);

	m_animationClips[1].Load(L"Assets/animData/pla_run.tka");
	m_animationClips[1].SetLoopFlag(true);

	m_animationClips[2].Load(L"Assets/animData/pla_hit.tka");
	m_animationClips[2].SetLoopFlag(false);
	//アニメーションの初期化。
	m_animation.Init(
		m_model,			//アニメーションを流すスキンモデル。
							//これでアニメーションとスキンモデルが関連付けされる。
		m_animationClips,	//アニメーションクリップの配列。
		3					//アニメーションクリップの数。
	);
		
	m_charaCon.Init(10.0f, 50.0f, m_position);

	for (int i = 0; i < MAPX_RLk; i++) {
		for (int j = 0; j < MAPY_RLk; j++) {
			if (map.mapData != 1) {
	
			}
		}
	}

}


Player::~Player()
{
}

void Player::PlStatus()
{
	plHP;
	HUN;

}

void Player::Move()
{
	auto enpo = Game::GetGame().GetEnemy()->GetPosition() - m_position;
	if (Game::GetGame().GetPhase()->GetTaan() == Phase::plTaan) {

		//移動処理。
		float XF = 0;
		float ZF = 0;
		//十字キー上を押したら。
		if (g_pad[0].IsTrigger(enButtonUp))
		{
			ZF = 1;
			moveF = 1;
		}
		//十字キー下を押したら。
		if (g_pad[0].IsTrigger(enButtonDown))
		{
			ZF = -1;
			moveF = 1;
		}
		//十字キー左を押したら。
		if (g_pad[0].IsTrigger(enButtonLeft))
		{
			XF = -1;
			moveF = 1;
		}
		//十字キー右を押したら。
		if (g_pad[0].IsTrigger(enButtonRight))
		{
			XF = 1;
			moveF = 1;
		}
		m_moveSpeed.z = ZF * masu;
		m_moveSpeed.x = XF * masu;
		m_position += m_moveSpeed;

		//重力(今回いらない)
		//m_moveSpeed.y -= 980.0f * (1.0f / 30.0f);

		
		//攻撃処理。
		if (g_pad[0].IsTrigger(enButtonA)&&RB1F == false)
		{
			m_animation.Play(2);
			if (masu*1.6 > enpo.Length())
			{
				Game::GetGame().GetEnemy() ->SetenHP(Game::GetGame().GetEnemy()->GetenDEF() - plATK);
			}
			
			attackF = 1;
		}
		if (g_pad[0].IsPress(enButtonRB1) == true)
		{
			RB1F = true;
			if (g_pad[0].IsTrigger(enButtonA)&&RB1F == true)
			{
				plHP += 3;
				if (plMaxHP < plHP)
				{
					plHP = plMaxHP;
				}
				attackF = 1;
			}
		}
		else
		{
			RB1F = false;
		}
		//待機処理。
		if (g_pad[0].IsTrigger(enButtonX))
		{
			standF = 1;
		}
		if (moveF == 1)
		{
			m_animation.Play(1);
		}
		else
		{
			m_animation.Play(0);
		}
		if (moveF == 1 || attackF == 1 || standF == 1)
		{

			summaryF = 1;
			moveF = 0;
			attackF = 0;
			standF = 0;
			
		}
		
	}

	//CVector3 cameraForward = g_camera3D.GetForward();
	//CVector3 cameraRight = g_camera3D.GetRight();
	////XZ平面での前方方向、右方向に変換する。
	//cameraForward.y = 0.0f;
	//cameraForward.Normalize();
	//cameraRight.y = 0.0f;
	//cameraRight.Normalize();
}

void Player::Turn()
{

}
void Player::Update()
{
		//プレイヤーのステータス処理。
		PlStatus();
		//移動処理。
		Move();
		//回転処理
		Turn();
		//アニメーションの更新。
		m_animation.Update(1.0f / 30.0f);
		////ワールド行列の更新。
		m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale*1.0);
}

void Player::Draw()
{

	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);

	m_font.BeginDraw();	//フォントの描画開始。
	wchar_t toubatu[256];
	swprintf_s(toubatu, L"HP：%d / %d", plHP,plMaxHP);	//敵を倒したときに表示する。
	m_font.Draw(
		toubatu,		//表示する文字列。
		{ 0.0f,300.0f },			//表示する座標。0.0f, 0.0が画面の中心。
		{ 1.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
	);

	swprintf_s(toubatu, L"空腹度：%d", HUN);	//空腹度を表示する。
	m_font.Draw(
		toubatu,		//表示する文字列。
		{ 300.0f,300.0f },			//表示する座標。0.0f, 0.0が画面の中心。
		{ 1.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
	);

	m_font.EndDraw();		//フォントの描画終了。
}