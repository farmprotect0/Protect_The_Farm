#pragma once

namespace GOTOEngine
{
	class IAttackAble
	{
	public:
		virtual ~IAttackAble() = default;
		// ������ �޾��� �� ȣ��Ǵ� �Լ�
		virtual void TakeDamage(float damage) = 0;
	};
}