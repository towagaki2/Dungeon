#pragma once
#include "character/CharacterController.h"
#include "Phase.h"

class Phase;

class Player
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
	
	CVector3 GetPosition()
	{
		return m_position;
	}
	CQuaternion GetRotation()
	{
		return m_rotation;
	}
	//プレイヤーの移動のフラグ
	int GetPlmoveF()
	{
		return moveF;
	}
	//プレイヤーの攻撃のフラグ
	int GetPlatttackF()
	{
		return atttackF;
	}
	//プレイヤーの待機のフラグ
	int GetPlstandF()
	{
		return standF;
	}

private:
	void Move();		//移動処理。
	void Turn();		//回転処理　

	Phase phase;			//ターン制御

	int moveF = 0;			//移動フラグ。	
	int atttackF = 0;		//攻撃フラグ。
	int standF = 0;			//待機フラグ。
	
	SkinModel m_model;									//スキンモデル。
	Animation m_animation;								//アニメーション。
	AnimationClip m_animationClips[2];					//アニメーションクリップ。
	CVector3 m_position = CVector3::Zero();				//座標。
	CVector3 m_scale = CVector3::One();					//拡大率。
	CVector3 m_moveSpeed = CVector3::Zero();			//移動速度。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。								
	CharacterController m_charaCon;						//キャラクターコントローラーを追加。
};

