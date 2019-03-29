#include "stdafx.h"
#include "Enemy.h"
#include "Game.h"


Enemy::Enemy()
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

	m_charaCon.Init(25.0f, 50.0f, m_position); 
	enemyMove.Getpos(m_position);
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
}

Enemy::~Enemy()
{
}

void Enemy::EnStatus()
{

}

void Enemy::Move()
{		
	if (Game::GetGame().GetPhase()->GetTaan() == Phase::enTaan) {
		FrameCounter++;
		if (FrameCounter > 15) {
			//特殊処理


			//移動処理
			auto move = Game::GetGame().GetPlayer()->GetPosition() - m_position;
			if (m_Length > move.Length())
			{
				//攻撃処理
				attackF = 1;
			}
			else {
				m_moveSpeed = enemyMove.EneMove();
				m_moveSpeed *= 1000.0f;
				m_position = m_charaCon.Execute(1.0f / 30.0f, m_moveSpeed);
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
		//移動処理。
		Move();
		//回転処理
		Turn();
	
	//ワールド行列の更新。
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
	
}

void Enemy::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}