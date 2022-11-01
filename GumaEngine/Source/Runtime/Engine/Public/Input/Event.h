#pragma once

#include "Core.h"

namespace Guma
{
	enum class EventType
	{
		None = 0,
		OnAppTicked, OnAppUpdated, OnAppRendered,
		OnWindowClosed, OnWindowResized,
		OnKeyPressed, OnKeyReleased, OnKeyTyped,
		OnMouseMoved, OnMouseScrolled, OnMouseBtnPressed, OnMouseBtnReleased
	};

	enum EventCategoryType
	{
		None = 0,
		AppEvent = BIT(0),
		InputEvent = BIT(1),
		KeyboardEvent = BIT(2),
		MouseEvent = BIT(3),
		MouseBtnEvent = BIT(4)
	};

#define EVENT_CLASS_TYPE(InEventType)											\
	static EventType GetStaticType() { return EventType::InEventType; }			\
	virtual EventType GetEventType() const override { return GetStaticType(); }	\
	virtual const std::string& GetEventName() const override { return #InEventType; }

#define EVENT_CLASS_CATEGORY(InEventCategoryType)								\
	virtual int GetCategoryFlags() const override { return InEventCategoryType; }

	class EventBase
	{
	public:
		bool bHandled = false;
		
		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual const std::string& GetEventName() const = 0;

		bool IsInCategory(EventCategoryType InEventCategoryType) const
		{
			return InEventCategoryType & GetCategoryFlags();
		}
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(EventBase& InEvent) : Event(InEvent) {}

		template<typename T, typename F>
		bool Dispatch(const F& Function)
		{
			if (Event.GetEventType() == T::GetStaticType())
			{
				Event.bHandled |= Function(static_cast<T&>(Event));
				return true;
			}

			return false;
		}

	private:
		EventBase& Event;
	};

	inline std::ostream& operator<<(std::ostream& InOstream, const EventBase& InEvent)
	{
		return InOstream << InEvent.GetEventName();
	}
}
