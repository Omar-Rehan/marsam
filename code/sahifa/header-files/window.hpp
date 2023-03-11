#pragma once

#include "utils/window-utils.hpp"

#include <type_traits>
#include <assert.h>

namespace sahifa
{
	enum class Button_State
	{
		NONE,
		UP,
		DOWN,
	};

	inline char const* button_state_string(Button_State const button_state)
	{
		switch (button_state)
		{
			SWITCH_CASE_ENUM_STRING(Button_State::NONE)
			SWITCH_CASE_ENUM_STRING(Button_State::UP)
			SWITCH_CASE_ENUM_STRING(Button_State::DOWN)

			SWITCH_CASE_DEFAULT_CRASH()
		}
	}

	/*----------------------------------------------------------------------------------------------------*/

	// TODO: Add more buttons.
	enum class Keyboard_Button
	{
		UNKNOWN,

		ALPHA_A,
		ALPHA_B,
		ALPHA_C,
		ALPHA_D,
		ALPHA_E,
		ALPHA_F,
		ALPHA_G,
		ALPHA_H,
		ALPHA_I,
		ALPHA_J,
		ALPHA_K,
		ALPHA_L,
		ALPHA_M,
		ALPHA_N,
		ALPHA_O,
		ALPHA_P,
		ALPHA_Q,
		ALPHA_R,
		ALPHA_S,
		ALPHA_T,
		ALPHA_U,
		ALPHA_V,
		ALPHA_W,
		ALPHA_X,
		ALPHA_Y,
		ALPHA_Z,

		NUM_0,
		NUM_1,
		NUM_2,
		NUM_3,
		NUM_4,
		NUM_5,
		NUM_6,
		NUM_7,
		NUM_8,
		NUM_9,

		NAV_LEFT,
		NAV_UP,
		NAV_RIGHT,
		NAV_DOWN,

		CMD_ENTER,
		CMD_BACKSPACE,
		CMD_DELETE,
		CMD_SPACE,
		CMD_TAB,
		CMD_ESCAPE,

		MDF_SHIFT,
		MDF_CONTROL,
		MDF_ALT,

		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
	};

	inline char const* keyboard_button_string(Keyboard_Button const keyboard_button)
	{
		switch (keyboard_button)
		{
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::UNKNOWN);

			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_A)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_B)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_C)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_D)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_E)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_F)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_G)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_H)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_I)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_J)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_K)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_L)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_M)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_N)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_O)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_P)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_Q)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_R)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_S)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_T)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_U)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_V)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_W)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_X)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_Y)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::ALPHA_Z)

			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NUM_0)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NUM_1)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NUM_2)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NUM_3)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NUM_4)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NUM_5)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NUM_6)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NUM_7)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NUM_8)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NUM_9)

			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NAV_LEFT)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NAV_UP)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NAV_RIGHT)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::NAV_DOWN)

			SWITCH_CASE_ENUM_STRING(Keyboard_Button::CMD_ENTER)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::CMD_BACKSPACE)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::CMD_DELETE)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::CMD_SPACE)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::CMD_TAB)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::CMD_ESCAPE)

			SWITCH_CASE_ENUM_STRING(Keyboard_Button::MDF_SHIFT)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::MDF_CONTROL)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::MDF_ALT)

			SWITCH_CASE_ENUM_STRING(Keyboard_Button::F1)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::F2)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::F3)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::F4)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::F5)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::F6)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::F7)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::F8)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::F9)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::F10)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::F11)
			SWITCH_CASE_ENUM_STRING(Keyboard_Button::F12)

			SWITCH_CASE_DEFAULT_CRASH()
		}
	}

	/*----------------------------------------------------------------------------------------------------*/

	enum class Mouse_Button
	{
		LEFT,
		MIDDLE,
		RIGHT,
	};

	inline char const* mouse_button_string(Mouse_Button const mouse_button)
	{
		switch (mouse_button)
		{
			SWITCH_CASE_ENUM_STRING(Mouse_Button::LEFT)
			SWITCH_CASE_ENUM_STRING(Mouse_Button::MIDDLE)
			SWITCH_CASE_ENUM_STRING(Mouse_Button::RIGHT)

			SWITCH_CASE_DEFAULT_CRASH()
		}
	}

	/*----------------------------------------------------------------------------------------------------*/

	enum class Event_Type
	{
		NONE,
		KEYBOARD_BUTTON,
		MOUSE_BUTTON,
		MOUSE_MOVE,
		MOUSE_WHEEL,
		WINDOW_RESIZE,
		WINDOW_CLOSE
	};

	struct Event
	{
		Event_Type type;
		union
		{
			struct
			{
				Keyboard_Button button;
				Button_State state;
			} keyboard_button;

			struct
			{
				Mouse_Button button;
				Button_State state;
			} mouse_button;

			struct
			{
				int32_t x;
				int32_t y;
			} mouse_move;

			float_t mouse_wheel;

			struct
			{
				int32_t width;
				int32_t height;
			} window_resize;
		};
	};

	/*----------------------------------------------------------------------------------------------------*/

	// Supported window implementations
	enum class Core_Implementation
	{
		WIN32_API
	};

	// Window initialization data
	struct Window_Desc
	{
		uint32_t width;
		uint32_t height;
		wchar_t const* title;
	};

	// Generic Window interface
	struct IWindow
	{
		// Allocate and initialize implementation-specific data
		auto (*initialize)    (IWindow* const window, Window_Desc const& desc) -> void;
		// Deallocate and deinitialize implementation-specific data
		auto (*deinitialize)  (IWindow* const window) -> void;

		// Get latest user event
		auto (*process_event) (IWindow* const window) -> Event;

		// Get window handle
		auto (*get_handle)    (IWindow* const window) -> void*;
		// Get window width
		auto (*get_width)     (IWindow* const window) -> uint32_t;
		// Get window height
		auto (*get_height)    (IWindow* const window) -> uint32_t;
		// Get window title
		auto (*get_title)     (IWindow* const window) -> const wchar_t*;

		// Set window title
		auto (*set_title)     (IWindow* const window, const wchar_t* title) -> void;

		// Implementation-specific data
		void* core_data;
	};

	// Setup interface
	auto window_api(IWindow* const window, Core_Implementation const core) -> void;

} // namespace sahifa
