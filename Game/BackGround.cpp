#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
	//cmo�t�@�C���̓ǂݍ��݁B
	m_model.Init(L"Assets/modelData/yuka.cmo");
	//�ÓI�I�u�W�F�N�g�B
	m_phyStaticObject.CreateMeshObject(m_model, CVector3::Zero(), CQuaternion::Identity());

	m_rotation.x = -90.0f;

}


BackGround::~BackGround()
{
}


void BackGround::Update()
{

	//���[���h�s��̍X�V�B
	m_model.UpdateWorldMatrix(CVector3::Zero(), CQuaternion::Identity(), CVector3::One());

}
void BackGround::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);

}