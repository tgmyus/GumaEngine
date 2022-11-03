#pragma once

#include "Event.h"
#include "InputCodes.h"

namespace Guma
{
	class KeyEventBase : public EventBase
	{
	public:
		EVENT_CLASS_CATEGORY(InputEvent | KeyboardEvent)

		KeyCodeType GetKeyCode() const { return KeyCode; }

	protected:
		KeyEventBase(KeyCodeType InKeyCode) : KeyCode(InKeyCode) {}

		KeyCodeType KeyCode;
	};

	class KeyPressEvent : public KeyEventBase
	{
	public:
		EVENT_CLASS_TYPE(OnKeyPressed)

		KeyPressEvent(KeyCodeType InKeyCode, bool bInRepeat = false)
			: KeyEventBase(InKeyCode), bRepeat(bInRepeat) {}

		bool IsRepeat() const { return bRepeat; }

	private:
		bool bRepeat;
	};

	class KeyReleaseEvent : public KeyEventBase
	{
	public:
		EVENT_CLASS_TYPE(OnKeyReleased)

		KeyReleaseEvent(KeyCodeType InKeyCode) : KeyEventBase(InKeyCode) {}
	};

	class KeyTypeEvent : public KeyEventBase
	{
	public:
		EVENT_CLASS_TYPE(OnKeyTyped)

		KeyTypeEvent(KeyCodeType InKeyCode) : KeyEventBase(InKeyCode) {}
	};

	class MouseMoveEvent : public EventBase
	{
	public:
		EVENT_CLASS_TYPE(OnMouseMoved)
		EVENT_CLASS_CATEGORY(InputEvent | MouseEvent)

		MouseMoveEvent(float InPosX, float InPosY) : PosX(InPosX), PosY(InPosY) {}

		float GetPosX() const { return PosX; }
		float GetPosY() const { return PosY; }

	private:
		float PosX;
		float PosY;
	};

	class MouseScrollEvent : public EventBase
	{
	public:
		EVENT_CLASS_TYPE(OnMouseScrolled)
		EVENT_CLASS_CATEGORY(InputEvent | MouseEvent)

		MouseScrollEvent(float InOffsetX, float InOffsetY) : OffsetX(InOffsetX), OffsetY(InOffsetY) {}

		float GetOffsetX() const { return OffsetX; }
		float GetOffsetY() const { return OffsetY; }

	private:
		float OffsetX;
		float OffsetY;
	};

	class MouseBtnEventBase : public EventBase
	{
	public:
		EVENT_CLASS_CATEGORY(InputEvent | MouseEvent | MouseBtnEvent)

		MouseCodeType GetMouseCode() const { return MouseCode; }

	protected:
		MouseBtnEventBase(MouseCodeType InMouseCode) : MouseCode(InMouseCode) {}

		MouseCodeType MouseCode;
	};

	class MouseBtnPressEvent : public MouseBtnEventBase
	{
	public:
		EVENT_CLASS_TYPE(OnMouseBtnPressed)

		MouseBtnPressEvent(MouseCodeType InMouseCode) : MouseBtnEventBase(InMouseCode) {}
	};

	class MouseBtnReleaseEvent : public MouseBtnEventBase
	{
	public:
		EVENT_CLASS_TYPE(OnMouseBtnReleased)

		MouseBtnReleaseEvent(MouseCodeType InMouseCode) : MouseBtnEventBase(InMouseCode) {}
	};
}
