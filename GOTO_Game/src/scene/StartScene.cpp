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
	//카메라
	auto mainCam = Camera::CreateMainCamera();

	if (!GameObject::Find(L"Player"))
	{
		auto CrossHair1GO = CrosshairPrefab::CreateCrosshair(0);
		auto CrossHair2GO = CrosshairPrefab::CreateCrosshair(1);

		CrossHair1GO->GetComponent<SpriteRenderer>()->SetRenderLayer(1 << 1);
		CrossHair2GO->GetComponent<SpriteRenderer>()->SetRenderLayer(1 << 2);

		//커서 유지
		Object::DontDestroyOnLoad(CrossHair1GO);
		Object::DontDestroyOnLoad(CrossHair2GO);
	}

	SCENE_CHANGE_SCENE(L"PlayScene");
}
