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
#include "MoveUpDown.h"
#include "MoveCircle.h"

namespace GOTOEngine
{
	class EnemySpawner : public ScriptBehaviour
	{
	public:
    EnemySpawner()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }

		static EnemySpawner* instance;

		std::vector<GameObject*> m_p1Enemy;
		std::vector<GameObject*> m_p2Enemy;


	public:
		virtual ~EnemySpawner() = default;

		void Awake();
		void Update();

		static GameObject* CreateEnemy(Vector2 position, int moveFlag);

		std::vector<GameObject*>* Getp1Enemy() { return &m_p1Enemy; }
		std::vector<GameObject*>* Getp2Enemy() { return &m_p2Enemy; }


	};
}

