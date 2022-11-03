#include "Precompiled.h"
#include "Platform/Windows/WindowsWindow.h"

#include "Input/AppEvent.h"
#include "Input/InputEvent.h"

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

		glfwSetWindowCloseCallback(Window, [](GLFWwindow* InWindow)
			{
				if (auto* Data = static_cast<WindowData*>(glfwGetWindowUserPointer(InWindow)))
					Data->CallbackEvent(WindowCloseEvent());
			});

		glfwSetWindowSizeCallback(Window, [](GLFWwindow* InWindow, int InWidth, int InHeight)
			{
				if (auto* Data = static_cast<WindowData*>(glfwGetWindowUserPointer(InWindow)))
				{
					Data->Width = InWidth;
					Data->Height = InHeight;
					Data->CallbackEvent(WindowResizeEvent(InWidth, InHeight));
				}
			});

		glfwSetKeyCallback(Window, [](GLFWwindow* InWindow, int InKey, int InScanCode, int InAction, int InMods)
			{
				if (auto* Data = static_cast<WindowData*>(glfwGetWindowUserPointer(InWindow)))
				{
					switch (InAction)
					{
					case GLFW_PRESS:	Data->CallbackEvent(KeyPressEvent(InKey)); break;
					case GLFW_RELEASE:	Data->CallbackEvent(KeyReleaseEvent(InKey)); break;
					case GLFW_REPEAT:	Data->CallbackEvent(KeyPressEvent(InKey, true)); break;
					}
				}
			});

		glfwSetCursorPosCallback(Window, [](GLFWwindow* InWindow, double InPosX, double InPosY)
			{
				if (auto* Data = static_cast<WindowData*>(glfwGetWindowUserPointer(InWindow)))
					Data->CallbackEvent(MouseMoveEvent(InPosX, InPosY));
			});

		glfwSetScrollCallback(Window, [](GLFWwindow* InWindow, double InOffsetX, double InOffsetY)
			{
				if (auto* Data = static_cast<WindowData*>(glfwGetWindowUserPointer(InWindow)))
					Data->CallbackEvent(MouseScrollEvent(InOffsetX, InOffsetY));
			});

		glfwSetMouseButtonCallback(Window, [](GLFWwindow* InWindow, int InButton, int InAction, int InMods)
			{
				if (auto* Data = static_cast<WindowData*>(glfwGetWindowUserPointer(InWindow)))
				{
					switch (InAction)
					{
					case GLFW_PRESS:	Data->CallbackEvent(MouseBtnPressEvent(InButton)); break;
					case GLFW_RELEASE:	Data->CallbackEvent(MouseBtnReleaseEvent(InButton)); break;
					}
				}
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(Window);
	}
}
