#pragma once
#include <SpriteRenderer.h>
#include <ResourceManager.h>
#include <Collider2D.h>

#include <any>

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
		virtual ~GimmickEnemy() = default;

		void Initialize(std::any param, int _moveflag = 0b0000, bool _moveLoop = false) override
		{
			__super::Initialize(param, _moveflag, _moveLoop);

			if (param.type() == typeid(E_GimmickEnemyType)) m_gimmickEnemyType = std::any_cast<E_GimmickEnemyType>(param);
		}
		void Awake()
		{
			__super::Awake();

			m_enemyType = E_EnemyType::gimmick;

			m_isMoveLoop = true;

			m_destroyTime = 8.0f;


			AddComponent<SpriteRenderer>()->SetSprite(L"../Resources/artResource/Sprint/Rabit.png");
			GetComponent<SpriteRenderer>()->SetRenderLayer((1 << m_layer));
			GetTransform()->SetLossyScale({ 0.2f, 0.2f });

			auto spriteRect = GetComponent<SpriteRenderer>()->GetSprite()->GetRect();
			auto collider = AddComponent<Collider2D>();
			
			collider->SetSize({ spriteRect.width * GetTransform()->GetLossyScale().x , spriteRect.height * GetTransform()->GetLossyScale().y});
		}

		void OnBulletDie() override
		{
			__super::OnBulletDie();

			// 죽는 애니메이션 필요

			Destroy(GetGameObject(), 2.0f);
		}
	};
}