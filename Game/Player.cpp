#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include"GameDefine.h"
#include "GameEnd.h"



Player::Player()
{
	SetType(CharaType::player);
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/player1fbx.cmo");

	//tkaファイルの読み込み。
	m_animationClips[0].Load(L"Assets/animData/pla_idle.tka");
	m_animationClips[0].SetLoopFlag(true);
	//歩きモーション。
	m_animationClips[1].Load(L"Assets/animData/pla_run.tka");
	m_animationClips[1].SetLoopFlag(true);
	//攻撃モーション
	m_animationClips[2].Load(L"Assets/animData/pla_hit.tka");
	m_animationClips[2].SetLoopFlag(false);
	//アニメーションの初期化。
	m_animation.Init(
		m_model,			//アニメーションを流すスキンモデル。
							//これでアニメーションとスキンモデルが関連付けされる。
		m_animationClips,	//アニメーションクリップの配列。
		3					//アニメーションクリップの数。
	);
	//サウンドエンジンを初期化。
	//m_soundEngine.Init();
	//SE。
	m_AtkSE.Init(L"Assets/music/sword_gesture.wav");
	m_MoveSE.Init(L"Assets/music/plmove.wav");
	m_CureSE.Init(L"Assets/music/magic_status_cure.wav");


	NewPos();
}
void Player::NewPos()
{
	m_position = Game::GetGame().GetBackGround()->GetMapPosition(pltate, plyoko,this);

	m_position.y = masu;
}

Player::~Player()
{
}

void Player::PlStatus()
{
}

void Player::Move()
{
	CVector3 enpo = { 1000000.0f,10000000.0f,0.0f };
	for (int i = 0; i < 10; i++) {
		if (Game::GetGame().GetEnemy(i) != nullptr) {
			enpo = Game::GetGame().GetEnemy(i)->GetPosition() - m_position;
		}
	}
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
		//進む方向が壁じゃないなら進む。
		//壁なら移動せずターンは進まない。
		if (!Game::GetGame().GetBackGround()->GetKabeOrYuka(pltate+ ZF,plyoko+XF,this)&& moveF==true)
		{
			pltate += ZF;
			plyoko += XF;
			m_moveSpeed.z = ZF * masu;
			m_moveSpeed.x = XF * masu;
			m_position += m_moveSpeed;
		}
		else
		{
			moveF = false;
		}
		
		//重力(今回いらない)
		//m_moveSpeed.y -= 980.0f * (1.0f / 30.0f);
		
		//攻撃処理。
		if (g_pad[0].IsTrigger(enButtonA)&&RB1F == false)
		{
			m_animation.Play(2);
			for (int i = 0; i < teki; i++) {
				
				if (Game::GetGame().GetEnemy(i) != nullptr) {
					Game::GetGame().GetEnemy(i)->SetenHP(m_position, Game::GetGame().GetEnemy(i)->GetenDEF() - plATK);
				}
			}
			m_AtkSE.Play(false);
			attackF = true;
		}
		if (g_pad[0].IsPress(enButtonRB1) == true)
		{
			RB1F = true;
			//ホイミー。
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
				m_CureSE.Play(false);
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
		//アニメーション処理。
		if (moveF == true)
		{

			m_MoveSE.Play(false);
			m_animation.Play(1);
		}
		else
		{
			m_animation.Play(0);
		}
		//もし移動、攻撃、待機などのフラグが立っていたら総括フラグを立てる。
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
	float angle = atan2(m_moveSpeed.x, m_moveSpeed.z);
	m_rotation.SetRotation(CVector3::AxisY(), angle);
	if (g_pad[0].IsPress(enButtonB) == true)
	{
		
	}

}
void Player::Update()
{
		//プレイヤーのステータス処理。
		PlStatus();
		//移動処理。
		Move();
		//効果音の更新。
		//回転処理
		Turn();
		//アニメーションの更新。
		m_animation.Update(1.0f / 30.0f);
		////ワールド行列の更新。
		m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale*1.0);
		if (EXP >= exp)
		{
			LV++;
			exp += 10;
			//ステータスアップ。
			plMaxHP += 5;
			plMaxMP += 5;
			plATK += 5 ;
			plDEF += 5;
			//レベルアップによる回復。
			plHP = plMaxHP;
			plMP = plMaxMP;
			HUN = 100;
		}
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