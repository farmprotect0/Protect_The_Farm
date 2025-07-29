#pragma once
#include <any>
#include <ScriptBehaviour.h>
#include <SpriteRenderer.h>
#include <ResourceManager.h>

#include "BaseEnemyObject.h"

namespace GOTOEngine
{
	enum E_GimmickEnemyType
	{
		rabbit,		// 토끼
		squirrel	// 다람쥐
	};

	class GimmickEnemy : public BaseEnemyObject
	{
		E_GimmickEnemyType m_gimmickEnemyType;


	public:

		void Initialize(std::any param, int _moveflag = 0b0000, bool _moveLoop = false) override
		{
			__super::Initialize(param, _moveflag, _moveLoop);

			if (param.type() == typeid(E_GimmickEnemyType)) m_gimmickEnemyType = std::any_cast<E_GimmickEnemyType>(param);
			
			//GetTransform()->SetPosition({ 0,0 });
			GetTransform()->SetLossyScale({ 0.2f, 0.2f });

			
		}
		void Awake()
		{
			__super::Awake();

			std::cout << "GimmickEnemy Awake" << std::endl;

			m_enemyType = E_EnemyType::gimmick;

			m_isMoveLoop = true;

			m_enemyhp = 10.0f;
			m_DieScore = 10.0f;
			m_oneTargetScore = 1.0f;

			m_destroyTime = 8.0f;


			AddComponent<SpriteRenderer>()->SetSprite(Resource::Load<Sprite>(L"../Resources/artResource/Animal/Gimmick/Rabbit_idle.gif"));
		}
	};
}