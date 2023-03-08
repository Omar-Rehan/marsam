#include "window.hpp"
#include "core/win32/window-win32.hpp"

#include <assert.h>

namespace sahifa
{
	auto window_construct(Core_Implementation const core) -> IWindow*
	{
		// Allocate memory
		IWindow* window = new IWindow;

		// Setup interface
		switch (core)
		{
			case Core_Implementation::WIN32_API:
			{
				core::win32::window_api(window);
				break;
			}
			default:
			{
				assert(false);
			}
		}

		return window;
	}

	auto window_destruct(IWindow* const window) -> void
	{
		// Clear interface
		{
			window->initialize    = nullptr;
			window->deinitialize  = nullptr;
			window->process_event = nullptr;
			window->get_handle    = nullptr;
			window->get_width     = nullptr;
			window->get_height    = nullptr;
			window->get_title     = nullptr;
			window->set_title     = nullptr;
		}

		// Deallocate memory
		delete window;
	}

} // namespace sahifa