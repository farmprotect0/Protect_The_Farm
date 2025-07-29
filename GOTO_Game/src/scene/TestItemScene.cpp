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
#include "ScoreManager.h"

void TestItemScene::Initialize() {
	auto camera = Camera::CreateMainCamera();
	auto itemManager = new GameObject(L"�����۸Ŵ���");
	itemManager->AddComponent<ItemManager>();
	auto scoreManager = new GameObject(L"���ھ�Ŵ���");
	scoreManager->AddComponent<ScoreManager>();
}