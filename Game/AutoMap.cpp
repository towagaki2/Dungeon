#include "stdafx.h"
#include "AutoMap.h"

/*�}�b�v�n�f�[�^*/
const size_t MAPX_RLk = 64; //�}�b�v�c�T�C�Y
const size_t MAPY_RLk = 32;   //�}�b�v���T�C�Y

							  //����̃}�b�v�f�[�^�������܂�
class RogueLikeMap
{
public:
	RogueLikeMap(const size_t var_) :mapData(var_)
	{
	
	}
	RogueLikeMap() = default;

	//���������\�ȃ}�b�v
	size_t mapData = 1;
};
AutoMap::AutoMap()
{
	//����
	int time = 30;

	DungeonMap_RL dng; //�_���W����
	std::vector<std::vector<RogueLikeMap>> maprl(MAPX_RLk, std::vector<RogueLikeMap>(MAPY_RLk, 0));


	if (rogueLikeMapMake(&dng, maprl)) {
		throw;
	}
	size_t k = maprl[0][0].mapData;
}


AutoMap::~AutoMap()
{
}
