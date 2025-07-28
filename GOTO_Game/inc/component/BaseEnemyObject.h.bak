#pragma once
#include <ScriptBehaviour.h>
#include <string.h>
#include <iostream>

enum EnemyType
{
	move,
	gimmick,
	itemspawn
};

// 비트 플래그
// 1, 1, 1 (원형 or 지그재그)
// 좌우, 상하, 포물선, 타원

using namespace GOTOEngine;
class BaseEnemyObject : public ScriptBehaviour
{
protected:
	EnemyType m_enemyType = EnemyType::move;
	//std::string m_enemyName;
	
	bool m_moveLoop = true;
	float m_moveSpeed = 10.0f;
	
	float m_enemyhp = 10.0f;
	float m_DieScore = 10.0f;
	float m_oneTargetScore = 1.0f;

	// 스폰확률
	float m_destroyTime = 8.0f;

public:
    BaseEnemyObject()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(OnDestroy);
        REGISTER_BEHAVIOUR_MESSAGE(OnDisable);
        REGISTER_BEHAVIOUR_MESSAGE(OnEnable);
        REGISTER_BEHAVIOUR_MESSAGE(Start);
    }
	virtual ~BaseEnemyObject() = default;

	virtual void Awake()
	{
		std::cout << "base Awake" << std::endl;

	}
	void Start() {}
	void OnEnable() {}
	void OnDisable() {}
	void OnDestroy() {}

	virtual void Initialize() {}
	virtual void OnEnemyPlay() {}
};