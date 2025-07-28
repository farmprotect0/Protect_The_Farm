#pragma once
#include <any>
#include <ScriptBehaviour.h>
#include "BaseEnemyObject.h"

namespace GOTOEngine
{
	enum moveEnemyType
	{
		mole,	// 두더지
		crow	// 까마귀
	};

	class MoveEnemy : public BaseEnemyObject
	{
		moveEnemyType m_moveEnemyType;


	public:

		void Initialize(std::any param) override
		{
			if (param.type() == typeid(moveEnemyType)) m_moveEnemyType = std::any_cast<moveEnemyType>(param);




		}
		void Awake()
		{
			__super::Awake();

			std::cout << "Enemy Awake" << std::endl;

			m_enemyType = EnemyType::move;

			m_moveLoop = true;
			m_moveSpeed = 10.0f;

			m_enemyhp = 10.0f;
			m_DieScore = 10.0f;
			m_oneTargetScore = 1.0f;

			m_destroyTime = 8.0f;

		}
	};
}