#pragma once
#include "BaseMovement.h"
#include <TimeManager.h>

#include <math.h>

// enemy�� ���̴� movement �Դϴ�.

namespace GOTOEngine
{
    class MoveCircle : public BaseMovement
    {
    private:
        float m_radius = 1.0f;

    public:
        void Awake() override
        {
            __super::Awake();
            m_moveSpeed = 30.0f;            // ���� ���� �ӵ�
            m_role = E_Move_Role::OFFSET;
        }

        Vector2 Move(float deltaTime) override
        {
            float totalTime = TimeManager::Get()->GetTime();
            float angle = totalTime * m_moveSpeed;

            return Vector2(cos(angle) * m_radius, sin(angle) * m_radius);
        }
    };
}