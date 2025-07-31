#pragma once
#include <ScriptBehaviour.h>
#include <TimeManager.h>
#include <SpriteRenderer.h>
#include "Transform.h"
#include "Screen.h"

#include <string.h>
#include <iostream>
#include <any>

#include "GameManager.h"
#include "EnemySpawner.h"
#include "IAttackAble.h"

// move
#include "BaseMovement.h"
#include "MoveLeftRight.h"
#include "MoveUpDown.h"
#include "MoveCircle.h"
#include "MoveParabolic.h"

namespace GOTOEngine
{
	enum E_EnemyType
	{
		move,
		gimmick,
		itemspawn
	};

	class BaseEnemyObject : public ScriptBehaviour,
							public IAttackAble
	{
	private:
		// move
		std::vector<BaseMovement*> m_movementComponents;
		Vector2 m_pathBaseLine;

	protected:
		E_EnemyType m_enemyType = E_EnemyType::move;

		// move
		int m_moveFlag;
		bool m_isMoveLoop = true;

		// hp, score
		float m_enemyHp = 1.0f;
		float m_DieScore = 1.0f;

		// 스폰확률
		float m_destroyTime = 8.0f;

		// 상태 값
		bool m_isDie = false;
		bool m_isDelayByDispone = false;
		bool m_isFrozen = false;

		// player layer
		int m_layer = 1;

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
		
	public:
		virtual ~BaseEnemyObject() = default;

		virtual void Awake()
		{
			// OFFSET 경로의 기준선
			m_pathBaseLine = GetGameObject()->GetTransform()->GetPosition();

		}
		void Start() {}

		void Update()
		{
			if (m_isDie || m_isFrozen || m_movementComponents.empty())
			{
				return;
			}

			float deltaTime = TimeManager::Get()->GetDeltaTime();

			Vector2 pathDelta = Vector2::Zero();
			Vector2 offset = Vector2::Zero();

			for (BaseMovement* movement : m_movementComponents)
			{
				if (movement->GetRole() == E_Move_Role::PATH)
				{
					pathDelta += movement->Move(deltaTime);
				}
				else // EMoveRole::OFFSET
				{
					offset += movement->Move(deltaTime);
				}
			}

			Vector2 currentPos = GetGameObject()->GetTransform()->GetPosition();
			Vector2 newPos;

			// m_moveFlag로 가능함
			MoveParabolic* moveComp = GetComponent<MoveParabolic>();
			if (moveComp != nullptr)
			{
				newPos.x = currentPos.x + pathDelta.x + offset.x;
				newPos.y = m_pathBaseLine.y + pathDelta.y + offset.y;
			}
			else
			{
				newPos = currentPos + offset + pathDelta;
			}

			GetGameObject()->GetTransform()->SetPosition(newPos);

		}

		void OnEnable() {}
		void OnDisable() {}
		virtual void OnDestroy() {}
		
		virtual void Initialize(std::any param, bool _moveLoop = false)
		{
			m_isMoveLoop = _moveLoop;
		}

		// Get
		bool IsEnemyDie() { return m_isDie; }

		// Set
		void SetMovementComponents()
		{
			// flag 스크립트	부착

			if (m_moveFlag & MOVE_PARABOLIC) // 0b1000
			{
				auto move = AddComponent<MoveParabolic>();

				if (m_moveFlag & MOVE_LEFT_RIGHT || m_moveFlag & MOVE_UP_DOWN)
				{
					if (m_moveFlag & MOVE_LEFT_RIGHT && m_moveFlag & MOVE_UP_DOWN) //0b1011
					{
						move->Initialize(E_Move_Role::OFFSET, false);
					}
					else if (m_moveFlag & MOVE_LEFT_RIGHT) // 0b1001
					{
						move->Initialize(E_Move_Role::OFFSET, false);
						AddComponent<MoveLeftRight>();
					}
					else // 0b1010
					{
						AddComponent<MoveUpDown>();
						move->Initialize(E_Move_Role::OFFSET, true);
					}
				}
				else // 0b1011
				{
					move->Initialize(E_Move_Role::PATH, false);
				}
			}
			else
			{
				if (m_moveFlag & MOVE_LEFT_RIGHT) // 0b0001
				{
					AddComponent<MoveLeftRight>();
				}
				if (m_moveFlag & MOVE_UP_DOWN) // 0b0010
				{
					AddComponent<MoveUpDown>();
				}
			}
			if (m_moveFlag & MOVE_CIRCULAR) // 0b0100
			{
				AddComponent<MoveCircle>();
			}

			// 등록한 movement들 추가
			m_movementComponents = GetGameObject()->GetComponents<BaseMovement>();
			MoveLeftRight* moveComp = GetComponent<MoveLeftRight>();

			if (moveComp != nullptr)
			{
				moveComp->OnFlipDirection.Add(this, &BaseEnemyObject::SetFlipXSprite);
			}

		}

		void SetFlipXSprite()
		{
			auto spriterenderer = GetComponent<SpriteRenderer>();
			if (spriterenderer) spriterenderer->SetFlipX(!spriterenderer->GetFlipX());
		}
		void SetEnemyFrozen(bool _frozen)
		{
			m_isFrozen = _frozen;
		}
		void SetEnemyLayer(int _layer = 1)
		{
			m_layer = _layer;
		}

		// 이벤트
		virtual void OnEnemyPlay() {}

		virtual void TakeDamage(float damage)
		{
			if (m_isDie) return;
			m_enemyHp -= damage;
			if (m_enemyHp <= 0) OnBulletDie();
		}
		virtual void OnBulletDie()
		{
			m_isDie = true;
			EnemySpawner::instance->SetDeleteEnemy(m_layer, GetGameObject());

			if (m_layer == 1)
			{
				GameManager::instance->P1Score += GameManager::instance->P1Bonus;
			}
			else if (m_layer == 2)
			{
				GameManager::instance->P2Score += GameManager::instance->P2Bonus;
			}
		}

	};
}

// enemy move size
//Screen::GetWidth() * 0.5f, Screen::GetHeight()});
