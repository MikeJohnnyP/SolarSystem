#include "Solar.h"
#include "GameLayer.h"
#include "pch.h"


class SandBox : public Solar::Application
{
public:
    SandBox() : m_GameLayer(new GameLayer("Game Layer")), m_UILayer(new UILayer("UI Layer")) {}
    bool ClientInit() override 
    {
        PushLayer(m_GameLayer);
        PushOverlay(m_UILayer);
        return true;
    }

    bool ClientShutdown() override
    {
        return true;
    }
private:
    GameLayer *m_GameLayer;
    UILayer *m_UILayer;
};

Solar::Application* Solar::createApplication()
{
    return new SandBox();
}


Solar::WindowSpec Solar::createSpec()
{
    Solar::WindowSpec spec;
    spec.width = 640;
    spec.height = 480;
    spec.Title = "My window";
    spec.Vsync = true;
    return spec;
}