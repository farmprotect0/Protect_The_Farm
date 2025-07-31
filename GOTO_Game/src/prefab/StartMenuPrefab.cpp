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

	//===== Start ��ư =====

	auto startButtonGO = new GameObject(L"StartButton");
	startMenu->startButton = startButtonGO->GetTransform();
	startMenu->startButton->SetPosition({ 0.0f, -150.0f });
	startButtonGO->AddComponent<SpriteRenderer>()->SetSprite(L"../Resources/Demo/MenuButton.png");
	
	//��ư �ݶ��̴� �߰�
	auto startButtonP1ColGO = new GameObject(L"StartButtonP1Col");
	auto startButtonP1Col = startButtonP1ColGO->AddComponent<Collider2D>();
	auto startButtonP2ColGO = new GameObject(L"StartButtonP2Col");
	auto startButtonP2Col = startButtonP2ColGO->AddComponent<Collider2D>();

	auto startInteractButtonP1 = startButtonP1ColGO->AddComponent<CrosshairInteractButton>();
	startInteractButtonP1->parentButton = startButtonGO->GetTransform();
	startMenu->p1InteractButtons.push_back(startInteractButtonP1);

	auto startInteractButtonP2 = startButtonP2ColGO->AddComponent<CrosshairInteractButton>();
	startInteractButtonP2->parentButton = startButtonGO->GetTransform();
	startMenu->p2InteractButtons.push_back(startInteractButtonP2);

	auto spriteSize = startButtonGO->GetComponent<SpriteRenderer>()->GetSprite()->GetRect();
	startButtonP1Col->SetSize({ spriteSize.width, spriteSize.height });
	startButtonP2Col->SetSize({ spriteSize.width, spriteSize.height });

	startButtonP1ColGO->layer = (1 << 1);
	startButtonP2ColGO->layer = (1 << 2);

	startButtonP1ColGO->GetTransform()->SetParent(startButtonGO->GetTransform(), false);
	startButtonP2ColGO->GetTransform()->SetParent(startButtonGO->GetTransform(), false);
	

	//===== Option ��ư =====

	auto optionsButtonGO = new GameObject(L"OptionsButton");
	startMenu->optionsButton = optionsButtonGO->GetTransform();
	startMenu->optionsButton->SetPosition({ 0.0f, -300.0f });
	optionsButtonGO->AddComponent<SpriteRenderer>()->SetSprite(L"../Resources/Demo/MenuButton.png");

	//��ư �ݶ��̴� �߰�
	auto optionButtonP1ColGO = new GameObject(L"OptionButtonP1Col");
	auto optionButtonP1Col = optionButtonP1ColGO->AddComponent<Collider2D>();
	auto optionButtonP2ColGO = new GameObject(L"OptionButtonP2Col");
	auto optionButtonP2Col = optionButtonP2ColGO->AddComponent<Collider2D>();

	auto optionInteractButtonP1 = optionButtonP1ColGO->AddComponent<CrosshairInteractButton>();
	optionInteractButtonP1->parentButton = optionsButtonGO->GetTransform();
	startMenu->p1InteractButtons.push_back(optionInteractButtonP1);

	auto optionInteractButtonP2 = optionButtonP2ColGO->AddComponent<CrosshairInteractButton>();
	optionInteractButtonP2->parentButton = optionsButtonGO->GetTransform();
	startMenu->p2InteractButtons.push_back(optionInteractButtonP2);

	optionButtonP1Col->SetSize({ spriteSize.width, spriteSize.height });
	optionButtonP2Col->SetSize({ spriteSize.width, spriteSize.height });

	optionButtonP1ColGO->layer = (1 << 1);
	optionButtonP2ColGO->layer = (1 << 2);

	optionButtonP1ColGO->GetTransform()->SetParent(optionsButtonGO->GetTransform(), false);
	optionButtonP2ColGO->GetTransform()->SetParent(optionsButtonGO->GetTransform(), false);

	//===== Exit ��ư =====

	auto exitButtonGO = new GameObject(L"ExitButton");
	startMenu->exitButton = exitButtonGO->GetTransform();
	startMenu->exitButton->SetPosition({ 0.0f, -450.0f });
	exitButtonGO->AddComponent<SpriteRenderer>()->SetSprite(L"../Resources/Demo/MenuButton.png");

	//��ư �ݶ��̴� �߰�
	auto exitButtonP1ColGO = new GameObject(L"ExitButtonP1Col");
	auto exitButtonP1Col = exitButtonP1ColGO->AddComponent<Collider2D>();
	auto exitButtonP2ColGO = new GameObject(L"ExitButtonP2Col");
	auto exitButtonP2Col = exitButtonP2ColGO->AddComponent<Collider2D>();

	exitButtonP1Col->SetSize({ spriteSize.width, spriteSize.height });
	exitButtonP2Col->SetSize({ spriteSize.width, spriteSize.height });

	exitButtonP1ColGO->layer = (1 << 1);
	exitButtonP2ColGO->layer = (1 << 2);

	auto exitInteractButtonP1 = exitButtonP1ColGO->AddComponent<CrosshairInteractButton>();
	exitInteractButtonP1->parentButton = exitButtonGO->GetTransform();
	startMenu->p1InteractButtons.push_back(exitInteractButtonP1);

	auto exitInteractButtonP2 = exitButtonP2ColGO->AddComponent<CrosshairInteractButton>();
	exitInteractButtonP2->parentButton = exitButtonGO->GetTransform();
	startMenu->p2InteractButtons.push_back(exitInteractButtonP2);

	exitButtonP1ColGO->GetTransform()->SetParent(exitButtonGO->GetTransform(), false);
	exitButtonP2ColGO->GetTransform()->SetParent(exitButtonGO->GetTransform(), false);

	return GO;
}
