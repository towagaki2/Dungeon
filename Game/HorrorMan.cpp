#include "stdafx.h"
#include "HorrorMan.h"
#include "Game.h"


HorrorMan::HorrorMan(int HP, int ATK, int DEF):Enemy(HP, ATK, DEF)
{
	horrorHP = HP;
	horrorATK = ATK;
	horrorDEF = DEF;
	this->SetenHP(horrorHP);
}


HorrorMan::~HorrorMan()
{
}

void HorrorMan::Update()
{	
}