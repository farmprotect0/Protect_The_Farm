#pragma once
#include <ScriptBehaviour.h>
#include <TimeManager.h>
#include "Transform.h"
#include "Screen.h"
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

		int m_moveFlag;
		bool m_isMoveLoop = true;
		int m_maxX;
		int m_minX;
		int m_maxY;
		int m_minY;

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

			// player1
			m_maxX = Screen::GetWidth() * 0.25f;
			m_minX = Screen::GetWidth() * -0.25f;

			m_maxY = Screen::GetHeight() * 0.5f;
			m_minY = Screen::GetHeight() * -0.5f;
		}
		void Start() {}

		void Update()
		{
			if (m_frozen == true || m_movementComponents.empty())
			{
				return;
			}

			float deltaTime = TimeManager::Get()->GetDeltaTime();
			Vector2 currentPos = GetTransform()->GetPosition();

			Vector2 pathDelta = Vector2::Zero();
			Vector2 offset = Vector2::Zero();

			for (BaseMovement* movement : m_movementComponents)
			{
				if (movement->GetRole() == E_Move_Role::PATH)
				{
					// 루프 로직
					if (m_isMoveLoop)
					{
						if ((currentPos.x > m_maxX && movement->GetDirection() > 0) ||
							(currentPos.x < m_minX && movement->GetDirection() < 0))
						{
							// sprite flip 필요
							movement->FlipDirection();
						}
						if ((currentPos.y > m_maxY && movement->GetDirection() > 0) ||
							(currentPos.y < m_minY && movement->GetDirection() < 0))
						{
							movement->FlipDirection();
						}
					}
					pathDelta += movement->Move(deltaTime);
				}
				else // EMoveRole::OFFSET
				{
					offset += movement->Move(deltaTime);
				}
			}

			GetTransform()->SetPosition(currentPos + pathDelta + offset);
		}

		void OnEnable() {}
		void OnDisable() {}
		void OnDestroy() {}

		virtual void Initialize(std::any param, int _moveflag = 0b0000, bool _moveLoop = false)
		{
			m_moveFlag = _moveflag;
			m_isMoveLoop = _moveLoop;
		}

		void AddMovementComponent(BaseMovement* movement)
		{
			m_movementComponents.push_back(movement);
		}

		void SetEnemyFrozen(bool _frozen)
		{
			m_frozen = _frozen;
		}

		virtual void OnEnemyPlay() {}
	};
}


// enemy move size
//Screen::GetWidth() * 0.5f, Screen::GetHeight()});