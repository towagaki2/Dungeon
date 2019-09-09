#pragma once
#include "Phase.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyManager.h"
#include "HorrorMan.h"
#include "title.h"
#include "level/Level.h"
#include "BackGround.h"
#include "GameEnd.h"
#include "UI.h"
#include "RogueLikeMap.h"
#include "Stairs.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
#include "Item.h"

class Player;
class Phase;
class Enemy;
class EnemyManager;
class HorrorMan;
class titel;
class GameEnd;
class UI;
class RogueLikeMap;
class Stairs;
class Item;

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
		Enemy* GetEnemy(int no)
		{
			return enemyManager->GetEnemy(no);
			
		}
		//�G�l�~�[�}�l�[�W���[�̃Q�b�^�[�B
		EnemyManager* GetEnemymanager()
		{
			return  enemyManager;
		}
		//�z���[�}���̃Q�b�^�[�B
		Enemy* GetHorrorMan()
		{
			return enemyManager->GetEnemy(1);
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
		

		void EndAndStrat();			//�I���Ǝn�܂�B

	protected:
		Game();
	private:

		int kai=0;

		//�T�E���h�G���W���B
		CSoundEngine m_soundEngine;			
		//BGM�B
		CSoundSource m_bgm;		
		//�v���C���[�̃|�W�V�����B
		CVector3 PlayerPos;
		//�v���C���[�B
		Player* player;
		//�G�l�~�[�}�l�[�W���[�B
		EnemyManager* enemyManager;
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
		//�K�i�B
		Stairs* stairs;
		//�A�C�e���B
		Item* item;
};

