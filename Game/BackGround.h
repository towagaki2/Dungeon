#pragma once
#include "physics/PhysicsStaticObject.h"
#include"GameDefine.h"

class BackGround
{
public:
	BackGround();
	~BackGround();
	void Update();
	void Draw();
	

private:

	
	SkinModel m_model[MAPX_RLk][MAPY_RLk];									//スキンモデル。
	CVector3 m_position = CVector3::Zero();				//座標。
	CVector3 m_scale = CVector3::One();					//拡大率。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。	
};

