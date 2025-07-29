#pragma once
#include <ScriptBehaviour.h>
#include <TimeManager.h>
#include <string.h>
#include <iostream>
#include <any>

#include "BaseMovement.h"

namespace GOTOEngine
{
	enum E_EnemyType
	{
		move,
		gimmick,
		itemspawn
	};

	class BaseEnemyObject : public ScriptBehaviour
	{
	private:
		std::vector<BaseMovement*> m_movementComponents;

	protected:
		E_EnemyType m_enemyType = E_EnemyType::move;
		//std::string m_enemyName;

		int m_moveFlag = MOVE_LEFT_RIGHT;
		bool m_moveLoop = true;

		float m_enemyhp = 10.0f;
		float m_DieScore = 10.0f;			// 죽었을 때 점수
		float m_oneTargetScore = 1.0f;		// 한발 쐈을 때 점수

		// 스폰확률
		float m_destroyTime = 8.0f;

		bool m_frozen;

	public:
    BaseEnemyObject()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(OnDestroy);
        REGISTER_BEHAVIOUR_MESSAGE(OnDisable);
        REGISTER_BEHAVIOUR_MESSAGE(OnEnable);
        REGISTER_BEHAVIOUR_MESSAGE(Start);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		virtual ~BaseEnemyObject() = default;

		virtual void Awake()
		{
			// 등록한 movement들 추가
			m_movementComponents = GetGameObject()->GetComponents<BaseMovement>();
		}
		void Start() {}

		void Update()
		{
			if (m_frozen == true || m_movementComponents.empty())
			{
				return;
			}

			// 프레임마다 합산할 변수
			Vector2 totalMovement = Vector2::Zero();

			for (BaseMovement* movement : m_movementComponents)
			{
				totalMovement += movement->Move(TimeManager::Get()->GetDeltaTime());
			}

			GetTransform()->Translate(totalMovement, true);
		}

		void OnEnable() {}
		void OnDisable() {}
		void OnDestroy() {}

		virtual void Initialize(std::any param, int _moveflag = NONE) {
			std::cout << "Base Initialize with std::any" << std::endl;
		}

		void AddMovementComponent(BaseMovement* movement)
		{
			m_movementComponents.push_back(movement);
		}

		
		virtual void OnEnemyPlay() {}
	};
}