#pragma once
#include <ScriptBehaviour.h>
#include <SpriteRenderer.h>
#include <Transform.h>

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

		int renderLayer = 502;

		void Awake()
		{
			auto gagebarWidth = 0.0f;

			//��׶��� ��������Ʈ ����
			if (backgroundRenderer)
			{
				auto backgroundSprite = new Sprite();
				backgroundSprite->SetTexture(L"../Resources/Demo/GageUI_Back.png");
				backgroundSprite->SetPivotX(0.0f);
				if (backgroundSprite->GetTexture())
					gagebarWidth = backgroundSprite->GetRect().width;

				backgroundRenderer->SetSprite(backgroundSprite);
				backgroundRenderer->SetRenderLayer(renderLayer);
			}

			//������ �� ��������Ʈ ����
			if (gagebarRenderer)
			{
				auto gagebarSprite = new Sprite();
				gagebarSprite->SetTexture(L"../Resources/Demo/GageUI_Front.png");
				gagebarSprite->SetPivotX(0.0f);

				gagebarRenderer->SetSprite(gagebarSprite);
				gagebarRenderer->SetRenderLayer(renderLayer + 1);
			}

			//������ �ڵ� ��������Ʈ ����
			if (gagehandleRenderer)
			{
				auto gagehandleSprite = new Sprite();
				gagehandleSprite->SetTexture(L"../Resources/Demo/GageUI_Handle.png");

				gagehandleRenderer->SetSprite(gagehandleSprite);
				gagehandleRenderer->SetRenderLayer(renderLayer + 2);

				if (gagebarWidth)
				{
					gagehandleRenderer->GetTransform()->SetLocalPosition({ gagebarWidth,0 });
				}
			}
		}
	};
}