#pragma once
#include "BaseEnemyObject.h"


namespace GOTOEngine
{
	enum E_MoveEnemyType
	{
		mole,	// 두더지
		crow	// 까마귀
	};

	class MoveEnemy : public BaseEnemyObject
	{
		E_MoveEnemyType m_moveEnemyType;


	public:
		virtual ~MoveEnemy() = default;

		void Initialize(std::any param, int _moveflag = 0b0000, bool _moveLoop = false) override
		{
			__super::Initialize(param, _moveflag, _moveLoop);

			if (param.type() == typeid(E_MoveEnemyType)) m_moveEnemyType = std::any_cast<E_MoveEnemyType>(param);

		}
		void Awake()
		{
			__super::Awake();

			m_enemyType = E_EnemyType::move;

			m_isMoveLoop = true;

			m_destroyTime = 8.0f;


			AddComponent<SpriteRenderer>()->SetSprite(L"../Resources/artResource/Sprint/Crow.png");
			GetComponent<SpriteRenderer>()->SetRenderLayer((1 << m_layer));


			//auto spriteRect = GetComponent<SpriteRenderer>()->GetSprite()->GetRect();
			//auto collider = AddComponent<Collider2D>();
		}

		void OnBulletDie() override
		{
			__super::OnBulletDie();

			// 죽는 애니메이션 필요

			Destroy(GetGameObject(), 2.0f);
		}
	};
}