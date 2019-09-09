#include "stdafx.h"
#include "Enemy.h"
#include "Game.h"



Enemy::Enemy(int HP, int ATK, int DEF) :
	enHP(HP),
	enATK(ATK),
	enDEF(DEF)

{

	SetType(CharaType::enemy);

	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/Skeleton@Skin.cmo");

	//tkaファイルの読み込み。
	//待機アニメーション。
	m_animationClips[0].Load(L"Assets/animData/SkeletonIDLE.tka");		
	m_animationClips[0].SetLoopFlag(true);

	//歩きアニメーション。
	m_animationClips[1].Load(L"Assets/animData/SkeletonWALK.tka");		
	m_animationClips[1].SetLoopFlag(true);

	//攻撃アニメーション。
	m_animationClips[2].Load(L"Assets/animData/SkeletonATK.tka");
	m_animationClips[2].SetLoopFlag(true);

	//死亡アニメーション。
	m_animationClips[3].Load(L"Assets/animData/SkeletonDEATH.tka");	
	m_animationClips[3].SetLoopFlag(true);

	//ダメージアニメーション。
	m_animationClips[4].Load(L"Assets/animData/SkeletonDAMAGE.tka");	
	m_animationClips[4].SetLoopFlag(true);

	//アニメーションの初期化。
	m_animation.Init(
		m_model,			//アニメーションを流すスキンモデル。
							//これでアニメーションとスキンモデルが関連付けされる。
		m_animationClips,	//アニメーションクリップの配列。
		5					//アニメーションクリップの数。
	);

	////SE。
	m_AtkSE.Init(L"Assets/music/kick_middle.wav");

	m_position.y = masu;

	//ポジション決め。
	m_position = Game::GetGame().GetBackGround()->GetMapPosition(enemyMove.chatate, enemyMove.chayoko,this);

	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
	
}

Enemy::~Enemy()
{
	Game::GetGame().GetBackGround()->deletedata(RoomNo, this);

}

void Enemy::Move()
{		
	if (Game::GetGame().GetPhase()->GetTaan() == Phase::enTaan) { 
		
			FrameCounter++;
		
		if (FrameCounter > 0) {
			//特殊処理(眠るや混乱など追加予定。)


			auto move = Game::GetGame().GetPlayer()->GetPosition() - m_position;
				//攻撃処理
			if (masu*1.6 > move.Length())
			{
					if (Game::GetGame().GetPlayer()->GetplDEF() < enATK)
					{
						Game::GetGame().GetPlayer()->SetplHP(Game::GetGame().GetPlayer()->GetplDEF() - enATK);
					}
					//プレイヤーの防御力と同じまたはそれ以下ならダメージを与えない。
					else
					{
						Game::GetGame().GetPlayer()->SetplHP(0);
					}
				m_AtkSE.Play(false);
				m_animation.Play(2);
				attackF = true;
			}
			else
				//移動処理
			{
				m_moveSpeed = enemyMove.EneMove(m_position,this);
				m_moveSpeed *= masu;
				m_position += m_moveSpeed;
				moveF = true;
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
		if (enHP <= 0)
		{
			deathF = true;
		}
		else 
		{
			deathF = false;
		}
		m_position.y = 50.0f;
	
	//ワールド行列の更新。
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale * 5.5);
	//アニメーションの更新。
	m_animation.Update(1.0f / 30.0f);
	
}

void Enemy::Draw()
{
	if (Game::GetGame().GetEnemymanager()->Getsyurui() == EnemyManager::horrorman)
	{
		m_model.Draw(
			g_camera3D.GetViewMatrix(),
			g_camera3D.GetProjectionMatrix()
		);
	}
}