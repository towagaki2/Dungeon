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
		//�v���C���[�̃Q�b�^�[�B
		Player* GetPlayer()
		{
			return &player;
		}
		//�G�l�~�[�̃Q�b�^�[�B
		Enemy* GetEnemy()
		{
			return &enemy;
		}
		//�^�[���̃Q�b�^�[�B
		Phase* GetPhase()
		{
			return &phase;
		}
	protected:
		Game();
	private:
		CVector3 PlayerPos;
		//�v���C���[�B
		Player player;
		//�G�l�~�[�B
		Enemy enemy;
		//�o�b�N�O�����h�B
		BackGround background;
		//�^�[���B
		Phase phase;
};

