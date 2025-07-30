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

			m_enemyhp = 10.0f;
			m_DieScore = 10.0f;
			m_oneTargetScore = 1.0f;

			m_destroyTime = 8.0f;

		}
	};
}