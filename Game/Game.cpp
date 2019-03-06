#include "stdafx.h"
#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::Update()
{
	//�Q�[���p�b�h�̍X�V�B	
	for (auto& pad : g_pad) {
		pad.Update();
	}
	//�����G���W���̍X�V�B
	g_physics.Update();
	//�J�����̍X�V�B
	g_camera3D.Update();
	//�v���C���[�̍X�V�B
	player.Update();
	//�G�l�~�[�̍X�V�B
	enemy.Update();
	//�o�b�N�O�����h�̍X�V�B
	background.Update();
	//�^�[���̍X�V�B
	phase.Update();
}

void Game::Draw()
{
	//�v���C���[�̕`��B
	player.Draw();
	//�G�l�~�[�̕`��B
	enemy.Draw();
	//�o�b�N�O�����h�̕`��B
	background.Draw();
}