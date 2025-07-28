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
			if (INPUT_GET_KEYDOWN(KeyCode::Alpha1)) {
				GameObject* baseObject = new GameObject(L"까마귀");

				baseObject->GetTransform()->SetPosition({ 0,0 });
				baseObject->GetTransform()->SetLossyScale({ 2.0f,2.0f });

				baseObject->AddComponent<MoveEnemy>();
				baseObject->GetComponent<MoveEnemy>()->Initialize(crow);

				m_objects.push_back(baseObject);
				std::cout << "current objects size : " << m_objects.size() << std::endl;
			}
			if (INPUT_GET_KEYDOWN(KeyCode::Alpha2))
			{
				GameObject* baseObject = new GameObject(L"토끼");

				baseObject->GetTransform()->SetPosition({ 0,0 });
				baseObject->GetTransform()->SetLossyScale({ 2.0f,2.0f });

				baseObject->AddComponent<GimmickEnemy>();
				baseObject->GetComponent<GimmickEnemy>()->Initialize(iceBird);

				

				m_objects.push_back(baseObject);
				std::cout << "current objects size : " << m_objects.size() << std::endl;
			}
			if (INPUT_GET_KEYDOWN(KeyCode::Alpha3))
			{
				GameObject* baseObject = new GameObject(L"토끼");

				baseObject->GetTransform()->SetPosition({ 0,0 });
				baseObject->GetTransform()->SetLossyScale({ 2.0f,2.0f });

				baseObject->AddComponent<ItemEnemy>();
				baseObject->GetComponent<ItemEnemy>()->Initialize(rabbit);

				m_objects.push_back(baseObject);
				std::cout << "current objects size : " << m_objects.size() << std::endl;
			}
		}
	};
}