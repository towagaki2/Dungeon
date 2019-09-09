#pragma once
#include "character/CharacterController.h"
#include "CharaMove.h"
#include"GameDefine.h"
#include "CharaDeta.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
class Enemy :public CharaDeta
{
public:
	Enemy(int HP, int ATK,int DEF);
	virtual ~Enemy();
	void Update();
	void Draw();


	void RoomIn(std::vector<CharaDeta*> date)
	{
		for (int i = 0; i < date.size(); i++) {
			if (date[i]->GetType() == player)
			{
				enemyMove.Setjoutai(CharaMove::osou);
				break;
			}
		}
	}
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
	void SetenHP(CVector3 pos, int enenHP)
	{
		if ((pos - m_position).Length()<=masu*1.6) {
			enHP += enenHP;
		}
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
	void Move();				//移動処理。
	void Turn();				//回転処理。

	int enemynamber = 10;		//エネミーの総数。

	CharaMove enemyMove;		//移動制御。

	bool moveF = false;			//移動フラグ。	
	bool attackF = false;		//攻撃フラグ。
	bool standF = false;		//待機フラグ。
	bool summaryF = false;		//フラグの総括。
	bool deathF = false;		//死亡フラグ。　　　俺この戦いが終わったら・・・・

	int FrameCounter = 0;		//フレームのカウンター。
	int enHP = 10;				//体力値。
	int enATK = 7;				//攻撃力。
	int enDEF = 5;				//防御力。

	CSoundSource m_AtkSE;								//攻撃SE。
	SkinModel m_model;									//スキンモデル。
	Animation m_animation;								//アニメーション。
	AnimationClip m_animationClips[5];					//アニメーションクリップ。
	CVector3 m_position = {masu*10.0f,0.0f,masu*5.0f};	//座標。
	CVector3 m_scale = CVector3::One();					//拡大率。
	CVector3 m_moveSpeed = CVector3::Zero();			//移動速度。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。								
	
};

