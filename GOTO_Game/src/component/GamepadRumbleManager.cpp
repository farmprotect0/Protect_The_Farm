#include "GamepadRumbleManager.h"
#include <TimeManager.h>
#include <Mathf.h>
#include <InputManager.h>

GOTOEngine::GamepadRumbleManager* GOTOEngine::GamepadRumbleManager::instance = nullptr;

void GOTOEngine::GamepadRumbleManager::Awake()
{
	if (instance == nullptr)
	{
		instance = this;
		DontDestroyOnLoad(this);
	}
	else
	{
		Destroy(GetGameObject());
	}
}

void GOTOEngine::GamepadRumbleManager::Play(int padID, const RumbleAnimationClip& rumbleClip, float weight)
{
	m_activeRumbles.emplace_back(ActiveRumble{ padID,rumbleClip,weight });
}

void GOTOEngine::GamepadRumbleManager::ClearFinishedClips()
{
    // isFinished�� true�� Ŭ������ �迭���� ����
    auto newEnd = std::remove_if(m_activeRumbles.begin(), m_activeRumbles.end(),
        [](const ActiveRumble& rumble) {
            return rumble.isFinished;
        });

    m_activeRumbles.erase(newEnd, m_activeRumbles.end());
}

void GOTOEngine::GamepadRumbleManager::Update()
{
    float finalRightMotor[4] { 0.0f, };
    float finalLeftMotor[4] { 0.0f, };
    float totalWeight[4]{ 0.0f, };

    // ���� ��� ���� ��� ���� Ŭ���� ��ȸ
    for (auto& active : m_activeRumbles)
    {
        // 1. �ð� ������Ʈ
        active.elapsedTime += TIME_GET_DELTATIME();

        // 2. ������ ���� ����ġ ��� (�ʿ信 ���� �����ϰ� ���� �� ����)
        // ���� ���, Ŭ���� ���� �� ���̵� �ƿ�(Fade-out) ȿ���� �� �� �ֽ��ϴ�.
        float currentWeight = active.weight;

        // 3. ���� �� ���ø�
        float clampedTime = Mathf::Clamp(active.elapsedTime, 0.0f, active.clip.length);

        // ����� �������� Ȯ���ϰ� �÷��� ����
        if (active.elapsedTime >= active.clip.length)
        {
            active.isFinished = true;
        }

        float currentRight = active.clip.rightMotorCurve.Evaluate(clampedTime);
        float currentLeft = active.clip.leftMotorCurve.Evaluate(clampedTime);

        // 4. ����ġ�� ���� ���� ���� ���ϱ�
        finalRightMotor[active.id] += Mathf::Clamp01(currentRight) * currentWeight;
        finalLeftMotor[active.id] += Mathf::Clamp01(currentLeft) * currentWeight;
        totalWeight[active.id] += currentWeight;
    }

    ClearFinishedClips();


    for (int i = 0; i < 4; ++i)
    {
        // 5. ����ȭ(Normalize)
        if (totalWeight[i] > 0.0f)
        {
            finalRightMotor[i] /= totalWeight[i];
            finalLeftMotor[i] /= totalWeight[i];
        }

        // 6. ���� ���� ���� �����е忡 ����
        INPUT_SET_GAMEPAD_VIBRATION(i, finalLeftMotor[i], finalRightMotor[i]);
    }
}
