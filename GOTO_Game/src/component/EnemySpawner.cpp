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
	if (INPUT_GET_KEYDOWN(KeyCode::Z)) // p1 enemy 까마귀 생성 (MoveEnemy)
	{
		GameObject* baseObject = CreateEnemy(E_EnemyType::move, 0b0001, true);

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
	if (INPUT_GET_KEYUP(KeyCode::X)) // p1 enemy 토끼 생성 (GimmickEnemy)
	{
		GameObject* baseObject = CreateEnemy(E_EnemyType::gimmick, 0b1010, true);

		baseObject->GetComponent<BaseEnemyObject>()->SetEnemyLayer(1);
		baseObject->layer = 1 << 1;

		/*/ 랜덤
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> distWidth(-0.25f, 0.25f);
		std::uniform_real_distribution<float> distHeight(-0.3f, 0.3f);

		baseObject->GetTransform()->SetPosition({ Screen::GetWidth() * distWidth(gen), Screen::GetHeight() * distHeight(gen) });
		//*/
		baseObject->GetTransform()->SetPosition({ 0.0f, 0.0f });
		m_p1Enemy.push_back(baseObject);
	}
	if (INPUT_GET_KEYUP(KeyCode::C)) // p1 enemy 얼음새 생성 (ItemEnemy)
	{
		GameObject* baseObject = CreateEnemy(E_EnemyType::itemspawn, 0b0001, true);

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
		GameObject* baseObject = CreateEnemy(E_EnemyType::move, 0b0001, true);

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
		GameObject* baseObject = CreateEnemy(E_EnemyType::gimmick, 0b0111, true);

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
		GameObject* baseObject = CreateEnemy(E_EnemyType::itemspawn, 0b0001, true);

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

GameObject* GOTOEngine::EnemySpawner::CreateEnemy(E_EnemyType enemyType, int moveFlag, bool isLoop)
{
	GameObject* newEnemyObject = new GameObject(L"토끼");
	
	switch(enemyType)
	{
	case move:
		newEnemyObject->AddComponent<MoveEnemy>();
		newEnemyObject->GetComponent<MoveEnemy>()->Initialize(crow, moveFlag, isLoop);
		break;
	case gimmick:
		newEnemyObject->AddComponent<GimmickEnemy>();
		newEnemyObject->GetComponent<GimmickEnemy>()->Initialize(squirrel, moveFlag, isLoop);
		break;
	case itemspawn:
		newEnemyObject->AddComponent<ItemEnemy>();
		newEnemyObject->GetComponent<ItemEnemy>()->Initialize(goldCrow, moveFlag, isLoop);
		break; 
	default:
		break;
	}

	// flag 스크립트	부착
	
	if (moveFlag & MOVE_PARABOLIC) // 0b1000
	{
		auto move = newEnemyObject->AddComponent<MoveParabolic>();

		if (moveFlag & MOVE_LEFT_RIGHT || moveFlag & MOVE_UP_DOWN)
		{
			
			std::cout << "move offset" << std::endl;
			if (moveFlag & MOVE_LEFT_RIGHT) // 0b0001
			{
				move->Initialize(E_Move_Role::OFFSET, true);
				newEnemyObject->AddComponent<MoveLeftRight>();
			}
			else if (moveFlag & MOVE_UP_DOWN) // 0b0010
			{
				newEnemyObject->AddComponent<MoveUpDown>();
				move->Initialize(E_Move_Role::OFFSET, false);
			}
			else
			{
				move->Initialize(E_Move_Role::OFFSET, true);
			}
		}
		else
		{
			move->Initialize(E_Move_Role::PATH, false);
			std::cout << "move path" << std::endl;
		}
	}
	if (moveFlag & MOVE_CIRCULAR) // 0b0100
	{
		newEnemyObject->AddComponent<MoveCircle>();
	}
	
	return newEnemyObject;
}

void GOTOEngine::EnemySpawner::CreateEnemy(int player, int moveFlag, bool isLoop)
{
	GameObject* baseObject = CreateEnemy(E_EnemyType::move, moveFlag, isLoop);

	baseObject->GetComponent<BaseEnemyObject>()->SetEnemyLayer(player);
	baseObject->layer = 1 << player;

	// 랜덤
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> distWidth(-0.25f, 0.25f);
	std::uniform_real_distribution<float> distHeight(0.0f, 0.5f);

	baseObject->GetTransform()->SetPosition({ Screen::GetWidth() * distWidth(gen), Screen::GetHeight() * distHeight(gen) });

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
