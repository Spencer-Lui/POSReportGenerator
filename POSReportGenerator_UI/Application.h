#pragma once

class Application
{
public:

    int Run();

private:

    bool Initialize();

    void Update();

    void Render();

    void Shutdown();
};