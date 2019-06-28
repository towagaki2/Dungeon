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
		if (Game::GetGame().GetPlayer()->GetPlSummaryF()==true)
		{
			mati = enTaan;
			if (Game::GetGame().GetEnemy() != nullptr) {
				Game::GetGame().GetEnemy()->SetEneSummaryF(false);
			}
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
		if (Game::GetGame().GetEnemy() != nullptr) {
			if (Game::GetGame().GetEnemy()->GetEneSummaryF() == true)
			{
				mati = plTaan;
				Game::GetGame().GetPlayer()->SetPlSummaryF(false);
			}
		}
			else {
				mati = plTaan;
				Game::GetGame().GetPlayer()->SetPlSummaryF(false);
			}
		break;
	}
}