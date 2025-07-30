#pragma once
#include "BaseEnemyObject.h"

#include <any>

namespace GOTOEngine
{
	enum E_ItemEnemyType
	{
		iceBird,	// 얼음새
		bombBird,	// 폭탄새
		goldBird	// 황금새
	};

	class ItemEnemy : public BaseEnemyObject
	{
		E_ItemEnemyType m_itemEnemyType;


	public:
		virtual ~ItemEnemy() = default;

		void Initialize(std::any param, int _moveflag = 0b0000, bool _moveLoop = false) override
		{
			__super::Initialize(param, _moveflag, _moveLoop);

			if (param.type() == typeid(E_ItemEnemyType)) m_itemEnemyType = std::any_cast<E_ItemEnemyType>(param);


		}
		void Awake()
		{
			__super::Awake();

			m_enemyType = E_EnemyType::itemspawn;

			m_isMoveLoop = true;

			m_destroyTime = 8.0f;

		}

		void OnBulletDie() override
		{
			__super::OnBulletDie();

			// 죽는 애니메이션 필요

			Destroy(GetGameObject(), 2.0f);
		}
	};
}