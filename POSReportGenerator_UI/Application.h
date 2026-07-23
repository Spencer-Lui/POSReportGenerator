#pragma once
#include <Windows.h>
#include "MainWindow.h"
#include "GraphicsDevice.h"
#include "ImportService.h"
#include "DatabaseInitializer.h"
#include "imgui.h"


class Application
{
public:

    bool Initialize();

    int Run();

    void Render();

    GraphicsDevice& GetGraphics();

    void BeginFrame();

    void EndFrame();

    bool IsDone() const;

    void Quit();

    bool ProcessMessages();

private:

    bool InitializeWindow();

    bool InitializeImGui();

    bool RegisterWindowClass();

    void Update();

    void Shutdown();

private:

    HWND m_hWnd = nullptr;

    bool m_done = false;

    MSG m_msg{};

    MainWindow m_mainWindow;

    GraphicsDevice m_graphics;

    ImVec4 m_clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    ImportService m_importService;

    DatabaseInitializer m_databaseInitializer;

};