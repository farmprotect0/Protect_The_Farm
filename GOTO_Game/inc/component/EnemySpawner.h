#pragma once
#include <ScriptBehaviour.h>
#include <InputManager.h>
#include <GameObject.h>

#include <vector>


namespace GOTOEngine
{	
	enum E_EnemyType;

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

		static GameObject* CreateEnemy(E_EnemyType enemyType, int moveFlag, bool isLoop);
		void CreateEnemy(int player, int moveFlag, bool isLoop);

		std::vector<GameObject*>* Getp1Enemy() { return &m_p1Enemy; }
		std::vector<GameObject*>* Getp2Enemy() { return &m_p2Enemy; }

		bool SetDeleteEnemy(int _layer, GameObject* enemy);

		void Setp1EnemyAllDestroy();
		void Setp2EnemyAllDestroy();
	};
}

