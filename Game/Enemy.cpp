#include "stdafx.h"
#include "Enemy.h"



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

	m_position.y = 0.0f;	
	m_charaCon.Init(25.0f, 50.0f, m_position); 
	enemyMove.Getpos(m_position);
	m_position = { 10.0f,0.0f,0.0f };
}

Enemy::~Enemy()
{
}

void Enemy::Move()
{
	enemyMove.Getpos(m_position);
	if (phase.GetTaan() == 0) {
		m_moveSpeed = enemyMove.EneMove();
		m_moveSpeed *= 100.0f;
		m_position += m_moveSpeed;
	}
	m_position = m_charaCon.Execute(1.0f / 30.0f, m_moveSpeed);
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