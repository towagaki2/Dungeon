#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include"GameDefine.h"
#include "GameEnd.h"

Player::Player()
{

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
	std::random_device rnd;     // 非決定的な乱数生成器を生成
	std::mt19937 Rand(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
	std::uniform_int_distribution<> GetRand(0, 1000);        // [0, 99] 範囲の一様乱数

	m_position = Game::GetGame().GetBackGround()->GetMapPosition();
	m_position.y = 50.0f;
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
			moveF = true;
		}
		//十字キー下を押したら。
		if (g_pad[0].IsTrigger(enButtonDown))
		{
			ZF = -1;
			moveF = true;
		}
		//十字キー左を押したら。
		if (g_pad[0].IsTrigger(enButtonLeft))
		{
			XF = -1;
			moveF = true;
		}
		//十字キー右を押したら。
		if (g_pad[0].IsTrigger(enButtonRight))
		{
			XF = 1;
			moveF = true;
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
			
			attackF = true;
		}
		if (g_pad[0].IsPress(enButtonRB1) == true)
		{
			RB1F = true;
			//回復魔法。
			if (g_pad[0].IsTrigger(enButtonA)&&RB1F == true)
			{
				if (plMP > 2) {
					plHP += 6;
					plMP -= 2;
					if (plMaxHP < plHP)
					{
						plHP = plMaxHP;
					}
				}
				attackF = true;
			}
		}
		else
		{
			RB1F = false;
		}
		//待機処理。
		if (g_pad[0].IsTrigger(enButtonX))
		{
			standF = true;
		}
		if (moveF == true)
		{
			m_animation.Play(1);
		}
		else
		{
			m_animation.Play(0);
		}
		if (moveF == true || attackF == true || standF == true)
		{

			summaryF = true;
			moveF = false;
			attackF = false;
			standF = false;
			
		}	
	}
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
	swprintf_s(toubatu, L"HP：%d/%d", plHP,plMaxHP);	//HPを表示する。
	m_font.Draw(
		toubatu,		//表示する文字列。
		{ -300.0f,300.0f },			//表示する座標。0.0f, 0.0が画面の中心。
		{ 0.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
	);

	swprintf_s(toubatu, L"空腹度：%d", HUN);	//空腹度を表示する。
	m_font.Draw(
		toubatu,		//表示する文字列。
		{ 300.0f,300.0f },			//表示する座標。0.0f, 0.0が画面の中心。
		{ 0.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
	);
	swprintf_s(toubatu, L"MP：%d/%d", plMP,plMaxMP);	//MPを表示する。
	m_font.Draw(
		toubatu,		//表示する文字列。
		{ 0.0f,300.0f },			//表示する座標。0.0f, 0.0が画面の中心。
		{ 0.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
	);
	swprintf_s(toubatu, L"LV：%d", LV);	//LVを表示する。
	m_font.Draw(
		toubatu,		//表示する文字列。
		{ -600.0f,300.0f },			//表示する座標。0.0f, 0.0が画面の中心。
		{ 0.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
	);
	m_font.EndDraw();		//フォントの描画終了。
}