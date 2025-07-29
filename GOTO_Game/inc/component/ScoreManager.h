#pragma once
#include <ScriptBehaviour.h>
#include <RenderManager.h>
#include <SpriteRenderer.h>

namespace GOTOEngine
{
	class ScoreManager : public ScriptBehaviour
	{
	public:
    ScoreManager()
    {

    }
		int P1Score = 0;
		int P2Score = 0;
		int P1Bonus = 1;
		int P2Bonus = 1;
	};
}