#pragma once

//ターン管理。
class Phase
{
public:
	enum Taan
	{
		plTaan,			//プレイヤーのターン。
		enTaan,			//エネミーのターン。
	};

	Phase();
	~Phase(); 
	void Update();
	Taan GetTaan()
	{
		return mati;
	}

private:
	Taan mati = plTaan;
	int PlHun=0;
};

