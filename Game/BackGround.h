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

	
	SkinModel m_model[MAPX_RLk][MAPY_RLk];									//�X�L�����f���B
	CVector3 m_position = CVector3::Zero();				//���W�B
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B	
};

