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
#include "BaseMovement.h"
#include "MoveLeftRight.h"
#include "MoveUpDown.h"

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
		std::vector<BaseMovement*> m_movementComponents;

	protected:
		E_EnemyType m_enemyType = E_EnemyType::move;
		//std::string m_enemyName;

		int m_moveFlag;
		bool m_isMoveLoop = true;

		bool m_isDelayByDispone = false;

		float m_enemyhp = 1.0f;
		float m_DieScore = 1.0f;			// 죽었을 때 점수
		//float m_oneTargetScore = 1.0f;	// 한발 쐈을 때 점수

		// 스폰확률
		float m_destroyTime = 8.0f;

		bool m_frozen;

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
			// 등록한 movement들 추가
			m_movementComponents = GetGameObject()->GetComponents<BaseMovement>();
			MoveLeftRight* moveComp = GetComponent<MoveLeftRight>();
			
			if (moveComp != nullptr)
			{
				moveComp->OnFlipDirection.Add(this, &BaseEnemyObject::SetFlipXSprite);
			}

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
		virtual void OnDestroy() {}
		
		virtual void Initialize(std::any param, int _moveflag = 0b0000, bool _moveLoop = false)
		{
			m_moveFlag = _moveflag;
			m_isMoveLoop = _moveLoop;
		}

		void AddMovementComponent(BaseMovement* movement)
		{
			m_movementComponents.push_back(movement);
		}

		void SetFlipXSprite()
		{
			auto spriterenderer = GetComponent<SpriteRenderer>();
			if (spriterenderer) spriterenderer->SetFlipX(!spriterenderer->GetFlipX());
		}

		void SetEnemyFrozen(bool _frozen)
		{
			m_frozen = _frozen;
		}

		void SetEnemyLayer(int _layer = 1)
		{
			m_layer = _layer;
		}

		virtual void OnEnemyPlay() {}

		virtual void TakeDamage(float damage)
		{
			if (IsEnemyDie()) return;
			m_enemyhp -= damage;
			if (m_enemyhp <= 0) OnBulletDie();
		}

		bool IsEnemyDie() { return m_enemyhp <= 0; }

		virtual void OnBulletDie()
		{
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
