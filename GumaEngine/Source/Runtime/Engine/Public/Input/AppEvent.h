#pragma once

#include "Event.h"

namespace Guma
{
	class AppTickEvent : public EventBase
	{
	public:
		EVENT_CLASS_TYPE(OnAppTicked)
		EVENT_CLASS_CATEGORY(AppEvent)
	};

	class AppUpdateEvent : public EventBase
	{
	public:
		EVENT_CLASS_TYPE(OnAppUpdated)
		EVENT_CLASS_CATEGORY(AppEvent)
	};

	class AppRenderEvent : public EventBase
	{
	public:
		EVENT_CLASS_TYPE(OnAppRendered)
		EVENT_CLASS_CATEGORY(AppEvent)
	};

	class WindowCloseEvent : public EventBase
	{
	public:
		EVENT_CLASS_TYPE(OnWindowClosed)
		EVENT_CLASS_CATEGORY(AppEvent)
	};

	class WindowResizeEvent : public EventBase
	{
	public:
		EVENT_CLASS_TYPE(OnWindowResized)
		EVENT_CLASS_CATEGORY(AppEvent)

		WindowResizeEvent(unsigned int InWidth, unsigned int InHeight) : Width(InWidth), Height(InHeight) {}

		unsigned int GetWidth() const { return Width; }
		unsigned int GetHeight() const { return Height; }

	private:
		unsigned int Width;
		unsigned int Height;
	};
}
