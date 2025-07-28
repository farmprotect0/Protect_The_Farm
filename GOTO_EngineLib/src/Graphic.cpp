#include "Graphic.h"
#include "Canvas.h"
#include "RectTransform.h"

GOTOEngine::Canvas* GOTOEngine::Graphic::FindCanvasInParents()
{
    // 1. ������ Canvas�� ���� �ִٸ� ��ȯ
    if (auto selfCanvas = GetComponent<Canvas>())
        return selfCanvas;

    // 2. �θ� Transform�� ���� �ö󰡸� Canvas Ž��
    auto transform = GetTransform();
    while (transform && transform->GetParent())
    {
        transform = transform->GetParent();

        if (auto canvas = transform->GetComponent<Canvas>())
            return canvas;
    }

    return nullptr;
}

GOTOEngine::Graphic::Graphic() : m_canvas(nullptr), m_color(255, 255,255, 255), m_raycastTarget(true)
{
    REGISTER_BEHAVIOUR_MESSAGE(OnEnable);
    REGISTER_BEHAVIOUR_MESSAGE(OnDisable);
}

GOTOEngine::Graphic::~Graphic()
{
}

void GOTOEngine::Graphic::AdditionalInitialize()
{
    GetTransform()->onHierarchyChanged += std::make_pair(this, &Graphic::OnCanvasHierarchyChanged);
}

void GOTOEngine::Graphic::Dispose()
{
    GetTransform()->onHierarchyChanged -= std::make_pair(this, &Graphic::OnCanvasHierarchyChanged);
}

void GOTOEngine::Graphic::OnEnable()
{
    
}

void GOTOEngine::Graphic::OnDisable()
{
}

void GOTOEngine::Graphic::OnCanvasHierarchyChanged()
{
	auto foundCanvas = FindCanvasInParents();

    if (m_canvas != foundCanvas)
    {
		if (m_canvas)
		{
			m_canvas->UnregisterGraphic(this);
		}
		m_canvas = foundCanvas;
		if (m_canvas)
		{
			m_canvas->RegisterGraphic(this);
		}
    }
}

void GOTOEngine::Graphic::SetColor(const Color& color)
{
}

const GOTOEngine::Color & GOTOEngine::Graphic::GetColor() const
{
    // TODO: ���⿡ return ���� �����մϴ�.
    return m_color;
}

void GOTOEngine::Graphic::SetRaycastTarget(bool raycastTarget)
{
}

bool GOTOEngine::Graphic::GetRaycastTarget() const
{
    return false;
}

GOTOEngine::Canvas* GOTOEngine::Graphic::GetCanvas() const
{
    return m_canvas;
}

GOTOEngine::RectTransform* GOTOEngine::Graphic::GetRectTransform()
{
    return dynamic_cast<RectTransform*>(GetGameObject()->GetTransform());
}

void GOTOEngine::Graphic::Render()
{
}
