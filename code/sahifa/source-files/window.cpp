#include "window.hpp"
#include "core/win32/window-win32.hpp"

#include <assert.h>

namespace sahifa
{
	auto window_api(IWindow* const window, Core_Implementation const core) -> void
	{
		assert(window);

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
	}

} // namespace sahifa