#pragma once

namespace GOTOEngine
{
	class GameObject;
	class ICollideAble
	{
	public:
		virtual ~ICollideAble() = default;
		// ������ �޾��� �� ȣ��Ǵ� �Լ�
		virtual void OnCollide(GameObject* obj) = 0;
	};
}