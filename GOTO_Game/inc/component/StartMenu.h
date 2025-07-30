#pragma once
#include <ScriptBehaviour.h>
#include <Transform.h>
#include "CrosshairInteractButton.h"
#include <SpriteRenderer.h>

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

		std::vector<CrosshairInteractButton*> p1InteractButtons;
		std::vector<CrosshairInteractButton*> p2InteractButtons;

		CrosshairInteractButton* lastP1InteractButton = nullptr;
		CrosshairInteractButton* lastP2InteractButton = nullptr;

		void Update()
		{
			//매 프레임 마다 스타트 메뉴 확인
			CrosshairInteractButton* currentP1InteractButtons = nullptr;
			CrosshairInteractButton* currentP2InteractButtons = nullptr;

			float lastTime = 0.0f;
			for (auto* button : p1InteractButtons)
			{
				//가장 마지막에 누른 버튼찾기
				CrosshairInteractButton* prevButton = currentP1InteractButtons;
				if (button->isInteracted && button->interactedTime > lastTime)
				{
					lastTime = button->interactedTime;
					currentP1InteractButtons = button;
				}
			}

			if (currentP1InteractButtons != lastP1InteractButton)
			{
				if (IsValidObject(lastP1InteractButton))
				{
					// 이전 버튼의 상호작용 상태 초기화
					lastP1InteractButton->isInteracted = false; 
					auto lastButtonP1Sprite = lastP1InteractButton->parentButton->GetComponent<SpriteRenderer>();
					if (IsValidObject(lastButtonP1Sprite))
					{
						lastButtonP1Sprite->SetSprite(L"../Resources/Demo/MenuButton.png");
					}
				}
				lastP1InteractButton = currentP1InteractButtons;

				if (IsValidObject(currentP1InteractButtons))
				{
					// 현재 버튼의 상호작용 상태 설정
					currentP1InteractButtons->isInteracted = true;
					auto currentButtonP1Sprite = currentP1InteractButtons->parentButton->GetComponent<SpriteRenderer>();
					if (IsValidObject(currentButtonP1Sprite))
					{
						currentButtonP1Sprite->SetSprite(L"../Resources/Demo/MenuButton_Select_P1.png");
					}
				}
			}

			lastTime = 0.0f;
			for (auto* button : p2InteractButtons)
			{
				//가장 마지막에 누른 버튼찾기
				CrosshairInteractButton* prevButton = currentP2InteractButtons;
				if (button->isInteracted && button->interactedTime > lastTime)
				{
					lastTime = button->interactedTime;
					currentP2InteractButtons = button;
				}
			}

			if (currentP2InteractButtons != lastP2InteractButton)
			{
				if (IsValidObject(lastP2InteractButton))
				{
					// 이전 버튼의 상호작용 상태 초기화
					lastP2InteractButton->isInteracted = false;
					auto lastButtonP2Sprite = lastP2InteractButton->parentButton->GetComponent<SpriteRenderer>();
					if (IsValidObject(lastButtonP2Sprite))
					{
						lastButtonP2Sprite->SetSprite(L"../Resources/Demo/MenuButton.png");
					}
				}
				lastP2InteractButton = currentP2InteractButtons;

				if (IsValidObject(currentP2InteractButtons))
				{
					// 현재 버튼의 상호작용 상태 설정
					currentP2InteractButtons->isInteracted = true;
					auto currentButtonP2Sprite = currentP2InteractButtons->parentButton->GetComponent<SpriteRenderer>();
					if (IsValidObject(currentButtonP2Sprite))
					{
						currentButtonP2Sprite->SetSprite(L"../Resources/Demo/MenuButton_Select_P2.png");
					}
				}
			}
		}
	};
}