#include "stdafx.h"
#include "Game.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	enemy[0] = new Enemy(0, 0, 0);
	enemy[1] = new HorrorMan(7, 7, 5);

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
	delete enemy[0];
	if (enemy[1] != nullptr) {
		delete enemy[1];
		enemy[1] = nullptr;
	}

}

void EnemyManager::Update()
{
	//�G�l�~�[�̍X�V�B
	if (enemy[1] != nullptr) {
		enemy[1]->Update();
	}
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
	if (enemy[1] != nullptr) {
		if (Game::GetGame().GetEnemy()->GetdeathF() == true)
		{
			delete enemy[1];
			enemy[1] = nullptr;
		}
	}
}

void EnemyManager::Draw()
{
	//�G�l�~�[�̕`��B
	if (enemy[1] != nullptr) {
		enemy[1]->Draw();
	}
}