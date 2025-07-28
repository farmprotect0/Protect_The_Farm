#pragma once
#include "Behaviour.h"
#include <vector>

namespace GOTOEngine
{
    class Graphic;
    class RectTransform;

    class Canvas : public Behaviour
    {
    private:
        friend class RenderManager;
        friend class Graphic;
        friend class GameObject;

        int m_sortingOrder = 0;
        std::vector<Graphic*> m_graphics;
        bool m_needSort = false;
        RectTransform* m_rectTransform = nullptr;

        void RegisterGraphic(Graphic* graphic);  //�Ŵ����� ����ϴ� ������ ����
        void UnregisterGraphic(Graphic* graphic);
        void SortGraphics();

    public:
        Canvas();
        virtual ~Canvas();

        void OnEnable();
        void OnDisable();

        // Canvas ����
        void SetSortingOrder(int order);
        int GetSortingOrder() const { return m_sortingOrder; }

        // RectTransform ����
        RectTransform* GetRectTransform();

        // ������
        void RenderCanvas();

        // Canvas ũ�� ��� (Constant Pixel Size)
        Vector2 GetCanvasSize() const;
    };
}
