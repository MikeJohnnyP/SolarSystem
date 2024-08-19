#include "pch.h"
#include "Input.h"
#include "Application.h"
#include "Logger/Logger.h"
#include <GLFW/glfw3.h>

namespace Solar 
{
    Application* Application::s_instance = nullptr;

    bool Application::Init()
    {
        if(s_instance == nullptr)
        {
           s_instance = this;
        } 
        Logger::Init(); 
        CORE_LOG_INFO("Application Init Succesfully");

        m_window = createWindow();

        if(!m_window->Init()) 
        {
            return false;
        }
        ClientInit();
        m_window->SetFunctionCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

        m_inputState = m_window->GetInputState();
        return true;
    }

    void Application::Run()
    {
        while (!m_window->IsWindowClose())
        {
            m_window->SwapBuffer();
             for(Layer* layer: m_LayerStack)
             {
                 layer->OnUpdate();
             }
            m_window->PollEvent();
        }
        
    }

    void Application::Shutdown()
    {
        ClientShutdown();
    }

    void Application::OnEvent(Event &event)
    {
        EventDispatcher dispatcher(event);
        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(event);
            if(event.Handled)
                break;
        }
    }

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *overlay)
    {
        m_LayerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }

    void Application::PopLayer(Layer *layer)
    {
        m_LayerStack.PopLayer(layer);
        layer->OnDettach();
    }

    void Application::PopOverlay(Layer *overlay)
    {
        m_LayerStack.PopOverlay(overlay);
        overlay->OnDettach();
    }

    Window *Application::GetWindow()
    {
        return m_window;
    }

    Application *Application::GetInstance()
    {
        return s_instance;
    }

    Application::~Application()
    {
    }
    bool Application::OnWindowClick(MouseButtonPressed &event)
    {
        CORE_LOG_INFO("On window cliked");
        return false;
    }
}
