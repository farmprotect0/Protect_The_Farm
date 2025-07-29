#include "PlayScene.h"
#include <Camera.h>
#include <Image.h>
#include <Canvas.h>
#include <RectTransform.h>
#include <SpriteRenderer.h>
#include "CrosshairPrefab.h"


void PlayScene::Initialize()
{
	auto player1CamGO = Camera::CreateMainCamera();
	auto player1Cam = player1CamGO->GetComponent<Camera>();
	player1Cam->SetRect({ 0.0f, 0.0f, 0.5f, 1.0f });
	player1Cam->SetRenderLayer(1 << 1);

	auto player2CamGO = Camera::CreateSubCamera();
	auto player2Cam = player2CamGO->GetComponent<Camera>();
	player2Cam->SetRect({ 0.5f, 0.0f, 0.5f, 1.0f });
	player2Cam->SetRenderLayer(1 << 2);

	auto canvasGO = new GameObject(L"UI");
	auto canvas = canvasGO->AddComponent<Canvas>();

	canvas->SetSortOrder(1000); // UI는 높은 렌더링 순서로 설정

	auto simpleImage = new GameObject(L"SimpleImage");
	auto imageComp = simpleImage->AddComponent<Image>();
	
	imageComp->SetSprite(Resource::Load<Sprite>(L"../Resources/Demo/Crosshair.png"));
	simpleImage->GetComponent<RectTransform>()->SetAnchoredPosition({ 960.0f, 540.0f });

	simpleImage->GetComponent<RectTransform>()->SetParent(canvasGO->GetTransform(), false);


	//카메라
	auto CrossHair1GO = CrosshairPrefab::CreateCrosshair(0);
	auto CrossHair2GO = CrosshairPrefab::CreateCrosshair(1);

	CrossHair1GO->GetComponent<SpriteRenderer>()->SetRenderLayer(1 << 1);
	CrossHair2GO->GetComponent<SpriteRenderer>()->SetRenderLayer(1 << 2);

	//커서 유지
	Object::DontDestroyOnLoad(CrossHair1GO);
	Object::DontDestroyOnLoad(CrossHair2GO);
}
