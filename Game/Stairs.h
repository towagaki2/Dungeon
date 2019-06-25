#pragma once
class Stairs
{
public:
	Stairs();
	~Stairs();
	void Update();
	void Draw();
	bool GetStairsF()
	{
		return stairsF;
	}

private:
	SkinModel m_model;									//スキンモデル。
	CVector3 m_position = CVector3::Zero();				//座標。
	CVector3 m_scale = CVector3::One();					//拡大率。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。	

	bool stairsF = false;
};

