#pragma once
#include"Enemy.h"


class HorrorMan : public Enemy
{
public:
	HorrorMan(int HP, int ATK, int DEF);
	~HorrorMan();
	void Update();

	//エネミーHPのゲッター。
	int GetenHP()
	{
		return horrorHP;
	}
	//エネミーHPのセッター。
	void SetenHP(int enenHP)
	{
		horrorHP += enenHP;
	}
	//エネミーDEFのゲッター。
	int GetenDEF()
	{
		return horrorDEF;
	}
protected:

private:
	Enemy * enemy;						//エネミー。	

	int horrorHP = 7;					//体力値。
	int horrorATK = 7;					//攻撃力。
	int horrorDEF = 5;					//防御力。
	SkinModel m_model;					//スキンモデル。

};

