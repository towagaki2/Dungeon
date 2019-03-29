#pragma once
#include "Phase.h"
#include "Player.h"
#include "Enemy.h"
#include "level/Level.h"
#include "BackGround.h"
class Player;
class Phase;
class Enemy;
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
		Player* GetPlayer()
		{
			return &player;
		}
		Enemy* GetEnemy()
		{
			return &enemy;
		}
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
};

