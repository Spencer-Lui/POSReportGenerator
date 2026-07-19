#pragma once

#include <Windows.h>

class Window
{
public:

    bool Create();

    void Destroy();

    HWND GetHandle() const;

private:

    HWND m_hWnd = nullptr;

private:

    static LRESULT CALLBACK WndProc(
        HWND hWnd,
        UINT msg,
        WPARAM wParam,
        LPARAM lParam);
};

