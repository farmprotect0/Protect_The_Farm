#pragma once
#include <ScriptBehaviour.h>
#include "BaseEnemyObject.h"

enum itemEnemyType
{
	iceBird,	// 얼음새
	bombBird,	// 폭탄새
	goldBird	// 황금새
};

using namespace GOTOEngine;
class ItemEnemy : public BaseEnemyObject
{
	itemEnemyType m_moveEnemyType;


public:

	void Initialize() override
	{

		//std::cout << GetObject << std::endl;

	}
	void Awake()
	{
		__super::Awake();

		std::cout << "MoveEnemy Awake" << std::endl;

		m_enemyType = EnemyType::itemspawn;

		m_moveLoop = true;
		m_moveSpeed = 10.0f;

		m_enemyhp = 10.0f;
		m_DieScore = 10.0f;
		m_oneTargetScore = 1.0f;

		m_destroyTime = 8.0f;

	}
};