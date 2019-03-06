#pragma once
#include "Player.h"
#include "Phase.h"
#include "Enemy.h"
#include "level/Level.h"
#include "BackGround.h"

class Player;

class Game
{
public:
	Game();
	~Game();
	void Update();
	void Draw();
	Player* GetPlayer()
	{
		return &player;
	}
private:
	//プレイヤー。
	Player player;
	//エネミー。
	Enemy enemy;
	//バックグランド。
	BackGround background;
	//ターン。
	Phase phase;
};

