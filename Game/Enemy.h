#pragma once
#include "character/CharacterController.h"
#include "CharaMove.h"
#include"GameDefine.h"

class Enemy
{
public:
	Enemy();
	~Enemy();
	void EnStatus();
	void Update();
	void Draw();

	const CVector3* GetPosition()
	{
		return &m_position;
	}
	CQuaternion GetRotation()
	{
		return m_rotation;
	}
	//エネミーのターンフラグ。
	int GetEneSummaryF()
	{
		return summaryF;
	}
	void SetEneSummaryF(int eneSummaryF)
	{
		summaryF = eneSummaryF;
	}

private:
	void Move();		//移動処理。
	void Turn();		//回転処理。

	int HP = 10;		//体力値。
	int ATK = 6;		//攻撃力。
	int DEF = 5;		//防御力。
	

	CharaMove enemyMove;		//移動制御。

	int moveF = 0;			//移動フラグ。	
	int attackF = 0;		//攻撃フラグ。
	int standF = 0;			//待機フラグ。
	int summaryF = 0;			//フラグの総括。

	int FrameCounter = 0;		//フレームのカウンター。

	SkinModel m_model;									//スキンモデル。
	Animation m_animation;								//アニメーション。
	AnimationClip m_animationClips[2];					//アニメーションクリップ。
	CVector3 m_position = {masu*10,0.0f,masu*5};				//座標。
	float m_Length=(1000.0f*(1.0f/30.0f))*sqrt(2);			//1マスの長さ
	CVector3 m_scale = CVector3::One();					//拡大率。
	CVector3 m_moveSpeed = CVector3::Zero();			//移動速度。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。								
	CharacterController m_charaCon;			//キャラクターコントローラーを追加。
	
};

