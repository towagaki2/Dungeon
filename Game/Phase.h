#pragma once

//�^�[���Ǘ��B
class Phase
{
public:
	enum Taan
	{
		plTaan,			//�v���C���[�̃^�[���B
		enTaan,			//�G�l�~�[�̃^�[���B
		taan,			//�^�[���̑����B
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

