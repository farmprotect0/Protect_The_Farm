#pragma once
#include "UIBehaviour.h"
#include "Color.h"

namespace GOTOEngine
{
	class Graphic : public UIBehaviour
	{
	private:
		Canvas* m_canvas;
		Color m_color;
		bool m_raycastTarget;
		int m_sortOrder = 0; // 렌더링 순서

        void OnEnable();
        void OnDisable();
        void OnCanvasHierarchyChanged() override;

	public:
        Graphic();
        virtual ~Graphic();

		void AdditionalInitialize() override;

        void Dispose() override;

        Canvas* FindCanvasInParents();

        // 색상
        void SetColor(const Color& color);
        const Color& GetColor() const;

        // Raycast Target
        void SetRaycastTarget(bool raycastTarget);
        bool GetRaycastTarget() const;

        // Canvas와 RectTransform 접근
        Canvas* GetCanvas() const;
		void SetCanvas(Canvas* canvas) { m_canvas = canvas; }
        RectTransform* GetRectTransform();
		void SetSortOrder(int order) { m_sortOrder = order; }
		int GetSortOrder() const { return m_sortOrder; }

        // 렌더링 (Canvas에서 호출)
        virtual void Render() = 0;
	};
}