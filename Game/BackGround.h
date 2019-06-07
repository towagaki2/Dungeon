#pragma once
#include "physics/PhysicsStaticObject.h"
#include"GameDefine.h"

#include"RogueLikeMap.h"
class BackGround
{
public:
	BackGround();
	~BackGround();
	void Update();
	void Draw();
	CVector3 GetMapPosition()
	{
		for (int i = 0; i < MAPX_RLk; i++) {
			for (int j = 0; j < MAPY_RLk; j++) {
				if (mapArray[i][j].mapData != 1) {
					return m_position[i][j];
					break;

				}
			}
		}
	}

private:
	std::vector<std::vector<RogueLikeMap>> mapArray;
	SkinModel m_model[MAPX_RLk][MAPY_RLk];				//スキンモデル。
	CVector3 m_position[MAPX_RLk][MAPY_RLk];				//座標。
	CVector3 m_scale = CVector3::One();					//拡大率。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。	
};

