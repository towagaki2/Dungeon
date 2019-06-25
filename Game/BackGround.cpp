#include "stdafx.h"
#include "BackGround.h"
#include"GameDefine.h"

BackGround::BackGround()
{
	RogueLikeMap map;
	auto mapdate = map.NewMap();
	CVector3 pos = CVector3::Zero();
	mapArray.resize(MAPX_RLk);
	for (int i = 0; i < MAPX_RLk; i++) {
		mapArray[i].resize(MAPX_RLk);
		for (int j = 0; j < MAPY_RLk; j++) {
			pos.x += masu;
			if (mapdate[i][j].mapData!=1) {
				//cmoファイルの読み込み。
				m_model[i][j].Init(L"Assets/modelData/yukaTail.cmo");
				count++;
				m_model[i][j].UpdateWorldMatrix(pos, CQuaternion::Identity(), { 1.0f,1.0f,1.0f });
;
			}else
			{
				m_model[i][j].Init(L"Assets/modelData/kabe.cmo");
				//cmoファイルの読み込み。
				m_model[i][j].UpdateWorldMatrix(pos, CQuaternion::Identity(), {0.05f,0.05f,0.05f});
			
			}
			mapArray[i][j] = mapdate[i][j];
			m_position[i][j] = pos;
		}
		pos.y = 0.0f;
		pos.z += masu;
		pos.x = 0.0f;
	}
}


BackGround::~BackGround()
{
}

void BackGround::Update()
{
}

void BackGround::Draw()
{
	for (int i = 0; i < MAPX_RLk; i++) {
		for (int j = 0; j < MAPY_RLk; j++) {
			m_model[i][j].Draw(
				g_camera3D.GetViewMatrix(),
				g_camera3D.GetProjectionMatrix()
			);
		}
	}
}