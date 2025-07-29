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

	auto BackgroundGO = new GameObject(L"Background");	
	auto BackgdoundSprite = BackgroundGO->AddComponent<SpriteRenderer>();
	BackgdoundSprite->SetSprite(L"../Resources/Demo/BG.png");
	BackgroundGO->GetTransform()->SetLossyScale({ 1.35f, 1.35f});
}
