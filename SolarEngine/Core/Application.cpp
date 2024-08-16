#include "Application.h"

namespace Solar 
{
    Application* Application::s_instance = nullptr; 

    bool Application::Init()
    {
        if(s_instance == nullptr)
        {
           s_instance = this;
        }  
        return true;
    }

    void Application::Run()
    {
        while (true)
        {
        }
        
    }

    void Application::Shutdown()
    {
    }

    Application *Application::GetInstance()
    {
        return s_instance;
    }

    Application::~Application()
    {
    }
}
