#include "stdafx.h"
#include "Game.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	//�G�l�~�[��10�̂����B
	for (int i = 0; i < teki; i++)
	{
		std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
		std::mt19937 Rand(rnd());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
		std::uniform_int_distribution<> GetRand(1, 1);        // [0, 99] �͈͂̈�l����
		ran = GetRand(Rand);
		EnemyDeci[i] = ran;
		m_number++;
	}
}


EnemyManager::~EnemyManager()
{
}

void EnemyManager::Update()
{
	
	switch (syurui)
	{
	case kara:
		for (int i = 0; i < teki; i++)
		{
			if (EnemyDeci[i] == 0)
			{
				std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
				std::mt19937 Rand(rnd());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
				std::uniform_int_distribution<> GetRand(1, 1);        // [0, 99] �͈͂̈�l����
				ran = GetRand(Rand);
				EnemyDeci[i] = ran;
				m_number++;
			}
			if (EnemyDeci[i] == 1)
			{
				syurui = horrorman;
			}
		}
		break;
	case horrorman:
		
		break;
	}
}