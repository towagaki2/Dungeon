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

	bool titleF = false;								//タイトルフラグ。
	SkinModel m_titleModel;								//タイトルモデル。
	CVector3 m_position = {0.0f,300.0f,0.0f};				//座標。
	CVector3 m_scale = CVector3::One();					//拡大率。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。	
	Font m_font;										//文字表示のインスタンス。
};

