#pragma once
#include "font.h"
class UI
{
public:
	UI();
	~UI();
	/// <summary>
	/// Gemeobjectから継承したLoat関数。
	/// </summary>
	/// <returns>
	/// 成功でtrue、失敗でfalse。
	/// </returns>
	bool Load();
	/// <summary>
	/// Gameobjectから継承したUpdate関数。
	/// </summary>
	void Update();
	/// <summary>
	/// Gameobjectから継承したDraw関数。
	/// </summary>
	void Draw();
	/// <summary>
	/// Gameobjectから継承したpostDraw関数。
	/// </summary>
	void PostDraw(bool END);
private:
Font m_font;											//文字表示のインスタンス。
};

