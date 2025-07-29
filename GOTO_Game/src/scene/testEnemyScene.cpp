#include "testEnemyScene.h"
#include <iostream>
#include <GameObject.h>
#include <Transform.h>
#include <RenderManager.h>
#include <InputManager.h>
#include <TimeManager.h>
#include <SceneManager.h>
#include <ResourceManager.h>

//#include "MoveEnemy.h"
#include "Camera.h"
#include "EnemySpawner.h"
#include "CameraMove.h"

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
	camera_GO->GetComponent<Camera>()->SetRect({ 0,0,1.0f,1.0f });


}
