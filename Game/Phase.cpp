#include "stdafx.h"
#include "Phase.h"
#include "Game.h"

Phase::Phase()
{

}


Phase::~Phase()
{
}

void Phase::Update()
{
	switch (mati)
	{
	case plTaan:
		if (Game::GetGame().GetPlayer()->GetPlSummaryF()==1)
		{
			taan = 1;
			mati = enTaan;
		}
		break;
	case enTaan:
		if (Game::GetGame().GetEnemy()->GetEneSummaryF()==1)
		{
			taan = 0;
			mati = plTaan;
		}
		break;
	}
}