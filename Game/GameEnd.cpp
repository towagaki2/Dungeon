#include "stdafx.h"
#include "GameEnd.h"



GameEnd::GameEnd()
{
	
}


GameEnd::~GameEnd()
{
}
void GameEnd::PostDraw(bool END)
{
	m_font.BeginDraw();	//�t�H���g�̕`��J�n�B
	wchar_t toubatu[256];
	if (END == true)
	{
		swprintf_s(toubatu, L"�Q�[���N���A�I");	//�G��|�����Ƃ��ɕ\������B

		m_font.Draw(
			toubatu,		//�\�����镶����B
			{ FRAME_BUFFER_W / 4.0f,-FRAME_BUFFER_H / 4.0f },			//�\��������W�B0.0f, 0.0����ʂ̒��S�B
			{ 1.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }

		);
		swprintf_s(toubatu, L"A�������ƃ^�C�g���ɖ߂�");	//�G��|�����Ƃ��ɕ\������B

		m_font.Draw(
			toubatu,		//�\�����镶����B
			{ FRAME_BUFFER_W / 4.0f,-FRAME_BUFFER_H / 4.0f },			//�\��������W�B0.0f, 0.0����ʂ̒��S�B
			{ -200.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 200.0f,1.0f }
			
		);
	}
	if (END == false)
	{
		swprintf_s(toubatu, L"�Q�[���I�[�o�[�I");	//�v���C���[�����񂾂Ƃ��ɕ\������B

		m_font.Draw(
			toubatu,		//�\�����镶����B
			{ FRAME_BUFFER_W / 4.0f,-FRAME_BUFFER_H / 4.0f },			//�\��������W�B0.0f, 0.0����ʂ̒��S�B
			{ 1.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
		);
	}
	m_font.EndDraw();		//�t�H���g�̕`��I���B
}
