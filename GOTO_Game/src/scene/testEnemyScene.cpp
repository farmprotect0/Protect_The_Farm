#include "testEnemyScene.h"
#include <iostream>
#include <GameObject.h>
#include <Transform.h>
#include <RenderManager.h>
#include <InputManager.h>
#include <TimeManager.h>
#include <SceneManager.h>
#include <ResourceManager.h>

#include "MoveEnemy.h"

using namespace std;

using namespace GOTOEngine;

void testEnemyScene::Initialize()
{
	GameObject* baseObject = new GameObject(L"까마귀");

	baseObject->GetTransform()->SetPosition({ 0,0 });
	baseObject->GetTransform()->SetLossyScale({ 2.0f,2.0f });


	baseObject->AddComponent<MoveEnemy>();
	baseObject->GetComponent<MoveEnemy>()->Initialize();

}
