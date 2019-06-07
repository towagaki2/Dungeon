#include "stdafx.h"
#include "RogueLikeMap.h"
#include"GameDefine.h"



RogueLikeMap::~RogueLikeMap()
{
}
std::vector<std::vector<RogueLikeMap>> RogueLikeMap::NewMap()
{

	DungeonMap_RL dng; //ƒ_ƒ“ƒWƒ‡ƒ“
	std::vector<std::vector<RogueLikeMap>> maprl(MAPX_RLk, std::vector<RogueLikeMap>(MAPY_RLk, 0));

	if (rogueLikeMapMake(&dng, maprl)) {
		throw;
	}
	return maprl;
}