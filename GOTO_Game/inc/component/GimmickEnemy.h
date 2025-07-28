#pragma once
#include <ScriptBehaviour.h>
#include "BaseEnemyObject.h"

namespace GOTOEngine
{
	enum gimmickEnemyType
	{
		rabbit,	// 토끼
		hamster	// 다람쥐 (Squirrel)
	};

	class GimmickEnemy : public BaseEnemyObject
	{
		gimmickEnemyType m_moveEnemyType;


	public:

		void Initialize() override
		{

			//std::cout << GetObject << std::endl;

		}
		void Awake()
		{
			__super::Awake();

			std::cout << "MoveEnemy Awake" << std::endl;

			m_enemyType = EnemyType::gimmick;

			m_moveLoop = true;
			m_moveSpeed = 10.0f;

			m_enemyhp = 10.0f;
			m_DieScore = 10.0f;
			m_oneTargetScore = 1.0f;

			m_destroyTime = 8.0f;

		}
	};
}