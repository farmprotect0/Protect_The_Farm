#pragma once
#include <ScriptBehaviour.h>
#include <Transform.h>

namespace GOTOEngine
{
	class StartMenu : public ScriptBehaviour
	{
	public:
		Transform* startButton;
		Transform* optionsButton;
		Transform* exitButton;

		StartMenu()
		{
		}

		void Awake()
		{

		}
	};
}