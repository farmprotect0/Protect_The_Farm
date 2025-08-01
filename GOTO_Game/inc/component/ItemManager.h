#pragma once
#include <ScriptBehaviour.h>
#include <TimeManager.h>
#include <InputManager.h>
#include <RenderManager.h>
#include <SpriteRenderer.h>
#include <Animator.h>
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
		std::vector<ItemType> p1Items;
		std::vector<ItemType> p2Items;
		float p1TicketTimer = 0.0f;
		float p2TicketTimer = 0.0f;
		float p1IceTimer = 0.0f;
		float p2IceTimer = 0.0f;
		const float timelimit = 5.0f;
		Image* p1itemImage[7];
		Image* p2itemImage[7];
	public:
    ItemManager()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(OnDestroy);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		static ItemManager* instance;

		void Awake();
		int p1count = 0;
		int p2count = 0;
		void Update();
		void OnDestroy();
		void UseItem(int player, ItemType item);
		void AddItem(int player, ItemType item);
	};
}