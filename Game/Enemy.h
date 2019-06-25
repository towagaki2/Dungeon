#pragma once
#include "character/CharacterController.h"
#include "CharaMove.h"
#include"GameDefine.h"

class Enemy
{
public:
	Enemy(int HP, int ATK,int DEF);
	~Enemy();
	void Update();
	void Draw();


	//エネミーの場所と向きのゲッター。
	const CVector3& GetPosition()
	{
		return m_position;
	}
	CQuaternion GetRotation()
	{
		return m_rotation;
	}

	//エネミーHPのゲッター。
	int GetenHP()
	{
		return enHP;
	}
	//エネミーHPのセッター。
	void SetenHP(int enenHP)
	{
		enHP += enenHP;
	}
	//エネミーDEFのゲッター。
	int GetenDEF()
	{
		return enDEF;
	}
	/// <summary>
	/// エネミーのフラグ総括のゲッター。
	/// </summary>
	/// <returns></returns>
	bool GetEneSummaryF()
	{
		return summaryF;
	}
	bool GetEneAttackF()
	{
		return attackF;
	}
	int Getnumber()
	{
		return enemynamber;
	}
	bool GetdeathF()
	{
		return deathF;
	}
	/// <summary>
	/// エネミーのフラグ総括のセッター。
	/// </summary>
	/// <param name="eneSummaryF">
	/// フラグ。
	/// </param>
	void SetEneSummaryF(int eneSummaryF)
	{
		summaryF = eneSummaryF;
	}

private:
	void Move();		//移動処理。
	void Turn();		//回転処理。

	int enemynamber = 10;		//エネミーの総数。

	CharaMove enemyMove;	//移動制御。

	bool moveF = false;			//移動フラグ。	
	bool attackF = false;		//攻撃フラグ。
	bool standF = false;		//待機フラグ。
	bool summaryF = false;		//フラグの総括。
	bool deathF = false;		//死亡フラグ。　　　俺この戦いが終わったら・・・・

	int FrameCounter = 0;		//フレームのカウンター。
	int enHP = 10;					//体力値。
	int enATK = 7;					//攻撃力。
	int enDEF = 5;					//防御力。

	SkinModel m_model;									//スキンモデル。
	Animation m_animation;								//アニメーション。
	AnimationClip m_animationClips[5];					//アニメーションクリップ。
	CVector3 m_position = {masu*10,0.0f,masu*5};		//座標。
	CVector3 m_scale = CVector3::One();					//拡大率。
	CVector3 m_moveSpeed = CVector3::Zero();			//移動速度。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。								
	CharacterController m_charaCon;			//キャラクターコントローラーを追加。
	
};

