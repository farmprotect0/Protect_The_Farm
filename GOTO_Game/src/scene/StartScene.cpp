#include "StartScene.h"
#include "CrosshairPrefab.h"
#include "StartMenuPrefab.h"
#include <Camera.h>
#include <SpriteRenderer.h>
#include <Canvas.h>
#include <Text.h>
#include <RectTransform.h>
#include <Screen.h>

void StartScene::Initialize()
{
	//ī�޶�
	auto mainCam = Camera::CreateMainCamera();

	if (!GameObject::Find(L"Player1") && !GameObject::Find(L"Player2"))
	{
		auto CrossHair1GO = CrosshairPrefab::CreateCrosshair(0);
		auto CrossHair2GO = CrosshairPrefab::CreateCrosshair(1);

		CrossHair1GO->name = L"Player1";
		CrossHair2GO->name = L"Player2";

		//Ŀ�� ����
		Object::DontDestroyOnLoad(CrossHair1GO);
		Object::DontDestroyOnLoad(CrossHair2GO);
	}

	StartMenuPrefab::CreateStartMenu();
}
