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


namespace GOTOEngine
{
	class EnemySpawner : public ScriptBehaviour
	{
	private:
		std::vector<GameObject*> m_objects;

	public:
    EnemySpawner()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }

	public:
		virtual ~EnemySpawner() = default;
		void Update()
		{
			if (INPUT_GET_KEYDOWN(KeyCode::Alpha1)) // 생성
			{
				GameObject* baseObject = new GameObject(L"토끼");

				baseObject->AddComponent<GimmickEnemy>();
				baseObject->GetComponent<GimmickEnemy>()->Initialize(rabbit);

				m_objects.push_back(baseObject);
				std::cout << "current objects size : " << m_objects.size() << std::endl;
			}
			if (INPUT_GET_KEYUP(KeyCode::Alpha2)) // disable
			{
				//GameObject* baseObject = m_objects[0];

				
				//m_objects[0]->SetActive(false);

			}
			if (INPUT_GET_KEYDOWN(KeyCode::Alpha3))
			{

			}
		}
	};
}