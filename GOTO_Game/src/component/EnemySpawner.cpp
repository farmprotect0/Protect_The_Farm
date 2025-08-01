#include "EnemySpawner.h"
#include "Screen.h"

// enemy
#include "BaseEnemyObject.h"
#include "MoveEnemy.h"
#include "GimmickEnemy.h"
#include "ItemEnemy.h"

// move
#include "MoveLeftRight.h"
#include "MoveUpDown.h"
#include "MoveCircle.h"
#include "MoveParabolic.h"

#include <random>
#include <cstdlib>
#include <ctime>

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
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void GOTOEngine::EnemySpawner::Update()
{
	if (INPUT_GET_KEYDOWN(KeyCode::Q)) // p1 enemy 까마귀 생성 (MoveEnemy)
	{
		GameObject* baseObject = CreateEnemy(E_EnemyType::move);

		baseObject->GetComponent<BaseEnemyObject>()->SetEnemyLayer(1);
		baseObject->layer = 1 << 1;

		// 랜덤
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> distWidth(-0.25f, 0.25f);
		std::uniform_real_distribution<float> distHeight(0.0f, 0.5f);

		baseObject->GetTransform()->SetPosition({ Screen::GetWidth() * distWidth(gen), Screen::GetHeight() * distHeight(gen) });

		m_p1Enemy.push_back(baseObject);
	}
	if (INPUT_GET_KEYUP(KeyCode::W)) // p1 enemy 토끼 생성 (GimmickEnemy)
	{
		GameObject* baseObject = CreateEnemy(E_EnemyType::gimmick);

		baseObject->GetComponent<BaseEnemyObject>()->SetEnemyLayer(1);
		baseObject->layer = 1 << 1;

		//*/ 랜덤
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> distWidth(-0.25f, 0.25f);
		std::uniform_real_distribution<float> distHeight(-0.3f, 0.3f);

		baseObject->GetTransform()->SetPosition({ Screen::GetWidth() * distWidth(gen), Screen::GetHeight() * distHeight(gen) });
		//*/
		baseObject->GetTransform()->SetPosition({ 0.0f, 0.0f });
		m_p1Enemy.push_back(baseObject);
	}
	if (INPUT_GET_KEYUP(KeyCode::E)) // p1 enemy 얼음새 생성 (ItemEnemy)
	{
		GameObject* baseObject = CreateEnemy(E_EnemyType::itemspawn);

		baseObject->GetComponent<BaseEnemyObject>()->SetEnemyLayer(1);
		baseObject->layer = 1 << 1;

		// 랜덤
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> distWidth(-0.25f, 0.25f);
		std::uniform_real_distribution<float> distHeight(0.0f, 0.5f);

		baseObject->GetTransform()->SetPosition({ Screen::GetWidth() * distWidth(gen), Screen::GetHeight() * distHeight(gen) });

		m_p1Enemy.push_back(baseObject);
	}
	if (INPUT_GET_KEYDOWN(KeyCode::I)) // p2 enemy 까마귀 생성 (MoveEnemy)
	{
		GameObject* baseObject = CreateEnemy(E_EnemyType::move);

		baseObject->GetComponent<BaseEnemyObject>()->SetEnemyLayer(2);
		baseObject->layer = 1 << 2;

		// 랜덤
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> distWidth(-0.25f, 0.25f);
		std::uniform_real_distribution<float> distHeight(0.0f, 0.5f);

		baseObject->GetTransform()->SetPosition({ Screen::GetWidth() * distWidth(gen), Screen::GetHeight() * distHeight(gen) });

		m_p2Enemy.push_back(baseObject);
	}
	if (INPUT_GET_KEYDOWN(KeyCode::O)) // p2 enemy 토끼 생성 (GimmickEnemy)
	{
		GameObject* baseObject = CreateEnemy(E_EnemyType::gimmick);

		baseObject->GetComponent<BaseEnemyObject>()->SetEnemyLayer(2);
		baseObject->layer = 1 << 2;

		// 랜덤
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> distWidth(-0.25f, 0.25f);
		std::uniform_real_distribution<float> distHeight(-0.3f, 0.3f);

		baseObject->GetTransform()->SetPosition({ Screen::GetWidth() * distWidth(gen), Screen::GetHeight() * distHeight(gen) });

		m_p2Enemy.push_back(baseObject);
	}
	if (INPUT_GET_KEYUP(KeyCode::P)) // p2 enemy 얼음새 생성 (ItemEnemy)
	{
		GameObject* baseObject = CreateEnemy(E_EnemyType::itemspawn);

		baseObject->GetComponent<BaseEnemyObject>()->SetEnemyLayer(2);
		baseObject->layer = 1 << 2;

		// 랜덤
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> distWidth(-0.25f, 0.25f);
		std::uniform_real_distribution<float> distHeight(0.0f, 0.5f);

		baseObject->GetTransform()->SetPosition({ Screen::GetWidth() * distWidth(gen), Screen::GetHeight() * distHeight(gen) });

		m_p2Enemy.push_back(baseObject);
	}
}

// moveflag 정리해야함
GameObject* GOTOEngine::EnemySpawner::CreateEnemy(E_EnemyType enemyType)
{
	GameObject* newEnemyObject = new GameObject(L"Enemy");
	//*// 설정대로 스폰
	switch(enemyType)
	{
	case move:
		newEnemyObject->AddComponent<MoveEnemy>();
		newEnemyObject->GetComponent<MoveEnemy>()->Initialize(crow);
		break;
	case gimmick:
		newEnemyObject->AddComponent<GimmickEnemy>();
		newEnemyObject->GetComponent<GimmickEnemy>()->Initialize(squirrel);
		break;
	case itemspawn:
		newEnemyObject->AddComponent<ItemEnemy>();
		newEnemyObject->GetComponent<ItemEnemy>()->Initialize(iceCrow);
		break; 
	default:
		break;
	}
	//*/

	/*// 랜덤 스폰
	switch (enemyType)
	{
		case move:
		{
			auto randomType = static_cast<E_Move_Enemy_Type>(std::rand() % E_Move_Enemy_Type::move_type_count);
			newEnemyObject->AddComponent<MoveEnemy>();
			newEnemyObject->GetComponent<MoveEnemy>()->Initialize(randomType, isLoop);
		}
		break;
		case gimmick:
		{
			auto randomType = static_cast<E_Gimmick_Enemy_Type>(std::rand() % E_Gimmick_Enemy_Type::gimmick_type_count);
			newEnemyObject->AddComponent<GimmickEnemy>();
			newEnemyObject->GetComponent<GimmickEnemy>()->Initialize(randomType, isLoop);
		}
		break;
		case itemspawn:
		{
			auto randomType = static_cast<E_Item_Enemy_Type>(std::rand() % E_Item_Enemy_Type::item_type_count);
			newEnemyObject->AddComponent<ItemEnemy>();
			newEnemyObject->GetComponent<ItemEnemy>()->Initialize(randomType, isLoop);
		}
		break;
	}
	//*/

	return newEnemyObject;
}

void GOTOEngine::EnemySpawner::CreateEnemy(E_EnemyType enemyType, int player)
{
	GameObject* baseObject = CreateEnemy(enemyType);

	baseObject->GetComponent<BaseEnemyObject>()->SetEnemyLayer(player);
	baseObject->layer = 1 << player;

	if (player == 1)
	{
		m_p1Enemy.push_back(baseObject);
	}
	else if (player == 2)
	{
		m_p2Enemy.push_back(baseObject);
	}

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
