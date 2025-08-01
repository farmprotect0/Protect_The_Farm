#pragma once
#include "BaseMovement.h"
#include <TimeManager.h>
#include "Screen.h"
#include "Transform.h"

#include <math.h>
#include <utility>

// enemy에 쓰이는 movement 입니다.

namespace GOTOEngine
{
    class MoveParabolic : public BaseMovement
    {
    private:
        float m_height = 50.0f;     // 포물선의 높이각도
        float m_distance = 0.2f;     // 포물선의 거리 화면 비율

        // PATH 일 때, 이전 프레임 위치 기억변수
        Vector2 m_lastPathPos; 
        Vector2 m_startPos;
        Vector2 m_endPos;
        float m_progress = 0.0f;     // 포물선 진행도 (0.0 ~ 1.0)
        float m_arcDuration = 2.0f;  // 포물선 전체 이동 시간

        bool m_flipXY;

    public:
        Delegate<void> OnFlipDirection;

    public:
        void Awake() override
        {
            __super::Awake();

            if (m_flag & (MOVE_LEFT_RIGHT | MOVE_UP_DOWN))
            {
                m_role = E_Move_Role::OFFSET;
                if ((m_flag & MOVE_LEFT_RIGHT) && (m_flag & MOVE_UP_DOWN))
                {
                    //m_arcDuration = 4.0f;
                    //m_height = 30.0f;
                }
                else m_flipXY = m_flag & MOVE_UP_DOWN;
            }
            else m_role = E_Move_Role::PATH;


            Vector2 curPos = GetGameObject()->GetTransform()->GetPosition();
            m_startPos = Vector2( curPos.x * m_flipDirection, curPos.y);
            m_endPos = Vector2((curPos.x + m_distance )* m_flipDirection, curPos.y);

            m_moveSpeed = 80.0f;
            m_distance = Screen::GetWidth() * m_distance;

            if (m_role == E_Move_Role::PATH)
            {
                m_lastPathPos = m_startPos;
            }
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
                        m_lastPathPos = m_startPos;
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

                // 목표 위치 - 이전 프레임 PATH 위치
                Vector2 pathPos = targetPos - m_lastPathPos;
                // 다음 프레임을 위해 저장
                m_lastPathPos = targetPos;

                // 현재 위치에서 목표 위치로의 이동량 반환
                return pathPos;
            }
            break;
            case  E_Move_Role::OFFSET:
            {
                if (m_flipXY)
                {
                    float time = fmod(TimeManager::Get()->GetTime(), m_arcDuration);
                    float progress = time / m_arcDuration;

                    // X축 오프셋만 계산
                    float offsetX = 4 * m_height * (progress - progress * progress);
                 
                    // X축 오프셋 벡터 반환
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
