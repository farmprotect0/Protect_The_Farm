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

		GameObject* m_cachedPlayer1 = nullptr;
		GameObject* m_cachedPlayer2 = nullptr;

		int m_focusIndex = 0;
	public:
    OptionWindowSystem()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(OnDisable);
        REGISTER_BEHAVIOUR_MESSAGE(OnEnable);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		Transform* baseWindow = nullptr;
        Transform* focusUITransform = nullptr;
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

			m_cachedPlayer1 = GameObject::Find(L"Player1");
			m_cachedPlayer2 = GameObject::Find(L"Player2");
		}

        void OnEnable()
        {
            m_isOpen = true;

			if(IsValidObject(m_cachedPlayer1))
				m_cachedPlayer1->SetActive(false);
			if (IsValidObject(m_cachedPlayer2))
				m_cachedPlayer2->SetActive(false);
        }

        void OnDisable()
        {
            m_focusIndex = 0;

            if (IsValidObject(m_cachedPlayer1))
                m_cachedPlayer1->SetActive(true);
            if (IsValidObject(m_cachedPlayer2))
                m_cachedPlayer2->SetActive(true);
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

			if (IsValidObject(focusUITransform) && m_isOpen)
			{
                // ��Ŀ�� �ε��� ����/����
                if (InputManager::Get()->GetKeyDown(KeyCode::DownArrow))
                {
                    m_focusIndex++;
                    if (m_focusIndex > 4) // ���÷� 3���� ��ư�� �ִٰ� ����
                        m_focusIndex = 4;
                
                }
                if (InputManager::Get()->GetKeyDown(KeyCode::UpArrow))
                {
                    m_focusIndex--;
                    if (m_focusIndex < 0)
                        m_focusIndex = 0;
                }


				// ��Ŀ�� UI ��ġ ������Ʈ
                auto focusSpace = 80.0f;

                auto startPosY = 150.0f;

				auto targetPosY = startPosY + focusSpace * -m_focusIndex;

				auto pos = Vector2::Lerp(
					focusUITransform->GetLocalPosition(),
					{ 0.0f, targetPosY },
					TIME_GET_DELTATIME() * 10.0f);

			
				focusUITransform->SetLocalPosition(pos);
			}
		}
	};
}