#pragma once
#include <any>
#include <ScriptBehaviour.h>
#include "BaseEnemyObject.h"
namespace GOTOEngine
{
	enum itemEnemyType
	{
		iceBird,	// 얼음새
		bombBird,	// 폭탄새
		goldBird	// 황금새
	};

	class ItemEnemy : public BaseEnemyObject
	{
		itemEnemyType m_itemEnemyType;


	public:

		void Initialize(std::any param) override
		{
			if (param.type() == typeid(itemEnemyType)) m_itemEnemyType = std::any_cast<itemEnemyType>(param);

		}
		void Awake()
		{
			__super::Awake();

			std::cout << "ItemEnemy Awake" << std::endl;

			m_enemyType = EnemyType::itemspawn;

			m_moveLoop = true;
			m_moveSpeed = 10.0f;

			m_enemyhp = 10.0f;
			m_DieScore = 10.0f;
			m_oneTargetScore = 1.0f;

			m_destroyTime = 8.0f;

		}
	};
}