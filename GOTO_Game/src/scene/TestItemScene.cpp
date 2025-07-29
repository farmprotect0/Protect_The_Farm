#include "TestItemScene.h"
#include <iostream>
#include <GameObject.h>
#include <Transform.h>
#include <RenderManager.h>
#include <InputManager.h>
#include <TimeManager.h>
#include <SceneManager.h>
#include <ResourceManager.h>
#include "Camera.h"
#include "ItemManager.h"
#include "GameManager.h"
#include "Canvas.h"

void TestItemScene::Initialize() {
	auto camera = Camera::CreateMainCamera();
	auto canvas = new GameObject(L"Canvas");
	canvas->AddComponent<Canvas>();
	auto itemManager = new GameObject(L"아이템매니저");
	itemManager->AddComponent<ItemManager>();
	auto gameManager = new GameObject(L"스코어매니저");
	gameManager->AddComponent<GameManager>();
}