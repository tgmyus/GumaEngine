#pragma once

#include "Precompiled.h"

namespace Guma
{
	class WindowProps
	{
	public:
		WindowProps(const std::string& InTitle = "Guma Engine", unsigned int InWidth = 1600, unsigned int InHeight = 900)
			: Title(InTitle), Width(InWidth), Height(InHeight) {}

		std::string Title;
		unsigned int Width;
		unsigned int Height;
	};

	class WindowBase
	{
	public:
		static std::unique_ptr<WindowBase> Create(const WindowProps& InWindowProps = WindowProps());

		virtual void* GetNativeWindow() const = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual bool IsEnabledVSync() const = 0;
		virtual void SetEnabledVSync(bool bInEnabledVSync) = 0;

		using CallbackEventType = std::function<void(class EventBase&)>;
		virtual void SetCallbackEvent(const CallbackEventType& InCallbackEvent) = 0;

		virtual void Update() = 0;
	};
}
