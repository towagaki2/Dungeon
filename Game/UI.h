#pragma once

class GameEnd;
class UI
{
public:
	UI(bool end);
	~UI();
	void Update();
	GameEnd* gameEnd;
private:

	SkinModel m_model;									//�X�L�����f���B	
	bool End;
};

