#pragma once

#include "Window.h"

#include <GLFW/glfw3.h>

namespace Guma
{
	class WindowsWindow : public WindowBase
	{
	public:
		WindowsWindow(const WindowProps& InWindowProps);
		virtual ~WindowsWindow();

		virtual void* GetNativeWindow() const override { return Window; }

		virtual unsigned int GetWidth() const override { return Data.Width; }
		virtual unsigned int GetHeight() const override { return Data.Height; }

		virtual bool IsEnabledVSync() const override { return Data.bEnabledVSync; }
		virtual void SetEnabledVSync(bool bInEnabledVSync) override;

		virtual void SetCallbackEvent(const CallbackEventType& InCallbackEvent) override { Data.CallbackEvent = InCallbackEvent; }

		virtual void Update() override;

	private:
		virtual void Init(const WindowProps& InWindowProps);
		virtual void Shutdown();

		GLFWwindow* Window;
		
		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool bEnabledVSync;

			CallbackEventType CallbackEvent;
		} Data;
	};
}
