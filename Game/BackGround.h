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
		std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
		std::mt19937 Rand(rnd());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
		std::uniform_int_distribution<> GetRand(0, count);        // [0, 99] �͈͂̈�l����
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
		std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
		std::mt19937 Rand(rnd());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
		std::uniform_int_distribution<> GetRand(0, count);        // [0, 99] �͈͂̈�l����
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
	SkinModel m_model[MAPX_RLk][MAPY_RLk];				//�X�L�����f���B
	CVector3 m_position[MAPX_RLk][MAPY_RLk];				//���W�B
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B	
	int count = 0;
};

