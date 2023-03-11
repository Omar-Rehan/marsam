#include "window.hpp"

#include <iostream>

int main()
{
	sahifa::IWindow* const window = sahifa::window_construct(sahifa::Core_Implementation::WIN32_API);
	window->initialize(window, {1280u, 720u, L"example-window"});
	while(true)
	{
		sahifa::Event const evt = window->process_event(window);

		if (evt.type == sahifa::Event_Type::WINDOW_CLOSE)
			break;

		switch (evt.type)
		{
			case sahifa::Event_Type::KEYBOARD_BUTTON:
				std::cout
				<< "Keyboard Button Event: "
				<< "[Button:" << keyboard_button_string(evt.keyboard_button.button) << "], "
				<< "[State:"  << button_state_string(evt.keyboard_button.state)     << "]"
				<< std::endl;
				break;
			case sahifa::Event_Type::MOUSE_BUTTON:
				std::cout
				<< "Mouse Button Event: "
				<< "[Button:" << mouse_button_string(evt.mouse_button.button) << "], "
				<< "[State:"  << button_state_string(evt.mouse_button.state)  << "]"
				<< std::endl;
				break;
			case sahifa::Event_Type::MOUSE_MOVE:
				std::cout
				<< "Mouse Move Event: "
				<< "[x: " << evt.mouse_move.x << "], "
				<< "[y: " << evt.mouse_move.y << "]"
				<< std::endl;
				break;
			case sahifa::Event_Type::MOUSE_WHEEL:
				std::cout
				<< "Mouse Wheel Event: "
				<< "[Amount: " << evt.mouse_wheel << "]"
				<< std::endl;
				break;
			case sahifa::Event_Type::WINDOW_RESIZE:
				std::cout
				<< "Window Resize Event: "
				<< "[Width: "  << evt.window_resize.width  << "], "
				<< "[Height: " << evt.window_resize.height << "]"
				<< std::endl;
				break;
			default:
				break;
		}
	}
	window->deinitialize(window);
	sahifa::window_destruct(window);

	return 0;
}