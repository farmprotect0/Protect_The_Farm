#pragma once
#include <ScriptBehaviour.h>
#include <GameObject.h>
#include <Delegate.h>

namespace GOTOEngine
{
	class CrosshairFire : public ScriptBehaviour
	{
	private:
	public:
    CrosshairFire()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		int id = 0;

		Delegate<void,int> onFire;

		void Update()
		{
			if ((id == 0 && INPUT_GET_KEYDOWN(KeyCode::RightShift)) || ( id == 1 && INPUT_GET_KEYDOWN(KeyCode::LeftShift)) || INPUT_GET_GAMEPAD_BUTTONDOWN(id, GamepadButton::ButtonSouth))
			{
				onFire.Invoke(id);
				std::cout << "Crosshair Fire! : " << id << std::endl;
			}
		}
	};
}