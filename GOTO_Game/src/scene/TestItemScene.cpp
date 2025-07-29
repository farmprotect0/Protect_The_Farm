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
	auto itemManager = new GameObject(L"�����۸Ŵ���");
	itemManager->AddComponent<ItemManager>();
	auto gameManager = new GameObject(L"���ھ�Ŵ���");
	gameManager->AddComponent<GameManager>();
}