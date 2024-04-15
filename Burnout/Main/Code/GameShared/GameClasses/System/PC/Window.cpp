#include "Window.hpp"

#include <cstdint>

#include <Windowsx.h>


int32_t g_00F4F6FC = 1;

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
bool g_013FD395;


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
    AdjustWindowRect(&rect, p3 ? (WS_POPUP | WS_CLIPCHILDREN) : (WS_CLIPCHILDREN | WS_BORDER | WS_DLGFRAME | WS_SYSMENU | WS_MINIMIZEBOX), FALSE);

    // TODO: finish this function
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
    // TODO: add other cases
    
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
        // TODO
        break;

    case WM_MOUSEWHEEL:
        {
            float delta = static_cast<float>(GET_WHEEL_DELTA_WPARAM(p3)) / static_cast<float>(WHEEL_DELTA);
            fn_008FBF30(delta); // inlined
        }
        break;

    case WM_MENUCHAR:
        // TODO
        break;

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

void fn_008FBFA0(float& p1, float& p2, bool& p3)
{
    p1 = g_013FC2A8;
    p2 = g_01398244;
    p3 = g_01398243;
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
