#pragma once

#include "Core.h"

namespace Guma
{
	class GUMA_API Application
	{
	public:
		void Run();
	};

	Application* CreateApplication();
}
