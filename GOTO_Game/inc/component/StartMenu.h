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
			//�� ������ ���� ��ŸƮ �޴� Ȯ��
			CrosshairInteractButton* currentP1InteractButtons = nullptr;
			CrosshairInteractButton* currentP2InteractButtons = nullptr;

			float lastTime = 0.0f;
			for (auto* button : p1InteractButtons)
			{
				//���� �������� ���� ��ưã��
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
					// ���� ��ư�� ��ȣ�ۿ� ���� �ʱ�ȭ
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
					// ���� ��ư�� ��ȣ�ۿ� ���� ����
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
				//���� �������� ���� ��ưã��
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
					// ���� ��ư�� ��ȣ�ۿ� ���� �ʱ�ȭ
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
					// ���� ��ư�� ��ȣ�ۿ� ���� ����
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