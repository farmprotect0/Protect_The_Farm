#include "EnemySpawner.h"

#include "BaseEnemyObject.h"
#include "MoveEnemy.h"
#include "GimmickEnemy.h"
#include "ItemEnemy.h"

#include "MoveLeftRight.h"
#include "MoveUpDown.h"
#include "MoveCircle.h"

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
	if (INPUT_GET_KEYDOWN(KeyCode::Z)) // p1 enemy 토끼 생성
	{
		GameObject* baseObject = CreateEnemy({ 0,0 }, 0b0111); // flag만 변경 하면 됩니다.

		baseObject->GetComponent<BaseEnemyObject>()->SetEnemyLayer(1);
		baseObject->layer = 1 << 1;


		m_p1Enemy.push_back(baseObject);
		std::cout << "current p1 objects size : " << m_p1Enemy.size() << std::endl;
	}
	if (INPUT_GET_KEYUP(KeyCode::X)) // p1 enemy 까마귀 생성
	{


	}
	if (INPUT_GET_KEYDOWN(KeyCode::O)) // p2 enemy 토끼 생성
	{
		GameObject* baseObject = CreateEnemy({ 0,0 }, 0b0111); // flag만 변경 하면 됩니다.

		baseObject->GetComponent<BaseEnemyObject>()->SetEnemyLayer(2);
		baseObject->layer = 1 << 2;

		m_p2Enemy.push_back(baseObject);
		std::cout << "current p2 objects size : " << m_p2Enemy.size() << std::endl;
	}
	if (INPUT_GET_KEYDOWN(KeyCode::P)) // p2 enemy 까마귀 생성
	{

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

bool GOTOEngine::EnemySpawner::SetDeleteEnemy(int _layer, GameObject* enemy)  
{  
   if (_layer == 1)  
   {  
       auto it = std::find(m_p1Enemy.begin(), m_p1Enemy.end(), enemy);  
       if (it != m_p1Enemy.end())  
       {  
           m_p1Enemy.erase(it);  
           return true;  
       }  
   }  
   else if (_layer == 2)  
   {  
       auto it = std::find(m_p2Enemy.begin(), m_p2Enemy.end(), enemy);  
       if (it != m_p2Enemy.end())  
       {  
           m_p2Enemy.erase(it);  
           return true;  
       }  
   }  

   return false;  
}

void GOTOEngine::EnemySpawner::Setp1EnemyAllDestroy()
{
	for (auto& enemy : m_p1Enemy)
	{
		if (enemy)
		{
			GameObject::Destroy(enemy);
			enemy = nullptr;
		}
	}
	m_p1Enemy.clear();
}
void GOTOEngine::EnemySpawner::Setp2EnemyAllDestroy()
{
	for (auto& enemy : m_p2Enemy)
	{
		if (enemy)
		{
			GameObject::Destroy(enemy);
			enemy = nullptr;
		}
	}
	m_p2Enemy.clear();
}
