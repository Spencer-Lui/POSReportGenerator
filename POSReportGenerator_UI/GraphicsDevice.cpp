#include "GraphicsDevice.h"

bool GraphicsDevice::Initialize(HWND hwnd)
{
    if (!CreateDevice(hwnd))
        return false;

    CreateRenderTarget();

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

    UINT createDeviceFlags = 0;

    //createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;

    D3D_FEATURE_LEVEL featureLevel;

    const D3D_FEATURE_LEVEL featureLevelArray[2] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_0,
    };

    HRESULT res = D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        createDeviceFlags,
        featureLevelArray,
        2,
        D3D11_SDK_VERSION,
        &sd,
        &m_swapChain,
        &m_device,
        &featureLevel,
        &m_context);

    if (res != S_OK)
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
    ID3D11Texture2D* pBackBuffer = nullptr;

    m_swapChain->GetBuffer(
        0,
        IID_PPV_ARGS(&pBackBuffer));

    m_device->CreateRenderTargetView(
        pBackBuffer,
        nullptr,
        &m_renderTargetView);

    pBackBuffer->Release();
}

void GraphicsDevice::CleanupRenderTarget()
{
    if (m_renderTargetView)
    {
        m_renderTargetView->Release();
        m_renderTargetView = nullptr;
    }
}

ID3D11Device* GraphicsDevice::GetDevice() const
{
    return m_device;
}

ID3D11DeviceContext* GraphicsDevice::GetDeviceContext() const
{
    return m_context;
}

IDXGISwapChain* GraphicsDevice::GetSwapChain() const
{
    return m_swapChain;
}

ID3D11RenderTargetView* GraphicsDevice::GetRenderTargetView() const
{
    return m_renderTargetView;
}


