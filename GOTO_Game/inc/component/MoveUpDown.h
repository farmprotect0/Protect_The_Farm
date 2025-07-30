#pragma once
#include "BaseMovement.h"
#include <TimeManager.h>
#include "Screen.h"
#include "Transform.h"

#include <math.h>

// enemy의 상하 movement 입니다.

namespace GOTOEngine
{
    class MoveUpDown : public BaseMovement
    {
    private:
        Vector2 m_initialPosition;
        float m_distance = 5.0f;
		float m_maxY;
		float m_minY;

    public:
        void Awake() override
        {
            __super::Awake();

            m_initialPosition = GetGameObject()->GetTransform()->GetPosition();

            m_moveSpeed = 140.0f;

            m_role = E_Move_Role::PATH;

			m_maxY = Screen::GetHeight() * 0.5f;
			m_minY = Screen::GetHeight() * 0.0f;
        }
        Vector2 Move(float deltaTime) override
        {
            if (m_isLoop)
            {
				Vector2 currentPos = GetGameObject()->GetTransform()->GetPosition();
				if ((currentPos.y > m_maxY && GetDirection() > 0) ||
					(currentPos.y < m_minY && GetDirection() < 0))
				{
					FlipDirection();
				}
                return Vector2(0, m_moveSpeed * m_flipDirection * deltaTime);
            }
            else
            {
                float totalTime = TimeManager::Get()->GetTime();
                float deltaY = sin(deltaTime * m_moveSpeed) * m_distance;
                return Vector2(0, deltaY);
            }
        }

    };
}
