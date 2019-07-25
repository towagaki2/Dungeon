#pragma once
#include "character/CharacterController.h"
#include "font.h"
#include "CharaDeta.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

class Font;

class Player:public CharaDeta
{
public:
	Player();
	~Player();
	void PlStatus();
	void Update();
	void Draw();
	void NewPos();
	void RoomIn(std::vector<CharaDeta*> date)
	{

	}
	//プレイヤーのHPのゲッター。
	int GetplHP()
	{
		return plHP;
	}
	//プレイヤーのHPのセッター。
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
	bool GetPlSummaryF()
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
	//経験値のセッター。
	void SetEXP(int SetExp)
	{
		EXP += SetExp;
	}

	int pltate = 0;
	int plyoko = 0;

private:

	int LV = 1;				//レベル。
	int EXP = 0;			//経験値。
	int exp = 10;			//レベルアップするのにいる経験値。
	int plMaxHP = 10;		//最大HP。
	int plHP = plMaxHP;		//現在のHP。
	int plMaxMP = 5;		//最大MP。
	int plMP = plMaxMP;		//現在のMP。
	int iniATK = 10;		//初期攻撃力。
	int plATK = iniATK;		//現在の攻撃力。
	int iniDEF = 50;		//初期防御力。
	int plDEF = iniDEF;		//現在の防御力。
	int HUN = 100000;		//満腹度。


	void Move();			//移動処理。
	void Turn();			//回転処理。　

	bool moveF = false;			//移動フラグ。	
	bool attackF = false;		//攻撃フラグ。
	bool standF = false;			//待機フラグ。
	bool summaryF = false;		//フラグの総括。
	bool RB1F = false;		//RB1押してるかのフラグ。



	CSoundEngine m_soundEngine;							//サウンドエンジン。
	CSoundSource m_MoveSE;								//移動SE。
	CSoundSource m_AtkSE;								//攻撃SE。
	CSoundSource m_CureSE;								//回復SE。
	SkinModel m_model;									//スキンモデル。
	Animation m_animation;								//アニメーション。
	AnimationClip m_animationClips[3];					//アニメーションクリップ。
	CVector3 m_position = CVector3::Zero();				//座標。
	CVector3 m_scale = CVector3::One();					//拡大率。
	CVector3 m_moveSpeed = CVector3::Zero();			//移動速度。
	CVector3 enpo;										//NPCとPlayerの距離。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。	
	Font m_font;										//文字表示のインスタンス。
};

