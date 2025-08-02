#include "CrosshairFire.h"

GOTOEngine::RumbleAnimationClip* GOTOEngine::CrosshairFire::s_pfireRumbleClip = nullptr;
int GOTOEngine::CrosshairFire::s_crosshairCount = 0;

void GOTOEngine::CrosshairFire::Awake()
{
	m_collider = GetComponent<CrosshairCollide>();

	if (!s_pfireRumbleClip)
	{
		s_pfireRumbleClip = new RumbleAnimationClip(AnimationCurve{ R"({
    "keyframes": [
        {
            "time": 0.0,
            "value": 1.0,
            "in_tangent": -0.375,
            "out_tangent": -0.375,
            "tangent_mode": 0
        },
        {
            "time": 0.135,
            "value": 0.4575,
            "in_tangent": -0.2,
            "out_tangent": -0.2,
            "tangent_mode": 1
        },
        {
            "time": 0.28,
            "value": 0.4775,
            "in_tangent": -0.35,
            "out_tangent": -0.35,
            "tangent_mode": 1
        },
        {
            "time": 0.34,
            "value": 0.0,
            "in_tangent": 0.0,
            "out_tangent": 0.0,
            "tangent_mode": 1
        },
        {
            "time": 1.0,
            "value": 0.0,
            "in_tangent": 0.0,
            "out_tangent": 0.0,
            "tangent_mode": 1
        }
    ]
})" }, AnimationCurve{ R"({
    "keyframes": [
        {
            "time": 0.0,
            "value": 1.0,
            "in_tangent": -0.375,
            "out_tangent": -0.375,
            "tangent_mode": 0
        },
        {
            "time": 0.135,
            "value": 0.4575,
            "in_tangent": -0.2,
            "out_tangent": -0.2,
            "tangent_mode": 1
        },
        {
            "time": 0.28,
            "value": 0.4775,
            "in_tangent": -0.35,
            "out_tangent": -0.35,
            "tangent_mode": 1
        },
        {
            "time": 0.34,
            "value": 0.0,
            "in_tangent": 0.0,
            "out_tangent": 0.0,
            "tangent_mode": 1
        },
        {
            "time": 1.0,
            "value": 0.0,
            "in_tangent": 0.0,
            "out_tangent": 0.0,
            "tangent_mode": 1
        }
    ]
})" }, 1.0f);
	}

	s_crosshairCount++;
}

void GOTOEngine::CrosshairFire::OnEnable()
{
	m_fireCooldown = 0.0f;
	m_RightTriggerCheckTrigger = false;
	TriggerPressedCheckReset();
}

void GOTOEngine::CrosshairFire::OnDestroy()
{
    s_crosshairCount--;
    if (s_crosshairCount <= 0)
    {
        delete s_pfireRumbleClip;
        s_pfireRumbleClip = nullptr;
    }
}


void GOTOEngine::CrosshairFire::TriggerPressedCheck()
{
	auto currentRightTrigger = INPUT_GET_GAMEPAD_AXIS(id, GamepadAxis::RightTrigger);
	if (!m_RightTriggerCheckTrigger)
	{
		if (currentRightTrigger > 0.89f)
		{
			m_RightTriggerCheckTrigger = true;
			m_RightTriggerPressed = true;
			return;
		}
	}
	else if ((m_RightTriggerCheckTrigger && currentRightTrigger < 0.2f))
	{
		m_RightTriggerCheckTrigger = false;
	}
}

void GOTOEngine::CrosshairFire::TriggerPressedCheckReset()
{
	m_RightTriggerPressed = false;
}

void GOTOEngine::CrosshairFire::Update()
{
	TriggerPressedCheckReset();
	TriggerPressedCheck();

	m_fireCooldown -= TIME_GET_DELTATIME();
	m_fireCooldown = Mathf::Max(m_fireCooldown, 0.0f);

	if (m_fireCooldown > 0.0f)
		return;

	//�Է� ����: �÷��̾� ID�� Ű �Ǵ� ��ư �Է�
	bool firePressed = (id == 0 && INPUT_GET_KEYDOWN(KeyCode::LeftShift)) ||
		(id == 1 && INPUT_GET_KEYDOWN(KeyCode::RightShift)) ||
		INPUT_GET_GAMEPAD_BUTTONDOWN(id, GamepadButton::ButtonSouth) ||
		m_RightTriggerPressed;

	if (!firePressed || !IsValidObject(m_collider))
		return;

	m_fireCooldown = fireRate;

    GamepadRumbleManager::instance->Play(id, *s_pfireRumbleClip, 1.0f);

	for (auto* obj : m_collider->GetCollideObjects())
	{
		std::wcout << obj->name << std::endl;

		for (auto* comp : obj->GetAllComponents())
		{
			if (auto* attackable = dynamic_cast<IAttackAble*>(comp))
			{
				attackable->TakeDamage(1);
			}
		}
	}

	onFire.Invoke(id);
	std::cout << "Crosshair Fire! : " << id << std::endl;
}
