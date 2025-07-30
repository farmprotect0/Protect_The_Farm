#include "StartMenuPrefab.h"
#include "StartMenu.h"
#include "CrosshairInteractButton.h"

#include <GameObject.h>
#include <Canvas.h>
#include <SpriteRenderer.h>
#include <Collider2D.h>

using namespace GOTOEngine;
GameObject* StartMenuPrefab::CreateStartMenu()
{
	auto GO = new GameObject(L"StartMenu");
	auto startMenu = GO->AddComponent<StartMenu>();

	auto startButtonGO = new GameObject(L"StartButton");
	startMenu->startButton = startButtonGO->GetTransform();
	startMenu->startButton->SetPosition({ 0.0f, -150.0f });
	startButtonGO->AddComponent<SpriteRenderer>()->SetSprite(L"../Resources/Demo/MenuButton.png");
	
	//버튼 콜라이더 추가
	auto startButtonP1ColGO = new GameObject(L"StartButtonP1Col");
	auto startButtonP1Col = startButtonP1ColGO->AddComponent<Collider2D>();
	auto startButtonP2ColGO = new GameObject(L"StartButtonP2Col");
	auto startButtonP2Col = startButtonP2ColGO->AddComponent<Collider2D>();
	auto startInteractButtonP1 = startButtonP1ColGO->AddComponent<CrosshairInteractButton>();
	startInteractButtonP1->parentButton = startButtonGO->GetTransform();
	auto startInteractButtonP2 = startButtonP2ColGO->AddComponent<CrosshairInteractButton>();
	startInteractButtonP2->parentButton = startButtonGO->GetTransform();

	auto spriteSize = startButtonGO->GetComponent<SpriteRenderer>()->GetSprite()->GetRect();
	startButtonP1Col->SetSize({ spriteSize.width, spriteSize.height });
	startButtonP2Col->SetSize({ spriteSize.width, spriteSize.height });

	startButtonP1ColGO->layer = (1 << 1);
	startButtonP2ColGO->layer = (1 << 2);

	startButtonP1ColGO->GetTransform()->SetParent(startButtonGO->GetTransform(), false);
	startButtonP2ColGO->GetTransform()->SetParent(startButtonGO->GetTransform(), false);
	

	auto optionsButtonGO = new GameObject(L"OptionsButton");
	startMenu->optionsButton = optionsButtonGO->GetTransform();
	startMenu->optionsButton->SetPosition({ 0.0f, -300.0f });
	optionsButtonGO->AddComponent<SpriteRenderer>()->SetSprite(L"../Resources/Demo/MenuButton.png");

	//버튼 콜라이더 추가
	auto optionButtonColGO = new GameObject(L"OptionButtonCol");
	auto optionButtonCol = optionButtonColGO->AddComponent<Collider2D>();

	optionButtonCol->SetSize({ spriteSize.width, spriteSize.height });

	optionButtonColGO->GetTransform()->SetParent(optionsButtonGO->GetTransform(), false);

	auto exitButtonGO = new GameObject(L"ExitButton");
	startMenu->exitButton = exitButtonGO->GetTransform();
	startMenu->exitButton->SetPosition({ 0.0f, -450.0f });
	exitButtonGO->AddComponent<SpriteRenderer>()->SetSprite(L"../Resources/Demo/MenuButton.png");

	//버튼 콜라이더 추가
	auto exitButtonP1ColGO = new GameObject(L"ExitButtonP1Col");
	auto exitButtonP1Col = exitButtonP1ColGO->AddComponent<Collider2D>();
	auto exitButtonP2ColGO = new GameObject(L"ExitButtonP2Col");
	auto exitButtonP2Col = exitButtonP2ColGO->AddComponent<Collider2D>();

	exitButtonP1Col->SetSize({ spriteSize.width, spriteSize.height });
	exitButtonP2Col->SetSize({ spriteSize.width, spriteSize.height });

	exitButtonP1ColGO->layer = (1 << 1);
	exitButtonP2ColGO->layer = (1 << 2);

	exitButtonP1ColGO->GetTransform()->SetParent(exitButtonGO->GetTransform(), false);
	exitButtonP2ColGO->GetTransform()->SetParent(exitButtonGO->GetTransform(), false);

	return GO;
}
