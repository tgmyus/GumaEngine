#pragma once

#include "Core.h"
#include "Window.h"

namespace Guma
{
	class GUMA_API Application
	{
	public:
		Application();

		void Run();

	private:
		std::unique_ptr<WindowBase> Window;
		bool bRunning = true;
	};

	Application* CreateApplication();
}
