#pragma once
#include "Graphic.h"
#include "Sprite.h"

namespace GOTOEngine
{
	class Image : public Graphic
	{
	private:
		Sprite* m_sprite = nullptr;
	public:
		Image() : Graphic() {}
		void SetSprite(Sprite* sprite);
		Sprite* GetSprite() { return m_sprite; };
		void Render() override;
	};
}