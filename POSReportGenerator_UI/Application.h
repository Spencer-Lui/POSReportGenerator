#pragma once
#include <Windows.h>
#include "MainWindow.h"
#include "GraphicsDevice.h"

class Application
{
public:

    int Run();

    void Render();

private:

    bool Initialize();

    void Update();

    void Shutdown();

private:

    HWND m_hWnd = nullptr;

    bool m_done = false;

    MainWindow m_mainWindow;

private:

    GraphicsDevice m_graphics;
};