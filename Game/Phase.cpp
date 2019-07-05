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
			for (int i = 0; i < teki; i++) {
				if (Game::GetGame().GetEnemy(i) != nullptr) {
					Game::GetGame().GetEnemy(i)->SetEneSummaryF(false);
				}
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
		for (int i = 0; i < teki; i++) {
			if (Game::GetGame().GetEnemy(i) != nullptr) {
				if (Game::GetGame().GetEnemy(i)->GetEneSummaryF() != true)
				{
					break;
				}
			}
		}
		mati = plTaan;
		Game::GetGame().GetPlayer()->SetPlSummaryF(false);
		break;
	}
}