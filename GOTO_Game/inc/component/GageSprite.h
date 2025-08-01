#pragma once
#include <ScriptBehaviour.h>
#include <SpriteRenderer.h>
#include <Transform.h>
#include <Texture2D.h>

namespace GOTOEngine
{
	class GageSprite : public ScriptBehaviour
	{
	private:
	public:
    GageSprite()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
    }

		SpriteRenderer* backgroundRenderer;
		SpriteRenderer* gagebarRenderer;
		SpriteRenderer* gagehandleRenderer;

		int renderOrder = 504;

		void Awake()
		{
			auto gagebarWidth = 0.0f;

			//백그라운드 스프라이트 설정
			if (backgroundRenderer)
			{
				auto backgroundSprite = new Sprite();
				backgroundSprite->SetTexture(L"../Resources/Demo/GageUI_Back.png");
				backgroundSprite->SetPivotX(0.0f);

				if (backgroundSprite->GetTexture())
				{
					backgroundSprite->SetRect(backgroundSprite->GetTexture()->GetRect());
					gagebarWidth = backgroundSprite->GetRect().width;
				}

				backgroundRenderer->SetSprite(backgroundSprite);
				backgroundRenderer->SetRenderOrder(renderOrder);
			}

			//게이지 바 스프라이트 설정
			if (gagebarRenderer)
			{
				auto gagebarSprite = new Sprite();
				gagebarSprite->SetTexture(L"../Resources/Demo/GageUI_Front.png");
				gagebarSprite->SetPivotX(0.0f);
				if (gagebarSprite->GetTexture())
				{
					gagebarSprite->SetRect(gagebarSprite->GetTexture()->GetRect());
				}

				gagebarRenderer->SetSprite(gagebarSprite);
				gagebarRenderer->SetRenderOrder(renderOrder + 1);
			}

			//게이지 핸들 스프라이트 설정
			if (gagehandleRenderer)
			{
				auto gagehandleSprite = new Sprite();
				gagehandleSprite->SetTexture(L"../Resources/Demo/GageUI_Handle.png");
				if (gagehandleSprite->GetTexture())
				{
					gagehandleSprite->SetRect(gagehandleSprite->GetTexture()->GetRect());
				}

				gagehandleRenderer->SetSprite(gagehandleSprite);
				gagehandleRenderer->SetRenderOrder(renderOrder + 2);

				if (gagebarWidth)
				{
					gagehandleRenderer->GetTransform()->SetLocalPosition({ gagebarWidth,0 });
				}
			}
		}
	};
}