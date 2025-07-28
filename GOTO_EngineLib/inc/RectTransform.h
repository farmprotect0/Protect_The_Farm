#pragma once
#include "Transform.h"
#include "Rect.h"

namespace GOTOEngine
{
    class Canvas;

    class RectTransform : public Transform
    {
    private:
        friend class Canvas;
        friend class Graphic;

        // Anchor �ý���
        Vector2 m_anchorMin = { 0.0f, 0.0f };
        Vector2 m_anchorMax = { 1.0f, 1.0f };
        Vector2 m_anchoredPosition = { 0.0f, 0.0f };
        Vector2 m_sizeDelta = { 100.0f, 100.0f };
        Vector2 m_pivot = { 0.5f, 0.5f };

        // ĳ�õ� ����
        mutable bool m_rectDirty = true;
        mutable Rect m_cachedRect;

        Canvas* m_canvas = nullptr;

        void MarkRectDirty();
        void UpdateCanvas();
        Rect CalculateRect() const;

    public:
        RectTransform();
        virtual ~RectTransform();

        // Anchor �ý���
        void SetAnchorMin(const Vector2& anchorMin) { m_anchorMin = anchorMin; MarkRectDirty(); }
        void SetAnchorMax(const Vector2& anchorMax) { m_anchorMax = anchorMax; MarkRectDirty(); }
        void SetAnchors(const Vector2& anchorMin, const Vector2& anchorMax) { m_anchorMin = anchorMin; m_anchorMax = anchorMax; MarkRectDirty(); }
        const Vector2& GetAnchorMin() const { return m_anchorMin; }
        const Vector2& GetAnchorMax() const { return m_anchorMax; }

        // ��ġ�� ũ��
        void SetAnchoredPosition(const Vector2& position) { m_anchoredPosition = position; MarkRectDirty(); }
        const Vector2& GetAnchoredPosition() const { return m_anchoredPosition; }

        void SetSizeDelta(const Vector2& sizeDelta) { m_sizeDelta = sizeDelta; MarkRectDirty(); }
        const Vector2& GetSizeDelta() const { return m_sizeDelta; }

        void SetPivot(const Vector2& pivot) { m_pivot = pivot; MarkRectDirty(); }
        const Vector2& GetPivot() const { return m_pivot; }

        // ���� ����
        Rect GetRect() const;
        Vector2 GetUISize() const;

        // Canvas ����
        Canvas* GetCanvas() const { return m_canvas; }

        // Transform �������̵� - RectTransform ��Ƽ �÷��׵� �Բ� ó��
        void SetParent(Transform* parent, bool worldPositionStays = true) override;
    };
}