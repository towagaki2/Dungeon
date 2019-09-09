#pragma once
class CharaDeta
{
public:
	CharaDeta();
	~CharaDeta();
	enum CharaType
	{
		player,
		enemy,
		num
	};
	CharaType GetType()
	{
		return m_Type;
	}
	void SetType(CharaType Type)
	{
		m_Type = Type;
	}
	virtual void RoomIn(std::vector<CharaDeta*> date){};
	int RoomNo = 0;
private:
	CharaType m_Type;

};

