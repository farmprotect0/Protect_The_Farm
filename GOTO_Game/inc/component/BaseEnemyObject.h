#pragma once
#include <ScriptBehaviour.h>
#include <string.h>
#include <iostream>
#include <any>


enum E_Enemy_Move_Type
{
	NONE = 0,					// 아무 움직임 없음 (0000)
	MOVE_LEFT_RIGHT = 1 << 0,	// 좌우 이동 (0001)
	MOVE_UP_DOWN = 1 << 1,		// 상하 이동 (0010)
	MOVE_CIRCULAR = 1 << 2,		// 원형 이동 (0100)
	MOVE_ZIGZAG = 1 << 3,		// 지그재그 이동 (1000)
	MOVE_PARABOLIC = 1 << 4,	// 포물선 이동 (10000)
};

namespace GOTOEngine
{
	enum E_EnemyType
	{
		move,
		gimmick,
		itemspawn
	};

	class BaseEnemyObject : public ScriptBehaviour
	{
	protected:
		E_EnemyType m_enemyType = E_EnemyType::move;
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

		virtual void Initialize(std::any param) {
			std::cout << "Base Initialize with std::any" << std::endl;
		}


		virtual void OnEnemyPlay() {}
	};
}