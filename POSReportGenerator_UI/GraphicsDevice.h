#pragma once

#include <Windows.h>
#include <d3d11.h>

class GraphicsDevice
{
public:

    bool Initialize(HWND hwnd);

    void Shutdown();

    ID3D11Device* GetDevice() const;

    ID3D11DeviceContext* GetDeviceContext() const;

    IDXGISwapChain* GetSwapChain() const;

    ID3D11RenderTargetView* GetRenderTargetView() const;

private:

    bool CreateDevice(HWND hwnd);

    void CreateRenderTarget();

    void CleanupRenderTarget();

    void CleanupDevice();

    ID3D11Device* m_device = nullptr;

    ID3D11DeviceContext* m_context = nullptr;

    IDXGISwapChain* m_swapChain = nullptr;

    ID3D11RenderTargetView* m_renderTargetView = nullptr;
};

