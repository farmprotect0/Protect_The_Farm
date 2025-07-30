#pragma once
#include "Component.h"
#include "Renderer.h"
#include "Matrix3x3.h"

namespace GOTOEngine
{
	class IRenderAPI;
	class Renderer : public Component
	{
	private:
		friend class Camera;
		friend class RenderManager;
		bool m_enabled;
		int m_renderOrder; //�׸� ����
		std::uint32_t m_renderLayer; //������ ���̾� -> ī�޶� ���� ���̾� �ø� ��������

	protected:
		virtual void Render(Matrix3x3& viewMatrix) = 0;
		Renderer();
		~Renderer();

		IRenderAPI* GetRenderAPIFromManager();
	public:
		bool GetEnabled();
		void SetEnabled(bool enabled);
		int GetRenderOrder();
		void SetRenderOrder(int value);
		std::uint32_t GetRenderLayer() { return m_renderLayer; }
		void SetRenderLayer(std::uint32_t layer);
	};
}