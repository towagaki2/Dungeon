#pragma once
#include "font.h"
class UI
{
public:
	UI();
	~UI();
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
Font m_font;											//�����\���̃C���X�^���X�B
};

