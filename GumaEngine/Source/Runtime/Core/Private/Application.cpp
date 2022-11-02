#include "Precompiled.h"
#include "Application.h"

#include "Input/AppEvent.h"
#include "Log.h"

namespace Guma
{
	Application::Application()
	{
		Window = WindowBase::Create(WindowProps());
	}

	void Application::Run()
	{
		while (bRunning && Window.get())
		{
			Window->Update();
		}
	}
}
