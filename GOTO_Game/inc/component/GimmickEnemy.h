#pragma once
#include <any>
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
		gimmickEnemyType m_gimmickEnemyType;


	public:

		void Initialize(std::any param) override
		{
			if (param.type() == typeid(gimmickEnemyType)) m_gimmickEnemyType = std::any_cast<gimmickEnemyType>(param);
			
			m_gimmickEnemyType;
		}
		void Awake()
		{
			__super::Awake();

			std::cout << "GimmickEnemy Awake" << std::endl;

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