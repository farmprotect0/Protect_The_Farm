#include "StartScene.h"
#include "CrosshairPrefab.h"
#include <Camera.h>
#include <SpriteRenderer.h>
#include <Canvas.h>
#include <Text.h>
#include <RectTransform.h>
#include <Screen.h>

void StartScene::Initialize()
{
	auto mainCam = Camera::CreateMainCamera();

	//카메라
	auto CrossHair1GO = CrosshairPrefab::CreateCrosshair(0);
	auto CrossHair2GO = CrosshairPrefab::CreateCrosshair(1);

	CrossHair1GO->GetComponent<SpriteRenderer>()->SetRenderLayer(1 << 1);
	CrossHair2GO->GetComponent<SpriteRenderer>()->SetRenderLayer(1 << 2);

	auto canvasGO = new GameObject(L"Canvas");
	auto canvas = canvasGO->AddComponent<Canvas>();

	auto TextGO = new GameObject(L"Text");
	auto textComp = TextGO->AddComponent<Text>();

	textComp->SetFont(L"../Resources/Maplestory Light.ttf");
	textComp->text = L"Press Enter to Start";

	textComp->GetTransform()->SetParent(canvasGO->GetTransform());	
	textComp->GetRectTransform()->SetAnchoredPosition({ Screen::GetWidth() * 0.2f, Screen::GetHeight() * 0.2f });

	//커서 유지
	Object::DontDestroyOnLoad(CrossHair1GO);
	Object::DontDestroyOnLoad(CrossHair2GO);
}
