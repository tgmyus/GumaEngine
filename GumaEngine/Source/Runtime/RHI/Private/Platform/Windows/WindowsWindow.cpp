#include "Precompiled.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Guma
{
	static bool bInitGLFW = false;

	WindowsWindow::WindowsWindow(const WindowProps& InWindowProps)
	{
		Init(InWindowProps);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::SetEnabledVSync(bool bInEnabledVSync)
	{
		Data.bEnabledVSync = bInEnabledVSync;

		glfwSwapInterval(Data.bEnabledVSync ? 1 : 0);
	}

	void WindowsWindow::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(Window);
	}

	void WindowsWindow::Init(const WindowProps& InWindowProps)
	{
		Data.Title = InWindowProps.Title;
		Data.Width = InWindowProps.Width;
		Data.Height = InWindowProps.Height;

		if (!bInitGLFW)
		{
			bInitGLFW = true;

			glfwInit();
		}

		Window = glfwCreateWindow(Data.Width, Data.Height, Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(Window);
		glfwSetWindowUserPointer(Window, &Data);
		SetEnabledVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(Window);
	}
}
