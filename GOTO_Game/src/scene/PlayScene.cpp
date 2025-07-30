#include "PlayScene.h"
#include <Camera.h>
#include <Image.h>
#include <Canvas.h>
#include <RectTransform.h>
#include <SpriteRenderer.h>
#include "CrosshairPrefab.h"

#include "ItemManager.h"
#include "GameManager.h"
#include "CameraShaker.h"
#include "CrosshairFire.h"
#include "EnemySpawner.h"

void PlayScene::Initialize()
{
	auto player1CamGO = Camera::CreateMainCamera();
	auto player1Cam = player1CamGO->GetComponent<Camera>();
	player1Cam->SetRect({ 0.0f, 0.0f, 0.5f, 1.0f });
	player1Cam->SetRenderLayer(1 << 1);
	auto player1CamShaker = player1Cam->AddComponent<CameraShaker>();
	auto player1CrosshairGO = GameObject::Find(L"Player1");
	if (Object::IsValidObject(player1CrosshairGO))
	{
		player1CrosshairGO->GetComponent<CrosshairFire>()->onFire.Add([player1CamShaker](int id) { player1CamShaker->ShakeCamera(24, 55, 8); });
	}

	auto player2CamGO = Camera::CreateSubCamera();
	auto player2Cam = player2CamGO->GetComponent<Camera>();
	player2Cam->SetRect({ 0.5f, 0.0f, 0.5f, 1.0f });
	player2Cam->SetRenderLayer(1 << 2);
	auto player2CamShaker = player2Cam->AddComponent<CameraShaker>();
	auto player2CrosshairGO = GameObject::Find(L"Player2");
	if (Object::IsValidObject(player2CrosshairGO))
	{
		player2CrosshairGO->GetComponent<CrosshairFire>()->onFire.Add([player2CamShaker](int id) { player2CamShaker->ShakeCamera(24, 55, 8); });
	}

	auto BackgroundGO = new GameObject(L"Background");	
	auto BackgdoundSprite = BackgroundGO->AddComponent<SpriteRenderer>();
	BackgdoundSprite->SetSprite(L"../Resources/Demo/BG.png");
	BackgroundGO->GetTransform()->SetLossyScale({ 1.35f, 1.35f});

	auto canvas = new GameObject(L"Canvas");
	canvas->AddComponent<Canvas>();
	auto itemManager = new GameObject(L"�����۸Ŵ���");
	itemManager->AddComponent<ItemManager>();
	auto gameManager = new GameObject(L"���ھ�Ŵ���");
	gameManager->AddComponent<GameManager>();
	auto spawner = new GameObject(L"enemySpawner");
	spawner->AddComponent<EnemySpawner>();
}
