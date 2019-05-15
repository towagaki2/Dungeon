#include "stdafx.h"
#include "UI.h"
#include "GameEnd.h"
#include "Game.h"

UI::UI(bool end)
{
	if (end == true)
	{
		gameEnd = new GameEnd;

	}
	else
	{
		gameEnd = new GameEnd;
	}
	End = end;
}


UI::~UI()
{
}

void UI::Update()
{
	gameEnd->PostDraw(End);
}