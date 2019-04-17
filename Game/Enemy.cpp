#include "stdafx.h"
#include "Enemy.h"
#include "Game.h"


Enemy::Enemy()
{
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/Skeleton@Skin.cmo");

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

	m_charaCon.Init(25.0f, 50.0f, m_position); 
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
}

Enemy::~Enemy()
{
}

void Enemy::EnStatus()
{
	enHP;
}

void Enemy::Move()
{		
	if (Game::GetGame().GetPhase()->GetTaan() == Phase::enTaan) { 
		FrameCounter++;
		if (FrameCounter > 15) {
			//特殊処理


			auto move = Game::GetGame().GetPlayer()->GetPosition() - m_position;
				//攻撃処理
			if (masu*1.3 > move.Length())
			{
				Game::GetGame().GetPlayer()->SetplHP(Game::GetGame().GetPlayer()->GetplDEF() - enATK);
				attackF = 1;
			}
			//移動処理
			{
				m_moveSpeed = enemyMove.EneMove(m_position);
				m_moveSpeed *= masu;
				m_position += m_moveSpeed;
				moveF = 1;
			}
			if (moveF == 1 || attackF == 1 || standF == 1)
			{
				summaryF = 1;
				moveF = 0;
				attackF = 0;
				standF = 0;
				FrameCounter = 0;
			}
		}
	}
}

void Enemy::Turn()
{

}

void Enemy::Update()
{
		//エネミーのステータス処理。
		EnStatus();
		//移動処理。
		Move();
		//回転処理
		Turn();
	
	//ワールド行列の更新。
		m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale * 8);
	
}

void Enemy::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}