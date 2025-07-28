#include "RectTransform.h"
#include "Canvas.h"


GOTOEngine::RectTransform::RectTransform()
{
}

GOTOEngine::RectTransform::~RectTransform()
{
}

void GOTOEngine::RectTransform::SetAnchorMin(const Vector2& anchorMin)
{
}

void GOTOEngine::RectTransform::SetAnchorMax(const Vector2& anchorMax)
{
}

void GOTOEngine::RectTransform::SetAnchors(const Vector2& anchorMin, const Vector2& anchorMax)
{

}

const GOTOEngine::Vector2& GOTOEngine::RectTransform::GetAnchorMin() const
{
	// TODO: 여기에 return 문을 삽입합니다.
	return m_anchorMin;
}

const GOTOEngine::Vector2& GOTOEngine::RectTransform::GetAnchorMax() const
{
	// TODO: 여기에 return 문을 삽입합니다.
	return m_anchorMax;
}

void GOTOEngine::RectTransform::SetAnchoredPosition(const Vector2& position)
{
	m_anchoredPosition = position;
}

const GOTOEngine::Vector2& GOTOEngine::RectTransform::GetAnchoredPosition() const
{
	// TODO: 여기에 return 문을 삽입합니다.
	return m_anchoredPosition;
}

void GOTOEngine::RectTransform::SetSizeDelta(const Vector2& sizeDelta)
{
}

const GOTOEngine::Vector2& GOTOEngine::RectTransform::GetSizeDelta() const
{
	// TODO: 여기에 return 문을 삽입합니다.
	return m_sizeDelta;
}

void GOTOEngine::RectTransform::SetPivot(const Vector2& pivot)
{
}

const GOTOEngine::Vector2& GOTOEngine::RectTransform::GetPivot() const
{
	// TODO: 여기에 return 문을 삽입합니다.
	return m_pivot;
}

void GOTOEngine::RectTransform::SetParent(Transform* parent, bool worldPositionStays)
{
	Transform::SetParent(parent, worldPositionStays);
}
