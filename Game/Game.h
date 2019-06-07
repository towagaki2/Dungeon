#pragma once
#include "Phase.h"
#include "Player.h"
#include "Enemy.h"
#include "title.h"
#include "level/Level.h"
#include "BackGround.h"
#include "GameEnd.h"
#include "UI.h"
#include "RogueLikeMap.h"

class Player;
class Phase;
class Enemy;
class titel;
class GameEnd;
class UI;
class RogueLikeMap;

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
	 void StartGame();
	 void EndGame();
		
	 /// <summary>
	 ///プレイヤーのゲッター。
	 /// </summary>
	 /// <returns>
	 /// プレイヤーのポインタ(Player*)
	 /// </returns>
	 Player* GetPlayer()
		{
			return player;
		}
		//エネミーのゲッター。
		Enemy* GetEnemy()
		{
			return enemy;
		}
		//ターンのゲッター。
		Phase* GetPhase()
		{
			return phase;
		}
		//グランドのゲッター。
		BackGround* GetBackGround()
		{
			return background;
		}
	protected:
		Game();
	private:
		CVector3 PlayerPos;
		//プレイヤー。
		Player* player;
		//エネミー。
		Enemy* enemy;
		//タイトル。
		Title* title;
		//バックグランド。
		BackGround* background;
		//ターン。
		Phase* phase;
		//ユーザーインターフェース。
		UI* ui;
		//マップ生成。
		RogueLikeMap* rogueLikeMap;
};

