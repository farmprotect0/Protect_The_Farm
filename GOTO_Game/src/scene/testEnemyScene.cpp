#include "testEnemyScene.h"
#include <iostream>
#include <GameObject.h>
#include <Transform.h>
#include <RenderManager.h>
#include <InputManager.h>
#include <TimeManager.h>
#include <SceneManager.h>
#include <ResourceManager.h>

#include "Camera.h"
#include "CameraMove.h"
#include "Canvas.h"

#include "EnemySpawner.h"
#include "ItemManager.h"
#include "ScoreManager.h"


using namespace std;

using namespace GOTOEngine;

void testEnemyScene::Initialize()
{

	auto spawner = new GameObject(L"enemySpawner");
	spawner->GetTransform()->SetPosition({ 0,0 });
	spawner->GetTransform()->SetLossyScale({ 2.0f,2.0f });

	spawner->AddComponent<EnemySpawner>();

	auto camera_GO = Camera::CreateMainCamera();
	camera_GO->AddComponent<CameraMove>();
	camera_GO->GetComponent<Camera>()->SetRect({ 0, 0, 1.0f,1.0f });


	auto canvas = new GameObject(L"Canvas");
	canvas->AddComponent<Canvas>();
	auto itemManager = new GameObject(L"아이템매니저");
	itemManager->AddComponent<ItemManager>();
	auto scoreManager = new GameObject(L"스코어매니저");
	scoreManager->AddComponent<ScoreManager>();

}
