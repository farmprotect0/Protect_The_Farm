#pragma once
#include <ScriptBehaviour.h>
#include <Transform.h>

namespace GOTOEngine
{
	class StartMenu : public ScriptBehaviour
	{
	public:
    StartMenu()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		Transform* startButton;
		Transform* optionsButton;
		Transform* exitButton;

		void Update()
		{

		}
	};
}