#include "stdafx.h"
#include "Player.h"
#include "Game.h"


Player::Player()
{
	
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	//tkaファイルの読み込み。
	m_animationClips[0].Load(L"Assets/animData/walk.tka");
	m_animationClips[0].SetLoopFlag(true);

	m_animationClips[1].Load(L"Assets/animData/run.tka");
	m_animationClips[1].SetLoopFlag(true);
	//アニメーションの初期化。
	m_animation.Init(
		m_model,			//アニメーションを流すスキンモデル。
							//これでアニメーションとスキンモデルが関連付けされる。
		m_animationClips,	//アニメーションクリップの配列。
		2					//アニメーションクリップの数。
	);

	m_position.y = 0.0f;
	m_charaCon.Init(10.0f, 50.0f, m_position);

}


Player::~Player()
{
}

void Player::Move()
{
	
	if (Game::GetGame().GetPhase()->GetTaan() == 0) {
		//移動処理。
	/*	float lStickXF = g_pad[0].GetLStickXF();
		float lStickYF = g_pad[0].GetLStickYF();*/
		float XF = 0;
		float ZF = 0;
		if (g_pad[0].IsTrigger(enButtonUp))
		{
			ZF = 1;
			moveF = 1;
		}
		else if (g_pad[0].IsTrigger(enButtonDown))
		{
			ZF = -1;
			moveF = 1;
		}
		else
		{
			ZF = 0;
		}
		if (g_pad[0].IsTrigger(enButtonLeft))
		{
			XF = -1;
			moveF = 1;
		}
		else if (g_pad[0].IsTrigger(enButtonRight))
		{
			XF = 1;
			moveF = 1;
		}
		else
		{
			XF = 0;
		}
		//m_moveSpeed.z = lStickYF * 1000.0f;	//縦方向への移動速度を代入。
		//m_moveSpeed.x = lStickXF * 1000.0f;		//横方向への移動速度を代入。
		m_moveSpeed.z = ZF * 1000.0f;
		m_moveSpeed.x = XF * 1000.0f;
		m_position = m_charaCon.Execute(1.0f / 30.0f, m_moveSpeed);

		m_moveSpeed.y -= 980.0f * (1.0f / 60.0f);

		//攻撃処理。
		if (g_pad[0].IsTrigger(enButtonA))
		{
			attackF = 1;
		}
		//待機処理。
		if (g_pad[0].IsTrigger(enButtonX))
		{
			standF = 1;
		}
		if (moveF == 1 || attackF == 1 || standF == 1)
		{
		summaryF = 1;
		moveF = 0;
		attackF = 0;
		standF = 0;
		}
	}

	CVector3 cameraForward = g_camera3D.GetForward();
	CVector3 cameraRight = g_camera3D.GetRight();
	//XZ平面での前方方向、右方向に変換する。
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	cameraRight.y = 0.0f;
	cameraRight.Normalize();
}

void Player::Turn()
{

}

void Player::Update()
{
	
	//移動処理。
	Move();
	//回転処理
	Turn();

	//ワールド行列の更新。
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);

}

void Player::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}