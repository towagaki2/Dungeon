#pragma once
#include "Phase.h"
#include "Player.h"
#include "Enemy.h"
#include "level/Level.h"
#include "BackGround.h"
#include "GameEnd.h"
#include "UI.h"
class Player;
class Phase;
class Enemy;
class GameEnd;
class UI;

class Game
{
	public:
		~Game();
		
		 void Update();
		 void Draw();
	 static Game &GetGame()
		{
			 static Game s_pGame;
			 return s_pGame;
		}
		
	 /// <summary>
	 ///プレイヤーのゲッター。
	 /// </summary>
	 /// <returns>
	 /// プレイヤーのポインタ(Player*)
	 /// </returns>
	 Player* GetPlayer()
		{
			return &player;
		}
		//エネミーのゲッター。
		Enemy* GetEnemy()
		{
			return &enemy;
		}
		//ターンのゲッター。
		Phase* GetPhase()
		{
			return &phase;
		}
	protected:
		Game();
	private:
		CVector3 PlayerPos;
		//プレイヤー。
		Player player;
		//エネミー。
		Enemy enemy;
		//バックグランド。
		BackGround background;
		//ターン。
		Phase phase;
		//ゲームの終わり。
		GameEnd gameEnd;
		//ユーザーインターフェース。
		UI* ui;
};

