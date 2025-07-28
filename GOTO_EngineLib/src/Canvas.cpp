#include "Canvas.h"
#include "RectTransform.h"

GOTOEngine::RectTransform* GOTOEngine::Canvas::GetRectTransform()
{
	return dynamic_cast<RectTransform*>( GetGameObject()->GetTransform());
}
