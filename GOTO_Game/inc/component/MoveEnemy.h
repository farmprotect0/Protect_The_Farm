#pragma once
#include <any>
#include <ScriptBehaviour.h>
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

		void Initialize(std::any param, int _moveflag = NONE) override
		{
			if (param.type() == typeid(E_MoveEnemyType)) m_moveEnemyType = std::any_cast<E_MoveEnemyType>(param);

		}
		void Awake()
		{
			__super::Awake();

			std::cout << "Enemy Awake" << std::endl;

			m_enemyType = E_EnemyType::move;

			m_moveLoop = true;

			m_enemyhp = 10.0f;
			m_DieScore = 10.0f;
			m_oneTargetScore = 1.0f;

			m_destroyTime = 8.0f;

		}
	};
}