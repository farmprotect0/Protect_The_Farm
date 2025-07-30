#pragma once
#include <ScriptBehaviour.h>
#include <GameObject.h>
#include <Delegate.h>
#include <PhysicsManager.h>
#include <Collider2D.h>
#include "IAttackAble.h"

namespace GOTOEngine
{
	class CrosshairFire : public ScriptBehaviour
	{
	private:
		Collider2D* m_collider = nullptr;
	public:
    CrosshairFire()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }


		int id = 0;
		Delegate<void,int> onFire;

		void Awake()
		{
			m_collider = GetComponent<Collider2D>();
		}

		void Update()
		{
			//입력 감지: 플레이어 ID별 키 또는 버튼 입력
			bool firePressed = (id == 0 && INPUT_GET_KEYDOWN(KeyCode::RightShift)) ||
				(id == 1 && INPUT_GET_KEYDOWN(KeyCode::LeftShift)) ||
				INPUT_GET_GAMEPAD_BUTTONDOWN(id, GamepadButton::ButtonSouth);

			if (!firePressed || !IsValidObject(m_collider))
				return;

			const Vector2 position = GetTransform()->GetPosition();
			const Vector2 size = m_collider->GetSize();
			auto objects = PHYSICS_OVERLAP_BOX2D(position, size);

			const int targetLayerMask = 1 << (id + 1);
			GameObject* self = GetGameObject();

			for (auto* obj : objects)
			{
				if (obj == self)
					continue;

				if ((obj->layer & targetLayerMask) == 0)
					continue;

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