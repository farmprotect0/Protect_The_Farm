#pragma once
#include <vector>

#include <ScriptBehaviour.h>
#include <TimeManager.h>
#include <InputManager.h>
#include <GameObject.h>

#include "BaseEnemyObject.h"
#include "MoveEnemy.h"
#include "GimmickEnemy.h"
#include "ItemEnemy.h"

#include "MoveLeftRight.h"

namespace GOTOEngine
{
	class EnemySpawner : public ScriptBehaviour
	{
	private:
		std::vector<GameObject*> m_p1Enemy;
		std::vector<GameObject*> m_p2Enemy;

	public:
    EnemySpawner()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }

	public:
		virtual ~EnemySpawner() = default;

		static GameObject* CreateEnemy(Vector2 position, int moveFlag)
		{
			GameObject* newEnemyObject = new GameObject(L"토끼");
			//newEnemyObject->GetTransform()->SetPosition(position);

			newEnemyObject->AddComponent<GimmickEnemy>();
			newEnemyObject->GetComponent<GimmickEnemy>()->Initialize(rabbit);

			// flag 스크립트	부착
			if (moveFlag & MOVE_LEFT_RIGHT)
			{
				newEnemyObject->AddComponent<MoveLeftRight>();

			}
			if (moveFlag & MOVE_UP_DOWN)
			{

			}
			if (moveFlag & MOVE_CIRCULAR)
			{
			}

			return newEnemyObject;
		}

		void Update()
		{
			if (INPUT_GET_KEYDOWN(KeyCode::Q)) // p1 enemy 생성
			{
				GameObject* baseObject = CreateEnemy({0,0}, MOVE_LEFT_RIGHT);

				m_p1Enemy.push_back(baseObject);
				std::cout << "current objects size : " << m_p1Enemy.size() << std::endl;
			}
			if (INPUT_GET_KEYUP(KeyCode::R)) // disable
			{
				//GameObject* baseObject = m_objects[0];

				
				//m_objects[0]->SetActive(false);

			}
			if (INPUT_GET_KEYDOWN(KeyCode::E))
			{

			}
		}
	};
}