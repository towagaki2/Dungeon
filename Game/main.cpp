#include "stdafx.h"
#include "system/system.h"
#include "Game.h"
 

///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{

	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");
	//�Q�[���B
	//Game::Create();

	//�J�������������B
	
	g_camera3D.SetTarget({0.0f,0.0f,0.0f});
	g_camera3D.SetFar(10000.0f);


	//�Q�[�����[�v�B
	while (DispatchWindowMessage() == true)
	{
		
		//�`��J�n�B
		g_graphicsEngine->BegineRender();
		
		//�Q�[���̍X�V�B
		Game::GetGame().Update();
		//�Q�[���̕`��B
		Game::GetGame().Draw();

		//�`��I���B
		g_graphicsEngine->EndRender();
	}
	//Game::Destroy();
}