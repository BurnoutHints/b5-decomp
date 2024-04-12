#include "Window.hpp"


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


LRESULT CALLBACK fn_008FB9D0(HWND p1, UINT p2, WPARAM p3, LPARAM p4)
{

}
