#pragma once
#include "BaseEnemyObject.h"

#include <SpriteRenderer.h>
#include <Collider2D.h>
#include "ItemManager.h"

namespace GOTOEngine
{
	enum E_ItemEnemyType
	{
		iceCrow,	// 얼음새
		bomCrow,	// 폭탄새
		goldCrow	// 황금새
	};

	class ItemEnemy : public BaseEnemyObject
	{
		E_ItemEnemyType m_itemEnemyType;
		ItemType m_itemType;

	public:
		virtual ~ItemEnemy() = default;

		void Initialize(std::any param, int _moveflag = 0b0000, bool _moveLoop = false) override
		{
			__super::Initialize(param, _moveflag, _moveLoop);

			if (param.type() == typeid(E_ItemEnemyType)) m_itemEnemyType = std::any_cast<E_ItemEnemyType>(param);


		}
		void Awake()
		{
			__super::Awake();

			m_enemyType = E_EnemyType::itemspawn;

			m_isMoveLoop = true;

			m_destroyTime = 8.0f;

			switch (m_itemEnemyType)
			{
			case iceCrow:
				m_itemType = ItemType::Icebomb;
				GetGameObject()->name = L"얼음새";
				AddComponent<SpriteRenderer>()->SetSprite(L"../Resources/artResource/Sprint/IceCrow.png");
				break;
			case bomCrow:
				m_itemType = ItemType::Bomb;
				GetGameObject()->name = L"폭탄새";
				AddComponent<SpriteRenderer>()->SetSprite(L"../Resources/artResource/Sprint/BomCrow.png");
				break;
			case goldCrow:
				m_itemType = ItemType::Ticket;
				GetGameObject()->name = L"황금새";
				AddComponent<SpriteRenderer>()->SetSprite(L"../Resources/artResource/Sprint/GoldCrow.png");
				break;
			}

			GetComponent<SpriteRenderer>()->SetRenderLayer((1 << m_layer));
			GetTransform()->SetLossyScale({ 0.2f, 0.2f });

			auto spriteRect = GetComponent<SpriteRenderer>()->GetSprite()->GetRect();
			auto collider = AddComponent<Collider2D>();

			collider->SetSize({ spriteRect.width * GetTransform()->GetLossyScale().x , spriteRect.height * GetTransform()->GetLossyScale().y });

		}

		void OnBulletDie() override
		{
			__super::OnBulletDie();

			// 죽는 애니메이션 필요

			ItemManager::instance->AddItem(m_layer, m_itemType);

			Destroy(GetGameObject(), 2.0f);
		}
	};
}