#include "Application.h"

int Application::Run()
{
    if (!Initialize())
    {
        return -1;
    }

    //--------------------------------
    // Main Loop
    //--------------------------------

    while (true)
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
    return true;
}

void Application::Update()
{
}

void Application::Render()
{
}

void Application::Shutdown()
{
}