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

	//�G�l�~�[�̃Q�b�^�[�B
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
	Enemysyurui syurui = kara;		//�G�l�~�[�̎�ށB
	int EnemyDeci[teki];			//�G�l�~�[�̎�ނ����߂�B						
	Enemy* enemy[2];				//�G�l�~�[�B
	int ran = 0;					//�����_���Ō��߂�ꂽ�����̓��ꕨ�B
	int m_number = 0;				//�G�l�~�[�̃J�E���^�[�B
};

