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
        // ����Ŭ�������� ������ ������ �޼���
        virtual void OnRender() = 0;
        virtual ~Graphic();

    public:
        Graphic();

        void OnEnable() override;
        void OnDisable() override;

        // ����
        void SetColor(const Color& color) { m_color = color; }
        const Color& GetColor() const { return m_color; }

        // Raycast Target
        void SetRaycastTarget(bool raycastTarget) { m_raycastTarget = raycastTarget; }
        bool GetRaycastTarget() const { return m_raycastTarget; }

        // Canvas�� RectTransform ����
        Canvas* GetCanvas() const { return m_canvas; }
        RectTransform* GetRectTransform() { return dynamic_cast<RectTransform*>(GetGameObject()->GetTransform()); }

        // ������ (Canvas���� ȣ��)
        void Render();
    };
}