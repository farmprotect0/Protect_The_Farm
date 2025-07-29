#pragma once
#include <ScriptBehaviour.h>

namespace GOTOEngine
{
    enum E_Enemy_Move_Type
    {
        NONE = 0,					// 아무 움직임 없음 (0000)
        MOVE_LEFT_RIGHT = 1 << 0,	// 좌우 이동 (0001)
        MOVE_UP_DOWN = 1 << 1,		// 상하 이동 (0010)
        MOVE_CIRCULAR = 1 << 2,		// 원형 이동 (0100)
        MOVE_PARABOLIC = 1 << 3,	// 포물선 이동 (1000)
        // 이동 추가
    };

    class BaseMovement : public ScriptBehaviour
    {
    public:
    BaseMovement()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
    }
   
        virtual void Awake() {}
        virtual void Initialize() {}
        virtual Vector2 Move(float deltaTime) = 0;

    protected:
        float m_moveSpeed = 10.0f;
    };
}