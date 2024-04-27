#include "Window.hpp"

#include <cstdint>

#include <Windowsx.h>
#include <d3d11.h>
#include <Dbt.h>


struct Window
{
public:
	Window(int p1, int p2, HINSTANCE p3, DWORD p4, void(*p5)())
		:
		f2(p3),
		f5(p1),
		f6(p2),
		f9(p4),
		f14(0),
		f15(p5)
	{
	}

	HANDLE fn_00C8BD80();

public:
	void* f1 = nullptr;
	HINSTANCE f2 = nullptr;
	HMENU f3 = nullptr;
	HWND f4 = nullptr;
	int f5 = 0;
	int f6 = 0;
	int f7 = 0;
	int f8 = 0;
	DWORD f9  = 0;
	const char* f10 = "Burnout(TM) Paradise Remastered";
	const char* f11 = "BurnoutParadiseWindowClass";
	uint32_t f12 = 0; // unknown
	HWND f13 = nullptr;
	EA::Thread::Semaphore f14;
	void(*f15)();
};


int32_t g_00F4F6FC = 1;

bool g_013600D0;
bool g_01397E63;
bool g_0139813C;
bool g_0139813D;
bool g_0139813E;
bool g_0139813F;
HWND g_0139815C;
bool g_01398241;
bool g_01398242;
bool g_01398243;
float g_01398244;
float g_01398248;
float g_013FC2A8;
struct
{
	void(*f1)(void*, HWND, UINT, WPARAM, LPARAM);
	void* f2;
} g_013FC2C0[10];
bool g_013FD395;
IDXGISwapChain* g_0148600C;


void fn_00901B40(void*, HWND, UINT, WPARAM, LPARAM);
void fn_004B0580(int32_t, WPARAM, LPARAM);


void fn_008FB500()
{
	MSG msg;
	msg.message = 0;
	while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			g_0139813F = true;
		}

		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}

	fn_008FB8F0();
	fn_008FBEE0(); // inlined
}

HWND fn_008FB590(int p1, int p2, bool p3)
{
	HMODULE moduleHandle = GetModuleHandleA(nullptr);
	
	char moduleFileName[MAX_PATH];
	GetModuleFileNameA(nullptr, moduleFileName, MAX_PATH);

	WNDCLASSA wndClass;
	wndClass.style = 0;
	wndClass.lpfnWndProc = fn_008FB9D0;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = moduleHandle;
	wndClass.hIcon = ExtractIconA(moduleHandle, moduleFileName, 0);
	wndClass.hCursor = LoadCursorA(nullptr, IDC_ARROW);
	wndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	wndClass.lpszMenuName = nullptr;
	wndClass.lpszClassName = "BurnoutParadiseWindowClass";
	if (RegisterClassA(&wndClass) == 0 && GetLastError() != ERROR_CLASS_ALREADY_EXISTS)
	{
		return nullptr;
	}

	RECT rect;
	SetRect(&rect, 0, 0, p1, p2);
	DWORD windowStyle = p3 ? (WS_POPUP | WS_CLIPCHILDREN) : (WS_CLIPCHILDREN | WS_BORDER | WS_DLGFRAME | WS_SYSMENU | WS_MINIMIZEBOX);
	AdjustWindowRect(&rect, windowStyle, FALSE);

	static Window s_012FE858(
		rect.bottom - rect.top,
		rect.right - rect.left,
		moduleHandle,
		windowStyle,
		fn_008FB500
	);

	HANDLE threadHandle = s_012FE858.fn_00C8BD80();
	s_012FE858.f14.Wait();

	AttachThreadInput(
		GetThreadId(threadHandle),
		GetCurrentThreadId(),
		TRUE
	);
	GetLastError(); // useless, maybe a part of an assert
	
	HWND hwnd = s_012FE858.f13;
	g_0139813E = true;
	
	if (hwnd == nullptr)
	{
		GetLastError(); // useless, maybe a part of an assert
		return nullptr;
	}

	HDEVNOTIFY deviceNotificationHandle;
	if (!fn_008FB8B0(hwnd, &deviceNotificationHandle)) // inlined
	{
		return nullptr;
	}

	return hwnd;
}

BOOL fn_008FB8B0(HWND p1, HDEVNOTIFY* p2)
{
	DEV_BROADCAST_DEVICEINTERFACE_A notificationFilter = {};
	notificationFilter.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE_A);
	notificationFilter.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
	
	HDEVNOTIFY handle = RegisterDeviceNotificationA(p1, &notificationFilter, DEVICE_NOTIFY_ALL_INTERFACE_CLASSES);
	*p2 = handle;
	return handle != nullptr;
}

void fn_008FB8F0()
{
	if (g_0139813E)
	{
		if (!g_0139813C || g_01398242)
		{
			ShowCursor(FALSE);
			ClipCursor(nullptr);

			while (ShowCursor(TRUE) < 0)
			{
			}
		}
		else
		{
			RECT windowRect;
			if (GetClientRect(g_0139815C, &windowRect))
			{
				POINT pt1, pt2;
				pt1.x = windowRect.left;
				pt1.y = windowRect.top;
				pt2.x = windowRect.right;
				pt2.y = windowRect.bottom;
				ClientToScreen(g_0139815C, &pt1);
				ClientToScreen(g_0139815C, &pt2);

				RECT screenRect;
				screenRect.left = pt1.x;
				screenRect.top = pt1.y;
				screenRect.right = pt2.x;
				screenRect.bottom = pt2.y;
				ClipCursor(&screenRect);

				while (ShowCursor(FALSE) >= 0)
				{
				}
			}
		}

		g_0139813E = false;
	}
}

LRESULT CALLBACK fn_008FB9D0(HWND p1, UINT p2, WPARAM p3, LPARAM p4)
{
	switch (p2)
	{
	case WM_CLOSE:
		g_0139813F = true;
		return 0;

	case WM_CREATE:
		if (!g_01398242)
		{
			g_0139813E = true;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_MOVE:
		g_0139813E = true;
		break;

	case WM_SIZE:
		if (g_00F4F6FC == 1)
		{
			if (!g_01398242)
			{
				g_0139813E = true;
			}
		}
		break;

	case WM_COMMAND:
		fn_004B0580(2, p3, p4);
		break;

	case WM_ACTIVATEAPP:
		if (g_01398242)
		{
			g_0139813C = true;
		}
		else
		{
			g_0139813E = true;
			g_0139813C = p3 == TRUE;
		}
		if (g_00F4F6FC == 0 && g_013600D0)
		{
			if (p3 == TRUE)
			{
				if (g_0148600C != nullptr)
				{
					ShowWindow(p1, SW_SHOWNA);
					g_00F4F6FC = 0;
					// TODO: set other variables
				}
			}
			else
			{
				if (g_0148600C != nullptr)
				{
					ShowWindow(p1, SW_SHOWMINNOACTIVE);
				}
			}
		}
		break;

	case WM_DISPLAYCHANGE:
		fn_004B0580(3, p3, p4);
		break;

	case WM_KEYDOWN:
		fn_004B0580(1, p3, p4);
		break;

	case WM_CHAR:
		fn_004B0580(0, p3, p4);
		break;

	case WM_SYSKEYDOWN:
		switch (p3)
		{
		case VK_RETURN:
			if (HIWORD(p4) & KF_ALTDOWN)
			{
				switch (g_00F4F6FC)
				{
				case 0:
					g_00F4F6FC = 1;
					// TODO: set other variables
					break;
				
				case 1:
				case 2:
					g_00F4F6FC = 0;
					// TODO: set other variables
					break;
				}
			}
			break;

		case VK_MENU:
		case VK_F10:
			return 0;
		}
		break;

	case WM_MOUSEWHEEL:
		{
			float delta = static_cast<float>(GET_WHEEL_DELTA_WPARAM(p3)) / static_cast<float>(WHEEL_DELTA);
			fn_008FBF30(delta); // inlined
		}
		break;

	case WM_MENUCHAR:
		return MNC_CLOSE << 16;

	case WM_MOUSEMOVE:
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
		if (g_0139813C)
		{
			float x = GET_X_LPARAM(p4);
			float y = GET_Y_LPARAM(p4);

			RECT rect;
			if (GetClientRect(p1, &rect))
			{
				x /= rect.right - rect.left;
				y /= rect.bottom - rect.top;
			}

			fn_008FBF50(x, y, GET_KEYSTATE_WPARAM(p3) == MK_LBUTTON); // inlined
		}
		break;

	case WM_DEVICECHANGE:
		if (p3 == DBT_DEVICEARRIVAL || p3 == DBT_DEVICEREMOVECOMPLETE)
		{
			if (reinterpret_cast<DEV_BROADCAST_HDR*>(p4)->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE)
			{
				g_0139813D = p3 == DBT_DEVICEARRIVAL ? true : g_0139813D;
			}
		}
		break;

	case WM_EXITSIZEMOVE:
		if (!g_01398242)
		{
			g_0139813E = true;
		}
		break;
	}

	for (int i = 0; i < 10; ++i)
	{
		auto fn = g_013FC2C0[i].f1;
		if (fn != nullptr)
		{
			fn(g_013FC2C0[i].f2, p1, p2, p3, p4);
		}
	}

	return DefWindowProcA(p1, p2, p3, p4);
}

bool fn_008FBEC0()
{
	return g_0139813C && !g_013FD395;
}

void fn_008FBEE0()
{
	if (g_01397E63)
	{
		PostQuitMessage(0);
		g_01397E63 = false;
	}
}

bool fn_008FBF00()
{
	return g_01398241;
}

float fn_008FBF10()
{
	float tmp = g_01398248;
	g_01398248 = 0.0f;
	return tmp;
}

void fn_008FBF30(float p1)
{
	g_01398248 += p1;
}

void fn_008FBF50(float p1, float p2, bool p3)
{
	g_013FC2A8 = p1;
	g_01398244 = p2;
	g_01398243 = p3;
}

void fn_008FBF70(void* p1)
{
	for (int i = 0; i < 10; ++i)
	{
		if (g_013FC2C0[i].f1 == nullptr)
		{
			g_013FC2C0[i].f1 = fn_00901B40;
			g_013FC2C0[i].f2 = p1;
			break;
		}
	}
}

void fn_008FBFA0(float& p1, float& p2, bool& p3)
{
	p1 = g_013FC2A8;
	p2 = g_01398244;
	p3 = g_01398243;
}

void fn_008FBFD0()
{
	return;
}

void fn_008FBFE0()
{
	g_0139813D = true;
}

bool fn_008FBFF0()
{
	bool tmp = g_0139813D;
	g_0139813D = false;
	return tmp;
}
