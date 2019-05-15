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
			mati = enTaan;
			Game::GetGame().GetEnemy()->SetEneSummaryF(0);
			if (Game::GetGame().GetPlayer()->GetHUN() > 0)
			{
				Game::GetGame().GetPlayer()->SetHUN(-1);
			}
			if (Game::GetGame().GetPlayer()->GetHUN() <= 0)
			{
				Game::GetGame().GetPlayer()->SetplHP(-1);
			}
		}
		break;
	case enTaan:
		if (Game::GetGame().GetEnemy()->GetEneSummaryF()==1)
		{
			mati = plTaan;
			Game::GetGame().GetPlayer()->SetPlSummaryF(0);
		}
		break;
	}
}