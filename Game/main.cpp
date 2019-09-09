#include "stdafx.h"
#include "system/system.h"
#include "Game.h"
#include"title.h"
#include"RogueLikeMap.h"

///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{

	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");

	//�J�������������B
	g_camera3D.SetTarget({ 10.0f,10.0f,10.0f });
	g_camera3D.SetPosition({ 10.0f,800.0f,10.10f });
	g_camera3D.SetFar(10000.0f);
	//�J�����̍X�V�B
	g_camera3D.Update();
	while (DispatchWindowMessage() == true)
	{

		//�`��J�n�B
		g_graphicsEngine->BegineRender();
		//�Q�[���p�b�h�̍X�V�B	
		for (auto& pad : g_pad) {
			pad.Update();
		}
		//�Q�[���̍X�V�B
		Game::GetGame().Update();
		//�Q�[���̕`��B
		Game::GetGame().Draw();
		//�`��I���B
		g_graphicsEngine->EndRender();
	}
}