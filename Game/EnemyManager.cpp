#include "stdafx.h"
#include "Game.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	enemy[0] = new Enemy(0, 0, 0);
	enemy[1] = new HorrorMan(7, 7, 5);

	//エネミーを10体だす。
	for (int i = 0; i < teki; i++)
	{
		std::random_device rnd;     // 非決定的な乱数生成器を生成
		std::mt19937 Rand(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
		std::uniform_int_distribution<> GetRand(1, 1);        // [0, 99] 範囲の一様乱数
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
	//エネミーの更新。
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
				std::random_device rnd;     // 非決定的な乱数生成器を生成
				std::mt19937 Rand(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
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
	//エネミーの描画。
	if (enemy[1] != nullptr) {
		enemy[1]->Draw();
	}
}