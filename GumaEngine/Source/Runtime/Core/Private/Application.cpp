#include "Precompiled.h"
#include "Application.h"

#include "Input/AppEvent.h"

#include <GLFW/glfw3.h>

namespace Guma
{
#define BIND_CALLBACK_EVENT(InFunction) std::bind(&InFunction, this, std::placeholders::_1)

	Application::Application()
	{
		Window = WindowBase::Create(WindowProps());
		Window->SetCallbackEvent(BIND_CALLBACK_EVENT(Application::OnEventDispatched));
	}

	void Application::OnEventDispatched(EventBase& InEvent)
	{
		EventDispatcher Dispatcher(InEvent);
		Dispatcher.Dispatch<WindowCloseEvent>(BIND_CALLBACK_EVENT(Application::OnWindowClosed));
	}

	bool Application::OnWindowClosed(const WindowCloseEvent& InEvent)
	{
		bRunning = false;
		return true;
	}

	void Application::Run()
	{
		while (bRunning && Window.get())
		{
			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			Window->Update();
		}
	}
}
