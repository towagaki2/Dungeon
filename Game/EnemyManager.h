#pragma once
#include "Game.h"
#include "GameDefine.h"
#include "Enemy.h"

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();
	void Update();
	void Draw();

	//エネミーのゲッター。
	Enemy* GetEnemy()
	{
			return enemy[1];
	
	}

	enum Enemysyurui
	{
		kara,
		horrorman,
	};
	Enemysyurui Getsyurui()
	{
		return syurui;
	}

private:
	Enemysyurui syurui = kara;		//エネミーの種類。
	int EnemyDeci[teki];			//エネミーの種類を決める。						
	Enemy* enemy[2];				//エネミー。
	int ran = 0;					//ランダムで決められた数字の入れ物。
	int m_number = 0;				//エネミーのカウンター。
};

