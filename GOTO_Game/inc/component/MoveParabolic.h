#pragma once
#include "BaseMovement.h"
#include <TimeManager.h>
#include "Screen.h"
#include "Transform.h"

#include <math.h>
#include <utility>

namespace GOTOEngine
{
    class MoveParabolic : public BaseMovement
    {
    private:
        float m_height = 50.0f;     // 포물선의 높이각도
        float m_distance = 0.2f;     // 포물선의 거리 화면 비율

        // PATH 포물선 이동의 시작과 끝점
        Vector2 m_startPos;
        Vector2 m_endPos;
        float m_progress = 0.0f;     // 포물선 진행도 (0.0 ~ 1.0)
        float m_arcDuration = 2.0f;  // 포물선 전체 이동 시간

        // 안 쓰는 변수
        float m_maxX;
        float m_minX;

        bool m_flipXY;

    public:
        Delegate<void> OnFlipDirection;

    public:
        void Initialize(E_Move_Role moverole, bool flipXY)
        {
            m_role = moverole;
            m_flipXY = flipXY;
        }
        void Awake() override
        {
            __super::Awake();

            m_distance = Screen::GetWidth() * m_distance;
            // 좌우 방향
            // m_flipDirection = -1.0f;

            Vector2 curPos = GetGameObject()->GetTransform()->GetPosition();

            m_startPos = Vector2( curPos.x * m_flipDirection, curPos.y);
            m_endPos = Vector2((curPos.x + m_distance )* m_flipDirection, curPos.y);

            m_moveSpeed = 80.0f;

            //m_role = E_Move_Role::PATH;
            //m_role = E_Move_Role::OFFSET;
        }
        Vector2 Move(float deltaTime) override
        {
            switch (m_role)
            {
            case E_Move_Role::PATH:
            {
                // 진행도 progress 
                m_progress += deltaTime / m_arcDuration;
                if (m_progress > 1.0f)
                {
                    if (m_isLoop)
                    { 
                        m_progress = 0.0f; 
                        m_flipDirection *= -1;/*delegate*/ 
                        std::swap(m_startPos, m_endPos);
                    }
                    else m_progress = 1.0f;
                }

                // 수평 위치(x) 계산 
                float currentX = m_startPos.x + (m_endPos.x - m_startPos.x) * m_progress;
                // 수직 위치(y) 아래 방향 포물선 계산 
                // y = -4 * h * ( x - x^2 )
                float parabolicY = -4 * m_height * (m_progress - m_progress * m_progress);
                // 이번 프레임 목표 위치 계산
                Vector2 targetPos = Vector2(currentX, m_startPos.y + parabolicY);

                // 현재 위치에서 목표 위치로의 이동량 반환
                return targetPos - GetGameObject()->GetTransform()->GetPosition();
            }
            break;
            case  E_Move_Role::OFFSET:
            {
                if (m_flipXY)
                {
                    float time = fmod(TimeManager::Get()->GetTime(), m_arcDuration);
                    float progress = time / m_arcDuration;

                    // Y축 오프셋만 계산
                    float offsetX = 4 * 5.0f * (progress - progress * progress);

                    // Y축 오프셋 벡터 반환
                    return Vector2(offsetX, 0);
                }
                else
                {
                    float time = fmod(TimeManager::Get()->GetTime(), m_arcDuration);
                    float progress = time / m_arcDuration;

                    // Y축 오프셋만 계산
                    float offsetY = 4 * m_height * (progress - progress * progress);

                    // Y축 오프셋 벡터 반환
                    return Vector2(0, offsetY);
                }
            }
                break;
            default:
            {
                return Vector2::Zero();
            }
                break;
            }
            return Vector2::Zero();
        }

    };
}
