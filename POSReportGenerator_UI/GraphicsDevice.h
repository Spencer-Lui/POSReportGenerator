#pragma once

#include <Windows.h>
#include <d3d11.h>

class GraphicsDevice
{
public:

    bool Initialize(HWND hwnd);

    void Shutdown();

private:

    bool CreateDevice(HWND hwnd);

    void CleanupDevice();

    void CreateRenderTarget();

    void CleanupRenderTarget();

private:

    ID3D11Device* m_device = nullptr;

    ID3D11DeviceContext* m_context = nullptr;

    IDXGISwapChain* m_swapChain = nullptr;

    ID3D11RenderTargetView* m_renderTarget = nullptr;
};

