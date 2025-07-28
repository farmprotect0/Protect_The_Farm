#pragma once
#include "UIBehaviour.h"
#include "Component.h"
#include "Color.h"

namespace GOTOEngine
{
    class Canvas;
    class RectTransform;

    class Graphic : public UIBehaviour
    {
    private:
        friend class Canvas;
        friend class GameObject;

        Canvas* m_canvas = nullptr;
        Color m_color = { 255, 255, 255, 255 };
        bool m_raycastTarget = true;

    protected:
        // 서브클래스에서 구현할 렌더링 메서드
        virtual void OnRender() = 0;
        virtual ~Graphic();

    public:
        Graphic();

        void OnEnable() override;
        void OnDisable() override;

        // 색상
        void SetColor(const Color& color) { m_color = color; }
        const Color& GetColor() const { return m_color; }

        // Raycast Target
        void SetRaycastTarget(bool raycastTarget) { m_raycastTarget = raycastTarget; }
        bool GetRaycastTarget() const { return m_raycastTarget; }

        // Canvas와 RectTransform 접근
        Canvas* GetCanvas() const { return m_canvas; }
        RectTransform* GetRectTransform() { return dynamic_cast<RectTransform*>(GetGameObject()->GetTransform()); }

        // 렌더링 (Canvas에서 호출)
        void Render();
    };
}