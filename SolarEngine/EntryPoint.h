#pragma once

extern Solar::Application* Solar::createApplication();

int main()
{
    auto app = Solar::createApplication();
    if(app->Init())
    {
        app->Run();
    }
    
    app->Shutdown();
    delete app;
}