#pragma once
#include "physics/PhysicsStaticObject.h"
#include"GameDefine.h"
#include"RogueLikeMap.h"

class CharaDeta;

class BackGround
{
public:
	BackGround();
	~BackGround();
	void Update();
	void Draw();
	template <class T>
	CVector3 GetMapPosition(int& tate,int& yoko,T point)
	{
		std::random_device rnd;     // 非決定的な乱数生成器を生成
		std::mt19937 Rand(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
		std::uniform_int_distribution<> GetRand(1, count);        // [0, 99] 範囲の一様乱数
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
						Roomcall(mapArray[i][j].roomNo, point);
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
		std::uniform_int_distribution<> GetRand(1, count);        // [0, 99] 範囲の一様乱数
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
	void deletedata(int No, CharaDeta* point)
	{
		if (No >= 0)
		{
			Room[No].erase(std::remove(Room[No].begin(), Room[No].end(), (CharaDeta*)point), Room[No].end());
		}
	}
	template <class T>
	bool GetKabeOrYuka(int tate,int yoko, T point)
	{
		if (mapArray[tate][yoko].mapData != 1)
		{
			auto No = mapArray[tate][yoko].roomNo;

			if (No != 0)
			{	
				Roomcall(No, point);
			}
			else
			{
				auto no = ((CharaDeta*)point)->RoomNo;
				if (no >= 0) {
					Room[no].erase(std::remove(Room[no].begin(), Room[no].end(), (CharaDeta*)point), Room[no].end());
				}
				((CharaDeta*)point)->RoomNo = -1;
			}
			return false;
		}
		return true;
	}
	template <class T>
	void Roomcall(int No, T point)
	{
		No -= 1;
		if (No >= 0) {
			auto it = std::find(Room[No].begin(), Room[No].end(), (CharaDeta*)point);
			if (it == Room[No].end()) {
				((CharaDeta*)point)->RoomNo = No;
				Room[No].push_back((CharaDeta*)point);
				for (int i = 0; i < Room[No].size(); i++)
				{
					Room[No].at(i)->RoomIn(Room[No]);
				}
			}
		}
	}
private:
	std::vector<std::vector<RogueLikeMap>> mapArray;
	std::vector<std::vector<CharaDeta*>> Room;
	SkinModel m_model[MAPX_RLk][MAPY_RLk];				//スキンモデル。
	CVector3 m_position[MAPX_RLk][MAPY_RLk];				//座標。
	CVector3 m_scale = CVector3::One();					//拡大率。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。	
	int count = 0;
};

