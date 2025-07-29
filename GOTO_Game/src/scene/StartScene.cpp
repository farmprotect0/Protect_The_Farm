#include "StartScene.h"
#include "CrosshairPrefab.h"
#include <Camera.h>
#include <SpriteRenderer.h>


void StartScene::Initialize()
{
	auto mainCam = Camera::CreateMainCamera();

	//ī�޶�
	auto CrossHair1GO = CrosshairPrefab::CreateCrosshair(0);
	auto CrossHair2GO = CrosshairPrefab::CreateCrosshair(1);

	CrossHair1GO->GetComponent<SpriteRenderer>()->SetRenderLayer(1 << 1);
	CrossHair2GO->GetComponent<SpriteRenderer>()->SetRenderLayer(1 << 2);

	//Ŀ�� ����
	Object::DontDestroyOnLoad(CrossHair1GO);
	Object::DontDestroyOnLoad(CrossHair2GO);
}
