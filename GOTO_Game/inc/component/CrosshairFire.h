#pragma once
#include <ScriptBehaviour.h>
#include <GameObject.h>
#include <Delegate.h>
#include <PhysicsManager.h>
#include <Collider2D.h>

namespace GOTOEngine
{
	class CrosshairFire : public ScriptBehaviour
	{
	private:
		Collider2D* m_collider;
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
			if ((id == 0 && INPUT_GET_KEYDOWN(KeyCode::RightShift)) || ( id == 1 && INPUT_GET_KEYDOWN(KeyCode::LeftShift)) || INPUT_GET_GAMEPAD_BUTTONDOWN(id, GamepadButton::ButtonSouth))
			{
				onFire.Invoke(id);

				auto objects = PHYSICS_OVERLAP_BOX2D(GetTransform()->GetPosition(), m_collider->GetSize());

				for (auto obj : objects)
				{
					if(obj->name != GetGameObject()->name)
						std::wcout << obj->name << std::endl;
				}

				std::cout << "Crosshair Fire! : " << id << std::endl;
			}
		}
	};
}