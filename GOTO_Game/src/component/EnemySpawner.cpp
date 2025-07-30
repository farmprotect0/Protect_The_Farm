#include "EnemySpawner.h"

using namespace GOTOEngine;

EnemySpawner* EnemySpawner::instance = nullptr;

void GOTOEngine::EnemySpawner::Awake()
{
	if (!instance)
	{
		instance = this;
	}
	else
	{
		Destroy(GetGameObject());
	}
}

void GOTOEngine::EnemySpawner::Update()
{
	if (INPUT_GET_KEYDOWN(KeyCode::Q)) // p1 enemy 생성
	{
		GameObject* baseObject = CreateEnemy({ 0,0 }, 0b0111); // flag만 변경 하면 됩니다.

		m_p1Enemy.push_back(baseObject);
		std::cout << "current p1 objects size : " << m_p1Enemy.size() << std::endl;
	}
	if (INPUT_GET_KEYUP(KeyCode::R)) // disable
	{
		//GameObject* baseObject = m_objects[0];


		//m_objects[0]->SetActive(false);

	}
	if (INPUT_GET_KEYDOWN(KeyCode::O)) // p2 enemy 생성
	{
		GameObject* baseObject = CreateEnemy({ 0,0 }, 0b0111); // flag만 변경 하면 됩니다.

		m_p2Enemy.push_back(baseObject);
		std::cout << "current p2 objects size : " << m_p2Enemy.size() << std::endl;
	}
}

GameObject* GOTOEngine::EnemySpawner::CreateEnemy(Vector2 position, int moveFlag)
{
	GameObject* newEnemyObject = new GameObject(L"토끼");
	//newEnemyObject->GetTransform()->SetPosition(position);

	newEnemyObject->AddComponent<GimmickEnemy>();
	newEnemyObject->GetComponent<GimmickEnemy>()->Initialize(rabbit, moveFlag, true);

	// flag 스크립트	부착
	if (moveFlag & MOVE_LEFT_RIGHT) // 0b0001
	{
		newEnemyObject->AddComponent<MoveLeftRight>();
	}
	if (moveFlag & MOVE_UP_DOWN) // 0b0010
	{
		newEnemyObject->AddComponent<MoveUpDown>();
	}
	if (moveFlag & MOVE_CIRCULAR) // 0b0100
	{
		newEnemyObject->AddComponent<MoveCircle>();
	}

	return newEnemyObject;
}