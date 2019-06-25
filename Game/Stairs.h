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
	SkinModel m_model;									//�X�L�����f���B
	CVector3 m_position = CVector3::Zero();				//���W�B
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B	

	bool stairsF = false;
};

