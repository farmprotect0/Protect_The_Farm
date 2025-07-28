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
#include "EnemySpawner.h"

using namespace std;

using namespace GOTOEngine;

void testEnemyScene::Initialize()
{

	auto spawner = new GameObject(L"enemySpawner");
	spawner->GetTransform()->SetPosition({ 0,0 });
	spawner->GetTransform()->SetLossyScale({ 2.0f,2.0f });

	spawner->AddComponent<EnemySpawner>();
}
