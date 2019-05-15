#pragma once
#include "font.h"

class Font;

class title
{
public:
	title();
	~title();
	void Update();
	void Draw();
	bool GetTitleF()
	{
		return titleF;
	}
private:

	bool titleF = false;								//�^�C�g���t���O�B
	SkinModel m_titleModel;								//�^�C�g�����f���B
	CVector3 m_position = {0.0f,300.0f,0.0f};				//���W�B
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B	
	Font m_font;										//�����\���̃C���X�^���X�B
};

