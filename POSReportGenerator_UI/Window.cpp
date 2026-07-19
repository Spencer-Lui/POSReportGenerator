#include "Window.h"

bool Window::Create()
{
    WNDCLASSEXW wc = {};

    wc.cbSize = sizeof(WNDCLASSEXW);

    wc.style = CS_CLASSDC;

    wc.lpfnWndProc = WndProc;

    wc.cbClsExtra = 0;

    wc.cbWndExtra = 0;

    return true;
}

void Window::Destroy()
{
}

HWND Window::GetHandle() const
{
    return m_hWnd;
}

LRESULT CALLBACK Window::WndProc(
    HWND hWnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam)
{
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
