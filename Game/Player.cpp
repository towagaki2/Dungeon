#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include"GameDefine.h"


Player::Player()
{
	
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	//tkaファイルの読み込み。
	m_animationClips[0].Load(L"Assets/animData/walk.tka");
	m_animationClips[0].SetLoopFlag(false);

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

void Player::PlStatus()
{
	plHP;
	HUN;

}

void Player::Move()
{

	if (Game::GetGame().GetPhase()->GetTaan() == Phase::plTaan) {

		//移動処理。
		float XF = 0;
		float ZF = 0;
		if (g_pad[0].IsTrigger(enButtonUp))
		{
			ZF = 1;
			moveF = 1;
		}
		if (g_pad[0].IsTrigger(enButtonDown))
		{
			ZF = -1;
			moveF = 1;
		}
		if (g_pad[0].IsTrigger(enButtonLeft))
		{
			XF = -1;
			moveF = 1;
		}
		if (g_pad[0].IsTrigger(enButtonRight))
		{
			XF = 1;
			moveF = 1;
		}
		m_moveSpeed.z = ZF * masu;
		m_moveSpeed.x = XF * masu;
		m_position += m_moveSpeed;

		//m_moveSpeed.y -= 980.0f * (1.0f / 30.0f);e


		//攻撃処理。
		if (g_pad[0].IsTrigger(enButtonA))
		{
			if (masu*1.3 > enpo.Length())
			{
				Game::GetGame().GetEnemy() ->SetenHP(Game::GetGame().GetEnemy()->GetenDEF() - plATK);
			}
			attackF = 1;
		}
		//待機処理。
		if (g_pad[0].IsTrigger(enButtonX))
		{
			standF = 1;
		}
		if (moveF == 1)
		{
			m_animation.Play(0);
		}
		else
		{
			m_animation.Play(1);
		}
		if (moveF == 1 || attackF == 1 || standF == 1)
		{
			if (!m_animation.IsPlaying()) 
			{
			summaryF = 1;
			moveF = 0;
			attackF = 0;
			standF = 0;
			}
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
	//プレイヤーのステータス処理。
	PlStatus();
	//移動処理。
	Move();
	//回転処理
	Turn();
	//アニメーションの更新。
	m_animation.Update(1.0f/30.0f);
	//ワールド行列の更新。
	m_rotation.SetRotationDeg(CVector3::AxisX(), 90.0f);
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);

}

void Player::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}