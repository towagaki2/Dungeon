#pragma once
#include "font.h"
class UI;
class GameEnd
{
public:
	GameEnd();
	~GameEnd();
	/// <summary>
	/// Gemeobject����p������Loat�֐��B
	/// </summary>
	/// <returns>
	/// ������true�A���s��false�B
	/// </returns>
	bool Load();
	/// <summary>
	/// Gameobject����p������Update�֐��B
	/// </summary>
	void Update();
	/// <summary>
	/// Gameobject����p������Draw�֐��B
	/// </summary>
	void Draw();
	/// <summary>
	/// Gameobject����p������postDraw�֐��B
	/// </summary>
	void PostDraw(bool END);
private:

	SkinModel m_model;									//�X�L�����f���B
	Font m_font;										//�����\���̃C���X�^���X�B
};

