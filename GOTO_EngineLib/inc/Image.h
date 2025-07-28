#pragma once
#include "Graphic.h"

namespace GOTOEngine
{
	class Image : public Graphic
	{
	public:
		Image() : Graphic() {}
		void Render() override {}
	};
}