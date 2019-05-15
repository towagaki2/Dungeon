#pragma once
#include "character/CharacterController.h"
#include "font.h"

class Font;

class Player
{
public:
	Player();
	~Player();
	void PlStatus();
	void Update();
	void Draw();
	//プレイヤーのHPのゲッター。
	int GetplHP()
	{
		return plHP;
	}
	//プレイヤーのHPセッター。
	void SetplHP(int plplHP)
	{
		plHP += plplHP;
	}
	//プレイヤーのDEFのゲッター。
	int GetplDEF()
	{
		return plDEF;
	}
	//プレイヤーのポジションのゲッター。
	CVector3 GetPosition()
	{
		return m_position;
	}
	//プレイヤーの向きのゲッター。
	CQuaternion GetRotation()
	{
		return m_rotation;
	}
	//プレイヤーのターンフラグのゲッター。
	int GetPlSummaryF()
	{
		return summaryF;
	}
	//プレイヤーのターンフラグのセッター。
	void SetPlSummaryF(int plSummaryF)
	{
		summaryF = plSummaryF;
	}
	//満腹度のゲッター。
	int GetHUN()
	{
		return HUN;
	}
	//満腹度のセッター。
	void SetHUN(int SetHun)
	{
		HUN += SetHun;
	}

private:
	
	int plHP = 10;		//ヒットポイント。
	int plATK = 10;		//攻撃力。
	int plDEF = 5;		//防御力。
	int HUN = 100;		//満腹度。
	void Move();		//移動処理。
	void Turn();		//回転処理。　

	int moveF = 0;			//移動フラグ。	
	int attackF = 0;		//攻撃フラグ。
	int standF = 0;			//待機フラグ。
	int summaryF = 0;		//フラグの総括。


	SkinModel m_model;									//スキンモデル。
	Animation m_animation;								//アニメーション。
	AnimationClip m_animationClips[3];					//アニメーションクリップ。
	CVector3 m_position = CVector3::Zero();				//座標。
	CVector3 m_scale = CVector3::One();					//拡大率。
	CVector3 m_moveSpeed = CVector3::Zero();			//移動速度。
	CVector3 enpo;										//NPCとPlayerの距離。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。	
	CharacterController m_charaCon;						//キャラクターコントローラーを追加。
	Font m_font;										////文字表示のインスタンス。
};

