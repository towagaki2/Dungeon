#include "stdafx.h"
#include "Game.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	//エネミーを10体だす。
	for (int i = 0; i < teki; i++)
	{
		std::random_device rnd;     // 非決定的な乱数生成器を生成
		std::mt19937 Rand(rnd());    
		std::uniform_int_distribution<> GetRand(1, 1);        // [0, 99] 範囲の一様乱数
		ran = GetRand(Rand);
		if (ran == 0) {
			enemy[i] = new Enemy(0, 0, 0);
		}
		else {
			enemy[i] = new HorrorMan(7, 7, 5);
		}
		EnemyDeci[i] = ran;
		m_number++;
	}
	int a = 0;
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
	//エネミーの更新。
	for (int i = 0; i < teki; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Update();
		}
		else {
			enemy[i] = new HorrorMan(7, 7, 5);
		}
	}
	
	switch (syurui)
	{
	case kara:
		for (int i = 0; i < teki; i++)
		{
			if (EnemyDeci[i] == 0)
			{
				std::random_device rnd;     // 非決定的な乱数生成器を生成
				std::mt19937 Rand(rnd());   
				std::uniform_int_distribution<> GetRand(1, 1);        // [0, 99] 範囲の一様乱数
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
		if (EnemyDeci[1] == 0)syurui = kara;
		
		break;
	}

	for (int i = 0; i < teki; i++) {
			if (enemy[i] != nullptr) {
				if (enemy[i]->GetdeathF() == true)
				{
					Game::GetGame().GetPlayer()->SetEXP(2);
					delete enemy[i];
					enemy[i] = nullptr;
					EnemyDeci[i] = 0;
					syurui = kara;
				}
			}
		}
}

void EnemyManager::Draw()
{
	for(int i = 0; i < teki; i++)
	//エネミーの描画。
	if (enemy[i] != nullptr) {
		enemy[i]->Draw();
	}
}