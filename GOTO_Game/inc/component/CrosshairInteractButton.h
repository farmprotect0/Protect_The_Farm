#pragma once
#include <ScriptBehaviour.h>
#include <TimeManager.h>
#include "IAttackAble.h"
#include "ICollideAble.h"
#include <Delegate.h>

namespace GOTOEngine
{
	class CrosshairInteractButton : public ScriptBehaviour, public IAttackAble, public ICollideAble
	{
	private:
		bool m_lastColliding = false; // ������ �浹 ����
		bool m_isColliding = false; // ���� �浹 ����
	public:
    CrosshairInteractButton()
    {
        SetExecutionOrder(2);
        REGISTER_BEHAVIOUR_MESSAGE(FixedUpdate);
    }
		Transform* parentButton = nullptr; // �θ� ��ư Transform
		float interactedTime = 0.0f;
		bool isInteracted = false;
		bool isSingleInteract = false;

		Delegate<void> onEnter;
		Delegate<void> onExit;
		Delegate<void> onInteract;

		void TakeDamage(float dmg) override
		{
			isInteracted = true;
			interactedTime = TIME_GET_TOTALTIME();
			onInteract.Invoke();
#ifdef _DEBUG
			std::wcout << GetGameObject()->name << std::endl;
#endif
		}

		void OnCollide(GameObject* obj) override
		{
			m_isColliding = true;
		}

		void FixedUpdate()
		{
			if (m_lastColliding != m_isColliding)
			{
				if (m_isColliding)
				{
					onEnter.Invoke();
				}
				else
				{
					onExit.Invoke();
				}
			}

			m_lastColliding = m_isColliding;
			m_isColliding = false;
		}
	};
}