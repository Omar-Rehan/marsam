#include "window.hpp"
#include "core/win32/win32-window.hpp"

#define UNICODE
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <windowsx.h>
#undef DELETE

#include <assert.h>
#include <string>

namespace sahifa::core::win32
{
	namespace
	{
		constexpr wchar_t const* WINDOW_CLASS_NAME = L"sahifaWindowClass\0"; // TODO: Make class name customizable.

		struct Window_Win32
		{
			HWND    handle;
			HDC     device_context_handle;
			Event   latest_event;
		};

		/*----------------------------------------------------------------------------------------------------*/

		auto _window_procedure(HWND handle, UINT message, WPARAM wparam, LPARAM lparam) -> LRESULT
		{
			static auto map_wparam_to_keyboard_button = [](WPARAM wparam) -> Keyboard_Button
			{
				switch (wparam)
				{
					case 'A':
						return Keyboard_Button::ALPHA_A;
					case 'B':
						return Keyboard_Button::ALPHA_B;
					case 'C':
						return Keyboard_Button::ALPHA_C;
					case 'D':
						return Keyboard_Button::ALPHA_D;
					case 'E':
						return Keyboard_Button::ALPHA_E;
					case 'F':
						return Keyboard_Button::ALPHA_F;
					case 'G':
						return Keyboard_Button::ALPHA_G;
					case 'H':
						return Keyboard_Button::ALPHA_H;
					case 'I':
						return Keyboard_Button::ALPHA_I;
					case 'J':
						return Keyboard_Button::ALPHA_J;
					case 'K':
						return Keyboard_Button::ALPHA_K;
					case 'L':
						return Keyboard_Button::ALPHA_L;
					case 'M':
						return Keyboard_Button::ALPHA_M;
					case 'N':
						return Keyboard_Button::ALPHA_N;
					case 'O':
						return Keyboard_Button::ALPHA_O;
					case 'P':
						return Keyboard_Button::ALPHA_P;
					case 'Q':
						return Keyboard_Button::ALPHA_Q;
					case 'R':
						return Keyboard_Button::ALPHA_R;
					case 'S':
						return Keyboard_Button::ALPHA_S;
					case 'T':
						return Keyboard_Button::ALPHA_T;
					case 'U':
						return Keyboard_Button::ALPHA_U;
					case 'V':
						return Keyboard_Button::ALPHA_V;
					case 'W':
						return Keyboard_Button::ALPHA_W;
					case 'X':
						return Keyboard_Button::ALPHA_X;
					case 'Y':
						return Keyboard_Button::ALPHA_Y;
					case 'Z':
						return Keyboard_Button::ALPHA_Z;

					case '0':
						return Keyboard_Button::NUM_0;
					case '1':
						return Keyboard_Button::NUM_1;
					case '2':
						return Keyboard_Button::NUM_2;
					case '3':
						return Keyboard_Button::NUM_3;
					case '4':
						return Keyboard_Button::NUM_4;
					case '5':
						return Keyboard_Button::NUM_5;
					case '6':
						return Keyboard_Button::NUM_6;
					case '7':
						return Keyboard_Button::NUM_7;
					case '8':
						return Keyboard_Button::NUM_8;
					case '9':
						return Keyboard_Button::NUM_9;

					case VK_LEFT:
						return Keyboard_Button::NAV_LEFT;
					case VK_UP:
						return Keyboard_Button::NAV_UP;
					case VK_RIGHT:
						return Keyboard_Button::NAV_RIGHT;
					case VK_DOWN:
						return Keyboard_Button::NAV_DOWN;

					case VK_RETURN:
						return Keyboard_Button::CMD_ENTER;
					case VK_BACK:
						return Keyboard_Button::CMD_BACKSPACE;
					case VK_DELETE:
						return Keyboard_Button::CMD_DELETE;
					case VK_SPACE:
						return Keyboard_Button::CMD_SPACE;
					case VK_TAB:
						return Keyboard_Button::CMD_TAB;
					case VK_ESCAPE:
						return Keyboard_Button::CMD_ESCAPE;

					case VK_SHIFT:
						return Keyboard_Button::MDF_SHIFT;
					case VK_CONTROL:
						return Keyboard_Button::MDF_CONTROL;
					case VK_MENU:
						return Keyboard_Button::MDF_ALT;

					case VK_F1:
						return Keyboard_Button::F1;
					case VK_F2:
						return Keyboard_Button::F2;
					case VK_F3:
						return Keyboard_Button::F3;
					case VK_F4:
						return Keyboard_Button::F4;
					case VK_F5:
						return Keyboard_Button::F5;
					case VK_F6:
						return Keyboard_Button::F6;
					case VK_F7:
						return Keyboard_Button::F7;
					case VK_F8:
						return Keyboard_Button::F8;
					case VK_F9:
						return Keyboard_Button::F9;
					case VK_F10:
						return Keyboard_Button::F10;
					case VK_F11:
						return Keyboard_Button::F11;
					case VK_F12:
						return Keyboard_Button::F12;

					// TODO: Handle rest of keys.

					default:
						return Keyboard_Button::UNKNOWN;
				}
			};

			Window_Win32* const core_data = reinterpret_cast<Window_Win32*>(GetWindowLongPtr(handle, GWLP_USERDATA));
			if (core_data != nullptr)
			{
				memset(&core_data->latest_event, 0, sizeof(core_data->latest_event));

				switch (message)
			{
				case WM_CLOSE:
				case WM_DESTROY:
				{
					PostQuitMessage(0);
					core_data->latest_event.type = Event_Type::WINDOW_CLOSE;
					return 0;
				}
				case WM_KEYDOWN:
				{
					core_data->latest_event.type = Event_Type::KEYBOARD_BUTTON;
					core_data->latest_event.keyboard_button.button = map_wparam_to_keyboard_button(wparam);
					core_data->latest_event.keyboard_button.state = Button_State::DOWN;
					break;
				}
				case WM_KEYUP:
				{
					core_data->latest_event.type = Event_Type::KEYBOARD_BUTTON;
					core_data->latest_event.keyboard_button.button = map_wparam_to_keyboard_button(wparam);
					core_data->latest_event.keyboard_button.state = Button_State::UP;
					break;
				}
				case WM_CHAR:
				{
					// TODO: Handle WM_CHAR events.
					break;
				}
				case WM_LBUTTONDOWN:
				{
					SetCapture(core_data->handle);
					core_data->latest_event.type = Event_Type::MOUSE_BUTTON;
					core_data->latest_event.mouse_button.button = Mouse_Button::LEFT;
					core_data->latest_event.mouse_button.state = Button_State::DOWN;
					break;
				}
				case WM_LBUTTONUP:
				{
					SetCapture(core_data->handle);
					core_data->latest_event.type = Event_Type::MOUSE_BUTTON;
					core_data->latest_event.mouse_button.button = Mouse_Button::LEFT;
					core_data->latest_event.mouse_button.state = Button_State::UP;
					break;
				}
				case WM_MBUTTONDOWN:
				{
					SetCapture(core_data->handle);
					core_data->latest_event.type = Event_Type::MOUSE_BUTTON;
					core_data->latest_event.mouse_button.button = Mouse_Button::MIDDLE;
					core_data->latest_event.mouse_button.state = Button_State::DOWN;
					break;
				}
				case WM_MBUTTONUP:
				{
					SetCapture(core_data->handle);
					core_data->latest_event.type = Event_Type::MOUSE_BUTTON;
					core_data->latest_event.mouse_button.button = Mouse_Button::MIDDLE;
					core_data->latest_event.mouse_button.state = Button_State::UP;
					break;
				}
				case WM_RBUTTONDOWN:
				{
					SetCapture(core_data->handle);
					core_data->latest_event.type = Event_Type::MOUSE_BUTTON;
					core_data->latest_event.mouse_button.button = Mouse_Button::RIGHT;
					core_data->latest_event.mouse_button.state = Button_State::DOWN;
					break;
				}
				case WM_RBUTTONUP:
				{
					SetCapture(core_data->handle);
					core_data->latest_event.type = Event_Type::MOUSE_BUTTON;
					core_data->latest_event.mouse_button.button = Mouse_Button::RIGHT;
					core_data->latest_event.mouse_button.state = Button_State::UP;
					break;
				}
				case WM_MOUSEMOVE:
				{
					core_data->latest_event.type = Event_Type::MOUSE_MOVE;
					core_data->latest_event.mouse_move.x = GET_X_LPARAM(lparam);
					core_data->latest_event.mouse_move.y = GET_Y_LPARAM(lparam);
					break;
				}
				case WM_MOUSEWHEEL:
				{
					core_data->latest_event.type = Event_Type::MOUSE_WHEEL;
					core_data->latest_event.mouse_wheel = static_cast<float_t>(HIWORD(wparam));
					break;
				}
				case WM_SIZE:
				{
					core_data->latest_event.type = Event_Type::WINDOW_RESIZE;
					core_data->latest_event.window_resize.width = static_cast<int32_t>(LOWORD(lparam));
					core_data->latest_event.window_resize.height = static_cast<int32_t>(HIWORD(lparam));
					break;
				}
				default:
				{
					break;
				}
			}
			}

			return DefWindowProc(handle, message, wparam, lparam);
		}

		/*----------------------------------------------------------------------------------------------------*/

		auto window_initialize(IWindow* const window, Window_Desc const& desc) -> void
		{
			assert(window);
			assert(desc.width > 0u && desc.height > 0u && desc.title);

			// Allocate data
			Window_Win32* core_data = nullptr;
			{
				window->core_data = new Window_Win32;
				core_data = static_cast<Window_Win32*>(window->core_data); // Cast pointer for ease of use
			}

			// Initialize data
			{
				// Window description values
				auto width  = static_cast<LONG>(desc.width);
				auto height = static_cast<LONG>(desc.height);
				auto title  = static_cast<LPCWSTR>(desc.title);

				// Create window class
				WNDCLASS window_class;
				{
					ZeroMemory(&window_class, sizeof(window_class));
					window_class.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
					window_class.lpfnWndProc   = _window_procedure;
					window_class.hInstance     = NULL;
					window_class.hCursor       = LoadCursor(NULL, IDC_ARROW);
					window_class.hbrBackground = (HBRUSH)COLOR_WINDOW;
					window_class.lpszClassName = WINDOW_CLASS_NAME;
				}

				// Register window class
				RegisterClass(&window_class);

				// Create window instance & Get handle
				{
					// Create rectangle
					RECT rectangle { 0l, 0l, width, height };
					AdjustWindowRect(&rectangle, WS_OVERLAPPEDWINDOW, FALSE);

					// Create window instance
					core_data->handle = CreateWindow
					(
						window_class.lpszClassName,
						title,
						WS_OVERLAPPEDWINDOW,
						100,
						100,
						rectangle.right  - rectangle.left,
						rectangle.bottom - rectangle.top,
						NULL,
						NULL,
						NULL,
						NULL
					);
					assert(core_data->handle != INVALID_HANDLE_VALUE);
				}

				// Get device context handle
				core_data->device_context_handle = GetDC(core_data->handle);

				// Show window instance
				ShowWindow(core_data->handle, SW_SHOW);
				SetForegroundWindow(core_data->handle);
				SetFocus(core_data->handle);

				// Set user data for window instance
				SetWindowLongPtr(core_data->handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(core_data));
			}
		}

		auto window_deinitialize(IWindow* const window) -> void
		{
			assert(window && window->core_data);

			// Deinitialize data
			{
				Window_Win32* const core_data = static_cast<Window_Win32*>(window->core_data);

				// Deinitialize Win32
				{
					assert(SUCCEEDED(ReleaseDC(core_data->handle, core_data->device_context_handle)));
					assert(SUCCEEDED(DestroyWindow(core_data->handle)));
					assert(SUCCEEDED(UnregisterClass(WINDOW_CLASS_NAME, NULL)));

					core_data->handle                = NULL;
					core_data->device_context_handle = NULL;
				}
			}

			// Deallocate data
			delete window->core_data;
		}

		auto window_process_event(IWindow* const window) -> Event
		{
			assert(window && window->core_data);

			Window_Win32* const core_data = static_cast<Window_Win32*>(window->core_data);

			MSG message;
			ZeroMemory(&message, sizeof(message));
			memset(&core_data->latest_event, 0, sizeof(core_data->latest_event));

			if (PeekMessageW(&message, core_data->handle, 0u, 0u, PM_REMOVE))
			{
				TranslateMessage(&message);
				DispatchMessageW(&message);
			}

			return core_data->latest_event;
		}

		auto window_get_handle(IWindow* const window) -> void*
		{
			assert(window && window->core_data);

			Window_Win32 const* const core_data = static_cast<Window_Win32*>(window->core_data);

			return core_data->handle;
		}

		auto window_get_width(IWindow* const window) -> uint32_t
		{
			assert(window && window->core_data);

			Window_Win32 const* const core_data = static_cast<Window_Win32*>(window->core_data);

			LPRECT rectangle = nullptr;
			assert(SUCCEEDED(GetWindowRect(core_data->handle, rectangle)));
			return static_cast<uint32_t>(rectangle->bottom - rectangle->top);
		}

		auto window_get_height(IWindow* const window) -> uint32_t
		{
			assert(window && window->core_data);

			Window_Win32 const* const core_data = static_cast<Window_Win32*>(window->core_data);

			LPRECT rectangle = nullptr;
			assert(SUCCEEDED(GetWindowRect(core_data->handle, rectangle)));
			return static_cast<uint32_t>(rectangle->right - rectangle->left);
		}

		auto window_get_title(IWindow* const window) -> wchar_t const*
		{
			assert(window && window->core_data);

			Window_Win32 const* const core_data = static_cast<Window_Win32*>(window->core_data);

			LPWSTR title = nullptr;
			assert(SUCCEEDED(GetWindowText(core_data->handle, title, 25)));
			return static_cast<wchar_t const*>(title);
		}

		auto window_set_title(IWindow* const window, wchar_t const* title) -> void
		{
			assert(window && title);

			Window_Win32 const* const core_data = static_cast<Window_Win32*>(window->core_data);

			assert(SUCCEEDED(SetWindowText(core_data->handle, static_cast<LPCWSTR>(title))));
		}

	} // unnamed namespace

	/*----------------------------------------------------------------------------------------------------*/

	auto window_api(IWindow* const window) -> void
	{
		window->initialize    = window_initialize;
		window->deinitialize  = window_deinitialize;
		window->process_event = window_process_event;
		window->get_width     = window_get_width;
		window->get_height    = window_get_height;
		window->get_title     = window_get_title;
		window->get_handle    = window_get_handle;
		window->set_title     = window_set_title;
	}

} // namespace sahifa::core::win32