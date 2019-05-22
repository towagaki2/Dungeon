#include "stdafx.h"
#include "AutoMap.h"

/*マップ系データ*/
const size_t MAPX_RLk = 64; //マップ縦サイズ
const size_t MAPY_RLk = 32;   //マップ横サイズ

							  //自作のマップデータを扱えます
class RogueLikeMap
{
public:
	RogueLikeMap(const size_t var_) :mapData(var_)
	{
	
	}
	RogueLikeMap() = default;

	//書き換え可能なマップ
	size_t mapData = 1;
};
AutoMap::AutoMap()
{
	//時間
	int time = 30;

	DungeonMap_RL dng; //ダンジョン
	std::vector<std::vector<RogueLikeMap>> maprl(MAPX_RLk, std::vector<RogueLikeMap>(MAPY_RLk, 0));


	if (rogueLikeMapMake(&dng, maprl)) {
		throw;
	}
	size_t k = maprl[0][0].mapData;
}


AutoMap::~AutoMap()
{
}
