#include "stdafx.h"
#include "system/system.h"
#include "Game.h"
#include "Player.h"



///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");

	//�v���C���[�B
	//Player player;

	//�Q�[���B
	Game game;

	//�J�������������B
	
	g_camera3D.SetTarget({0.0f,0.0f,0.0f});
	g_camera3D.SetFar(10000.0f);

	CVector3 PlayerPos;
	//�Q�[�����[�v�B
	while (DispatchWindowMessage() == true)
	{
		PlayerPos = game.GetPlayer()->GetPosition();
		g_camera3D.SetPosition({ PlayerPos.x+10.0f,1000.0f, PlayerPos.z+10.0f });

		g_camera3D.SetTarget({ PlayerPos.x + 10.0f,0.0f, PlayerPos.z+10.1f});
		//�`��J�n�B
		g_graphicsEngine->BegineRender();
		
		//�Q�[���̍X�V�B
		game.Update();
		//�Q�[���̕`��B
		game.Draw();

		//�`��I���B
		g_graphicsEngine->EndRender();
	}
}