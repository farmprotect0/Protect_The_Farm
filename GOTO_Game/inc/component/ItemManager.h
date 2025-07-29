#pragma once
#include <ScriptBehaviour.h>
#include <TimeManager.h>
#include <InputManager.h>
#include <RenderManager.h>
#include <SpriteRenderer.h>
#include <queue>
#include "Canvas.h"
#include "Image.h"
#include "RectTransform.h"
#include "Screen.h"

namespace GOTOEngine
{
	enum class ItemType {
		Bomb = 0, Icebomb, Ticket
	};
	class ItemManager : public ScriptBehaviour
	{
	private:
		std::queue<ItemType> p1Items;
		std::queue<ItemType> p2Items;
		float p1TicketTimer = 0.0f;
		float p2TicketTimer = 0.0f;
		float p1IceTimer = 0.0f;
		float p2IceTimer = 0.0f;
		const float timelimit = 5.0f;
		GameObject* canvas;
		Image* p1itemImage;
		Image* p2itemImage;
	public:
    ItemManager()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		static ItemManager* instance;

		void Awake();
		int p1count = 0;
		int p2count = 0;
		void Update();
		void UseItem(int player, ItemType item);
	};
}