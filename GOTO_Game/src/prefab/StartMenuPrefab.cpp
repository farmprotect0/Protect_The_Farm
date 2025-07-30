#include "StartMenuPrefab.h"
#include "StartMenu.h"

#include <GameObject.h>
#include <Canvas.h>

using namespace GOTOEngine;
GameObject* StartMenuPrefab::CreateStartMenu()
{
	auto GO = new GameObject(L"StartMenu");
	auto startMenu = GO->AddComponent<StartMenu>();

	auto startButtonGO = new GameObject(L"StartButton");
	startMenu->startButton = startButtonGO->GetTransform();
	startMenu->startButton->SetPosition({ 0.0f, -150.0f });

	auto optionsButtonGO = new GameObject(L"OptionsButton");
	startMenu->optionsButton = optionsButtonGO->GetTransform();
	startMenu->optionsButton->SetPosition({ 0.0f, -300.0f });

	auto exitButtonGO = new GameObject(L"ExitButton");
	startMenu->exitButton = exitButtonGO->GetTransform();
	startMenu->exitButton->SetPosition({ 0.0f, -450.0f });


	return GO;
}
