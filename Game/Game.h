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
	 ///�v���C���[�̃Q�b�^�[�B
	 /// </summary>
	 /// <returns>
	 /// �v���C���[�̃|�C���^(Player*)
	 /// </returns>
	 Player* GetPlayer()
		{
			return player;
		}
		//�G�l�~�[�̃Q�b�^�[�B
		Enemy* GetEnemy()
		{
			return enemy;
		}
		//�^�[���̃Q�b�^�[�B
		Phase* GetPhase()
		{
			return phase;
		}
		//�O�����h�̃Q�b�^�[�B
		BackGround* GetBackGround()
		{
			return background;
		}
	protected:
		Game();
	private:
		CVector3 PlayerPos;
		//�v���C���[�B
		Player* player;
		//�G�l�~�[�B
		Enemy* enemy;
		//�^�C�g���B
		Title* title;
		//�o�b�N�O�����h�B
		BackGround* background;
		//�^�[���B
		Phase* phase;
		//���[�U�[�C���^�[�t�F�[�X�B
		UI* ui;
		//�}�b�v�����B
		RogueLikeMap* rogueLikeMap;
};

