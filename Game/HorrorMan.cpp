#include "stdafx.h"
#include "HorrorMan.h"
#include "Game.h"


HorrorMan::HorrorMan(int HP, int ATK, int DEF):Enemy(HP, ATK, DEF)
{
	horrorHP = HP;
	horrorATK = ATK;
	horrorDEF = DEF;
	this->SetenHP(horrorHP);
	//エネミーのレベルアップ処理。
	if (Game::GetGame().GetPlayer()->GetplLV() > LV)
	{
		LV++;
		horrorHP += 5;
		horrorATK += 5;
		horrorDEF += 5;
	}
	
}


HorrorMan::~HorrorMan()
{
}

void HorrorMan::Update()
{	
}