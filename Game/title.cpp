#include "stdafx.h"
#include "title.h"


title::title()
{
	m_titleModel.Init(L"Assets/modelData/tiitel.cmo");
	m_titleModel.UpdateWorldMatrix(m_position, m_rotation, {10.0f,10.0f,10.0f});
}


title::~title()
{
}
void title::Update()
{

	if (titleF == false &&g_pad[0].IsTrigger(enButtonA))
	{
		titleF = true;
	}
	
}
void title::Draw()
{
	if (titleF == false) {
		m_titleModel.Draw(
			g_camera3D.GetViewMatrix(),
			g_camera3D.GetProjectionMatrix()
		);
		m_font.BeginDraw();	//�t�H���g�̕`��J�n�B
		wchar_t toubatu[256];
		swprintf_s(toubatu, L"�s�v�c�ɂ����������_���W����");	//�^�C�g����\������B
		m_font.Draw(
			toubatu,		//�\�����镶����B
			{ -300.0f,100.0f },			//�\��������W�B0.0f, 0.0����ʂ̒��S�B
			{ 1.0f,0.0f,0.0f,1.0f }, 0.0, 4.0, { 1.0f,1.0f }
		);
		swprintf_s(toubatu, L"A�{�^���������Ă�");	//A�{�^���������Ă˂�\������B
		m_font.Draw(
			toubatu,		//�\�����镶����B
			{ 0.0f,-200.0f },			//�\��������W�B0.0f, 0.0����ʂ̒��S�B
			{ 1.0f,0.0f,0.0f,1.0f }, 0.0, 3.0, { 1.0f,1.0f }
		);
		m_font.EndDraw();		//�t�H���g�̕`��I���B
	}
}