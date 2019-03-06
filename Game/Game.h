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
	//�v���C���[�B
	Player player;
	//�G�l�~�[�B
	Enemy enemy;
	//�o�b�N�O�����h�B
	BackGround background;
	//�^�[���B
	Phase phase;
};

