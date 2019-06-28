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
	CVector3 GetMapPosition(int& tate,int& yoko)
	{
		std::random_device rnd;     // 非決定的な乱数生成器を生成
		std::mt19937 Rand(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
		std::uniform_int_distribution<> GetRand(0, count);        // [0, 99] 範囲の一様乱数
		int ran=GetRand(Rand);
		int cou = 0;
		for (int i = 0; i < MAPX_RLk; i++) {
			for (int j = 0; j < MAPY_RLk; j++) {
				if (mapArray[i][j].mapData != 1) {
					if (ran >= cou)
					{
						cou++;
					}
					else {
						tate = i;
						yoko = j;
						return m_position[i][j];

						break;
					}

				}
			}
		}
		return m_position[0][0];
	}
	CVector3 GetMapPosition()
	{
		std::random_device rnd;     // 非決定的な乱数生成器を生成
		std::mt19937 Rand(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
		std::uniform_int_distribution<> GetRand(0, count);        // [0, 99] 範囲の一様乱数
		int ran = GetRand(Rand);
		int cou = 0;
		for (int i = 0; i < MAPX_RLk; i++) {
			for (int j = 0; j < MAPY_RLk; j++) {
				if (mapArray[i][j].mapData != 1) {
					if (ran >= cou)
					{
						cou++;
					}
					else {
						return m_position[i][j];

						break;
					}

				}
			}
		}
		return m_position[0][0];
	}
	bool GetKabeOrYuka(int tate,int yoko)
	{
		if (mapArray[tate][yoko].mapData == 1)
		{
			return true;
		}
		return false;
	}
private:
	std::vector<std::vector<RogueLikeMap>> mapArray;
	SkinModel m_model[MAPX_RLk][MAPY_RLk];				//スキンモデル。
	CVector3 m_position[MAPX_RLk][MAPY_RLk];				//座標。
	CVector3 m_scale = CVector3::One();					//拡大率。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。	
	int count = 0;
};

