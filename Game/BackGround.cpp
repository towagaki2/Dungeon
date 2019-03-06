#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/yuka.cmo");
	//静的オブジェクト。
	m_phyStaticObject.CreateMeshObject(m_model, CVector3::Zero(), CQuaternion::Identity());

	m_rotation.x = -90.0f;

}


BackGround::~BackGround()
{
}


void BackGround::Update()
{

	//ワールド行列の更新。
	m_model.UpdateWorldMatrix(CVector3::Zero(), CQuaternion::Identity(), CVector3::One());

}
void BackGround::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);

}