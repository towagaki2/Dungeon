#pragma once

//ƒ^[ƒ“ŠÇ—B
class Phase
{
public:
	Phase();
	~Phase(); 
	void Update();
	int GetTaan()
	{
		return taan;
	}

	enum Taan
	{
		plTaan,
		enTaan,
	};
	enum Taan mati = plTaan;
private:
	

	int taan = 0;
};

