#pragma once
#include <ScriptBehaviour.h>
#include <GameObject.h>
#include <Delegate.h>
#include <CrosshairCollide.h>
#include "IAttackAble.h"

namespace GOTOEngine
{
	class CrosshairFire : public ScriptBehaviour
	{
	private:
		CrosshairCollide* m_collider = nullptr; // Collider2D 컴포넌트
		float m_fireCooldown = 0.0f; // 발사 쿨타임
	public:
    CrosshairFire()
    {
        SetExecutionOrder(10);
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }

		float fireRate = 0.5f; // 발사 간격
		int id = 0;
		Delegate<void,int> onFire;

		void Awake()
		{
			m_collider = GetComponent<CrosshairCollide>();
		}

		void Update()
		{
			m_fireCooldown -= TIME_GET_DELTATIME();
			m_fireCooldown = Mathf::Max(m_fireCooldown, 0.0f);

			if (m_fireCooldown > 0.0f)
				return;

			//입력 감지: 플레이어 ID별 키 또는 버튼 입력
			bool firePressed = (id == 0 && INPUT_GET_KEYDOWN(KeyCode::LeftShift)) ||
				(id == 1 && INPUT_GET_KEYDOWN(KeyCode::RightShift)) ||
				INPUT_GET_GAMEPAD_BUTTONDOWN(id, GamepadButton::ButtonSouth);

			if (!firePressed || !IsValidObject(m_collider))
				return;

			m_fireCooldown = fireRate;

			for (auto* obj : m_collider->GetCollideObjects())
			{
				std::wcout << obj->name << std::endl;

				for (auto* comp : obj->GetAllComponents())
				{
					if (auto* attackable = dynamic_cast<IAttackAble*>(comp))
					{
						attackable->TakeDamage(1);
					}
				}
			}

			onFire.Invoke(id);
			std::cout << "Crosshair Fire! : " << id << std::endl;
		}
	};
}