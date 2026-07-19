#include "GraphicsDevice.h"

bool GraphicsDevice::Initialize(HWND hwnd)
{
    return true;
}

void GraphicsDevice::Shutdown()
{
}

bool GraphicsDevice::CreateDevice(HWND hwnd)
{
    //=========================
    // Swap Chain 設定
    //=========================

    DXGI_SWAP_CHAIN_DESC sd;

    ZeroMemory(&sd, sizeof(sd));

    sd.BufferCount = 2;

    sd.BufferDesc.Width = 0;

    sd.BufferDesc.Height = 0;

    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

    sd.BufferDesc.RefreshRate.Numerator = 60;

    sd.BufferDesc.RefreshRate.Denominator = 1;

    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

    sd.OutputWindow = hwnd;

    sd.SampleDesc.Count = 1;

    sd.SampleDesc.Quality = 0;

    sd.Windowed = TRUE;

    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    D3D_FEATURE_LEVEL featureLevel;

    const D3D_FEATURE_LEVEL featureLevelArray[2] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_0,
    };

    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        0,
        featureLevelArray,
        2,
        D3D11_SDK_VERSION,
        &sd,
        &m_swapChain,
        &m_device,
        &featureLevel,
        &m_context);

    if (FAILED(hr))
    {
        return false;
    }

    return true;
}

void GraphicsDevice::CleanupDevice()
{
}

void GraphicsDevice::CreateRenderTarget()
{
}

void GraphicsDevice::CleanupRenderTarget()
{
}

