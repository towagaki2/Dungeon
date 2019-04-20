#pragma once
class UI;
class GameEnd
{

public:
	GameEnd(bool end);
	~GameEnd();
	void Update();
	UI* ui;
	bool End;
};

