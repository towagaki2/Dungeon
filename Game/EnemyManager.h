#pragma once
#include "Game.h"
#include "GameDefine.h"
class Enemy;

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();
	void Update();


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
	int EnemyDeci[teki];			//�G�l�~�[�̎�ނ����߂�
	Enemy * enemy = nullptr;		//�G�l�~�[
	int ran = 0;					//�����_���Ō��߂�ꂽ�����̓��ꕨ�B
	int m_number = 0;				//�G�l�~�[�̃J�E���^�[�B
};

