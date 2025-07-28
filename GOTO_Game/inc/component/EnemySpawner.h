#pragma once
#include <ScriptBehaviour.h>
#include "MoveEnemy.h"
#include "GimmickEnemy.h"
#include "ItemEnemy.h"

namespace GOTOEngine
{
	class EnemySpawner : public ScriptBehaviour
	{
	public:
    EnemySpawner()
    {

    }


	public:
		virtual ~EnemySpawner() = default;

	};
}