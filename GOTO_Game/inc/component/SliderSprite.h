#pragma once
#include <ScriptBehaviour.h>
#include <SpriteRenderer.h>
#include <Transform.h>
#include <TimeManager.h>
#include <Texture2D.h>
#include <cmath>

namespace GOTOEngine
{
	class SliderSprite : public ScriptBehaviour
	{
	private:
		float m_value = 1.0f;
	public:
    SliderSprite()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }

		SpriteRenderer* backgroundRenderer;
		SpriteRenderer* sliderBarRenderer;
		SpriteRenderer* sliderHandleRenderer;

		int renderOrder = 504;
		float sliderWidth;
		float GetValue() { return m_value; }
		void SetValue(float value) { m_value = Mathf::Clamp01(value); }

		void Awake()
		{
			
			//��׶��� ��������Ʈ ����
			if (backgroundRenderer)
			{
				auto backgroundSprite = new Sprite();
				backgroundSprite->SetTexture(L"../Resources/Demo/GageUI_Back.png");
				backgroundSprite->SetPivotX(0.0f);

				if (backgroundSprite->GetTexture())
				{
					backgroundSprite->SetRect(backgroundSprite->GetTexture()->GetRect());
					sliderWidth = backgroundSprite->GetRect().width;
				}

				backgroundRenderer->SetSprite(backgroundSprite);
				backgroundRenderer->SetRenderOrder(renderOrder);
			}

			//������ �� ��������Ʈ ����
			if (sliderBarRenderer)
			{
				auto sliderSprite = new Sprite();
				sliderSprite->SetTexture(L"../Resources/Demo/GageUI_Front.png");
				sliderSprite->SetPivotX(0.0f);
				if (sliderSprite->GetTexture())
				{
					sliderSprite->SetRect(sliderSprite->GetTexture()->GetRect());
				}

				sliderBarRenderer->SetSprite(sliderSprite);
				sliderBarRenderer->SetRenderOrder(renderOrder + 1);
			}

			//������ �ڵ� ��������Ʈ ����
			if (sliderHandleRenderer)
			{
				auto handleSprite = new Sprite();
				handleSprite->SetTexture(L"../Resources/Demo/GageUI_Handle.png");
				if (handleSprite->GetTexture())
				{
					handleSprite->SetRect(handleSprite->GetTexture()->GetRect());
				}

				sliderHandleRenderer->SetSprite(handleSprite);
				sliderHandleRenderer->SetRenderOrder(renderOrder + 2);

				if (sliderWidth)
				{
					sliderHandleRenderer->GetTransform()->SetLocalPosition({ sliderWidth,0 });
				}
			}
		}

		void Update()
		{
			sliderBarRenderer->GetTransform()->SetLocalScale({ m_value,1.0f });
			sliderHandleRenderer->GetTransform()->SetLocalPosition({ sliderWidth * m_value, 0.0f });
		}
	};
}