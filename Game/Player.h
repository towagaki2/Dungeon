#pragma once
#include "character/CharacterController.h"


class Player
{
public:
	Player();
	~Player();
	void PlStatus();
	void Update();
	void Draw();
	//プレイヤーのポジションと向きのゲッター。
	CVector3 GetPosition()
	{
		return m_position;
	}
	CQuaternion GetRotation()
	{
		return m_rotation;
	}
	//プレイヤーのターンフラグのゲッターとセッター。
	int GetPlSummaryF()
	{
		return summaryF;
	}
	void SetPlSummaryF(int plSummaryF)
	{
		summaryF = plSummaryF;
	}
	//満腹度のセッター。
	void SetHUN(int SetHun)
	{
		HUN += SetHun;
	}

private:
	
	int HP = 10;		//ヒットポイント。
	int ATK = 10;		//攻撃力。
	int DEF = 5;		//防御力。
	int HUN = 100;		//満腹度。
	void Move();		//移動処理。
	void Turn();		//回転処理。　

	int moveF = 0;			//移動フラグ。	
	int attackF = 0;		//攻撃フラグ。
	int standF = 0;			//待機フラグ。
	int summaryF = 0;		//フラグの総括。
	

	SkinModel m_model;									//スキンモデル。
	Animation m_animation;								//アニメーション。
	AnimationClip m_animationClips[2];					//アニメーションクリップ。
	CVector3 m_position = CVector3::Zero();				//座標。
	CVector3 m_scale = CVector3::One();					//拡大率。
	CVector3 m_moveSpeed = CVector3::Zero();			//移動速度。
	float m_Length = (1000.0f*(1.0f / 30.0f))*sqrt(2);	//1マスの長さ
	CVector3 enpo;										//NPCとPlayerの距離。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。	
	CharacterController m_charaCon;						//キャラクターコントローラーを追加。
};

