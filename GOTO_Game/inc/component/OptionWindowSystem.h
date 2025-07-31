#pragma once
#include <ScriptBehaviour.h>
#include <AnimationCurve.h>
#include <InputManager.h>

namespace GOTOEngine
{
	class OptionWindowSystem : public ScriptBehaviour
	{
	private:
		AnimationCurve m_openAnimation;
		float m_animationTime = 0.0f; // 0.0f ~ 1.0f
		bool m_isOpen = true;

		int m_focusIndex = 0;
	public:
    OptionWindowSystem()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(OnEnable);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		Transform* baseWindow = nullptr;
        float openAnimScale = 1.0f;

		void Awake()
		{
            std::string anim = R"({
    "keyframes": [
        {
            "time": 0,
            "value": 0,
            "in_tangent": 0.3875,
            "out_tangent": -0.5375,
            "tangent_mode": 0
        },
        {
            "time": 0.54,
            "value": 1.2075,
            "in_tangent": -0.3386679358984317,
            "out_tangent": -0.3386679358984317,
            "tangent_mode": 1
        },
        {
            "time": 0.715,
            "value": 0.8725,
            "in_tangent": 0,
            "out_tangent": 0,
            "tangent_mode": 1
        },
        {
            "time": 0.89,
            "value": 1.0675,
            "in_tangent": 0,
            "out_tangent": 0,
            "tangent_mode": 1
        },
        {
            "time": 1,
            "value": 1,
            "in_tangent": 1,
            "out_tangent": 0,
            "tangent_mode": 1
        }
    ]
})";
            m_openAnimation = AnimationCurve(anim);
		}

        void OnEnable()
        {
            m_isOpen = true;
        }

		void Update()
		{
            if (IsValidObject(baseWindow))
            {
				// �ִϸ��̼� �ð� ������Ʈ
				m_animationTime += (m_isOpen ? TIME_GET_DELTATIME() : -TIME_GET_DELTATIME()) * 1.5f;
				if (m_animationTime > 1.0f)
					m_animationTime = 1.0f;
				// �ִϸ��̼� �� ���
				float animValue = m_openAnimation.Evaluate(m_animationTime);
				openAnimScale = animValue;
				// ������ ũ�� ����
                baseWindow->SetLocalScale({ animValue, animValue });
				// ESC Ű�� â �ݱ�
				if (InputManager::Get()->GetKeyDown(KeyCode::Escape)
                    || INPUT_GET_GAMEPAD_BUTTONDOWN(0, GamepadButton::ButtonEast)
                    || INPUT_GET_GAMEPAD_BUTTONDOWN(1, GamepadButton::ButtonEast))
				{
					m_isOpen = false;
				}

				if (!m_isOpen && m_animationTime <= 0.0f)
				{
					// �ִϸ��̼��� ������ â�� ��Ȱ��ȭ
                    m_animationTime = 0.0f; // �ִϸ��̼� �ʱ�ȭ
                    GetGameObject()->SetActive(false);
                    baseWindow->SetLocalScale({ 0, 0 });
				}
            }
		}
	};
}