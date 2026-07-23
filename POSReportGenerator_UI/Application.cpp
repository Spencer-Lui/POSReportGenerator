#include "Application.h"
#include "imgui.h"
#include "backends/imgui_impl_dx11.h"
#include "backends/imgui_impl_win32.h"
#include <tchar.h>


int Application::Run()
{
    if (!Initialize())
    {
        return -1;
    }

    /*ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.Fonts->AddFontFromFileTTF(
        "C:/Windows/Fonts/msjh.ttc",
        18.0f,
        nullptr,
        io.Fonts->GetGlyphRangesChineseFull());*/

    while (!m_done)
    {
        Update();

        Render();

        break;
    }

    Shutdown();

    return 0;
}



bool Application::Initialize()
{
    if (!m_databaseInitializer.Initialize())
    {
        return false;
    }

    if (!InitializeWindow())
    {
        return false;
    }

    if (!InitializeImGui())
    {
        return false;
    }

    if (!m_importService.ImportStoreSummary())
    {
        return false;
    }

    return true;
}

bool Application::InitializeWindow()
{
    if (!RegisterWindowClass())
    {
        return false;
    }

    return true;
}

bool Application::RegisterWindowClass()
{
    return true;
}

bool Application::InitializeImGui()
{
    return true;
}

void Application::Update()
{
}

void Application::Render()
{
    BeginFrame();

    m_mainWindow.Draw();

    EndFrame();
}

void Application::Shutdown()
{
}

GraphicsDevice& Application::GetGraphics()
{
    return m_graphics;
}

void Application::BeginFrame()
{
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

void Application::EndFrame()
{
    ImGui::Render();

    const float clearColorWithAlpha[4] =
    {
        m_clearColor.x * m_clearColor.w,
        m_clearColor.y * m_clearColor.w,
        m_clearColor.z * m_clearColor.w,
        m_clearColor.w
    };

    ID3D11DeviceContext* context = m_graphics.GetDeviceContext();
    ID3D11RenderTargetView* target = m_graphics.GetRenderTargetView();

    context->OMSetRenderTargets(
        1,
        &target,
        nullptr);

    context->ClearRenderTargetView(
        target,
        clearColorWithAlpha);

    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    m_graphics.GetSwapChain()->Present(1, 0);
}

bool Application::IsDone() const
{
    return m_done;
}

void Application::Quit()
{
    m_done = true;
}

bool Application::ProcessMessages()
{
    while (::PeekMessage(&m_msg, nullptr, 0U, 0U, PM_REMOVE))
    {
        ::TranslateMessage(&m_msg);
        ::DispatchMessage(&m_msg);

        if (m_msg.message == WM_QUIT)
        {
            m_done = true;
        }
    }

    return !m_done;
}