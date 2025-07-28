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

        void RegisterGraphic(Graphic* graphic);  //매니저가 담당하는 것으로 변경
        void UnregisterGraphic(Graphic* graphic);
        void SortGraphics();

    public:
        Canvas();
        virtual ~Canvas();

        void OnEnable();
        void OnDisable();

        // Canvas 설정
        void SetSortingOrder(int order);
        int GetSortingOrder() const { return m_sortingOrder; }

        // RectTransform 접근
        RectTransform* GetRectTransform();

        // 렌더링
        void RenderCanvas();

        // Canvas 크기 계산 (Constant Pixel Size)
        Vector2 GetCanvasSize() const;
    };
}
