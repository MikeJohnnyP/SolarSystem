#include "Solar.h"
#include "Layer2D.h"
#include "GameLayer.h"
#include "pch.h"


class SandBox : public Solar::Application
{
public:
    SandBox() : m_GameLayer(new GameLayer("Game Layer")),
                m_Layer2DLayer(new Layer2D("Layer2D")) {}
    bool ClientInit() override 
    {
        // PushLayer(m_GameLayer);
        PushLayer(m_Layer2DLayer);
        return true;
    }

    bool ClientShutdown() override
    {
        return true;
    }
private:
    GameLayer *m_GameLayer;
    Layer2D* m_Layer2DLayer;
};

Solar::Application* Solar::createApplication()
{
    return new SandBox();
}


Solar::WindowSpec Solar::createSpec()
{
    Solar::WindowSpec spec;
    spec.width = 1280;
    spec.height = 720;
    spec.Title = "My window";
    spec.Vsync = true;
    return spec;
}