#pragma once
#include <ScriptBehaviour.h>
#include "BaseEnemyObject.h"

enum moveEnemyType
{
	mole,	// 두더지
	crow	// 까마귀
};

using namespace GOTOEngine;
class MoveEnemy : public BaseEnemyObject
{
	moveEnemyType m_moveEnemyType;


public:

	void Initialize() override
	{

		std::cout << GetObject << std::endl;

	}
	void Awake()
	{
		__super::Awake();

		std::cout << "MoveEnemy Awake" << std::endl;

		m_enemyType = EnemyType::move;

		m_moveLoop = true;
		m_moveSpeed = 10.0f;

		m_enemyhp = 10.0f;
		m_DieScore = 10.0f;
		m_oneTargetScore = 1.0f;

		m_destroyTime = 8.0f;

	}
};