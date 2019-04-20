#include "stdafx.h"
#include "GameEnd.h"
#include "Game.h"
#include "UI.h"


GameEnd::GameEnd(bool end)
{
	if (end == true)
	{
		ui=new UI;
	}
	else
	{
		ui = new UI;
	}
}


GameEnd::~GameEnd()
{
}

void GameEnd::Update()
{
	ui->PostDraw();
		
}