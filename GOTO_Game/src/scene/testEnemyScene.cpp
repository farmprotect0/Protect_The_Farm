#include "testEnemyScene.h"

#include "CrosshairPrefab.h"
#include "StartMenuPrefab.h"
#include <Camera.h>
#include <SpriteRenderer.h>
#include <Canvas.h>
#include <Text.h>
#include <RectTransform.h>
#include <Screen.h>

#include "Camera.h"
#include "CameraMove.h"
#include "Canvas.h"

#include "EnemySpawner.h"
#include "ItemManager.h"
#include "GameManager.h"

using namespace std;

using namespace GOTOEngine;

void testEnemyScene::Initialize()
{
	//*/ Start Scene
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
	//*/

	//*/ Play Scene
	auto player1CamGO = Camera::CreateMainCamera();
	auto player1Cam = player1CamGO->GetComponent<Camera>();
	player1Cam->SetRect({ 0.0f, 0.0f, 0.5f, 1.0f });
	player1Cam->SetRenderLayer(1 << 1);

	auto player2CamGO = Camera::CreateSubCamera();
	auto player2Cam = player2CamGO->GetComponent<Camera>();
	player2Cam->SetRect({ 0.5f, 0.0f, 0.5f, 1.0f });
	player2Cam->SetRenderLayer(1 << 2);

	//auto BackgroundGO = new GameObject(L"Background");
	//auto BackgdoundSprite = BackgroundGO->AddComponent<SpriteRenderer>();
	//BackgdoundSprite->SetSprite(L"../Resources/Demo/BG.png");
	//BackgroundGO->GetTransform()->SetLossyScale({ 1.35f, 1.35f });

	auto canvas = new GameObject(L"Canvas");
	canvas->AddComponent<Canvas>();
	auto itemManager = new GameObject(L"아이템매니저");
	itemManager->AddComponent<ItemManager>();
	auto gameManager = new GameObject(L"스코어매니저");
	gameManager->AddComponent<GameManager>();
	auto spawner = new GameObject(L"enemySpawner");
	spawner->AddComponent<EnemySpawner>();
	//*/
}
