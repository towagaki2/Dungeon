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
		std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
		std::mt19937 Rand(rnd());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
		std::uniform_int_distribution<> GetRand(1, count);        // [0, 99] �͈͂̈�l����
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
		std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
		std::mt19937 Rand(rnd());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
		std::uniform_int_distribution<> GetRand(1, count);        // [0, 99] �͈͂̈�l����
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
	SkinModel m_model[MAPX_RLk][MAPY_RLk];				//�X�L�����f���B
	CVector3 m_position[MAPX_RLk][MAPY_RLk];				//���W�B
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B	
	int count = 0;
};

