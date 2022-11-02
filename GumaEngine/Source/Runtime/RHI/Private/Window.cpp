#include "Precompiled.h"
#include "Window.h"

#include "Core.h"

#ifdef GUMA_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Guma
{
	std::unique_ptr<WindowBase> WindowBase::Create(const WindowProps& InWindowProps)
	{
		return MakeUnique<WindowsWindow>(InWindowProps);
	}
}
