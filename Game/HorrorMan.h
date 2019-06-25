#pragma once
#include"Enemy.h"


class HorrorMan : public Enemy
{
public:
	HorrorMan(int HP, int ATK, int DEF);
	~HorrorMan();
	void Update();

	//�G�l�~�[HP�̃Q�b�^�[�B
	int GetenHP()
	{
		return horrorHP;
	}
	//�G�l�~�[HP�̃Z�b�^�[�B
	void SetenHP(int enenHP)
	{
		horrorHP += enenHP;
	}
	//�G�l�~�[DEF�̃Q�b�^�[�B
	int GetenDEF()
	{
		return horrorDEF;
	}
protected:

private:
	Enemy * enemy;						//�G�l�~�[�B	

	int horrorHP = 7;					//�̗͒l�B
	int horrorATK = 7;					//�U���́B
	int horrorDEF = 5;					//�h��́B
	SkinModel m_model;					//�X�L�����f���B

};

