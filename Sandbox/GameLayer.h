#pragma once

#include "Solar.h"
#include "pch.h"

class GameLayer : public Solar::Layer
{
public:
    GameLayer(std::string name) : Layer(name) {}

    virtual void OnAttach() override
    {
        CORE_LOG_INFO("Attach game layer");
    }

    virtual void OnEvent(Solar::Event& event) override
    {
        std::cout << "Mouse offset: " << Input->Mouse->GetOffsetX() << ", " << Input->Mouse->GetOffsetY() << std::endl; 
        Solar::EventDispatcher dispatcher(event);
        dispatcher.Dispatcher<Solar::MouseButtonPressed>(std::bind(&GameLayer::OnMousePressed, this, std::placeholders::_1));
    }

    bool OnMousePressed(Solar::MouseButtonPressed& event)
    {
        CORE_LOG_INFO("Mouse pressed in game layer: {0}", event.ToString());
        return false;
    }
private:
};

class UILayer : public Solar::Layer
{
public:
    UILayer(std::string name) : Layer(name) {}

    virtual void OnAttach() override
    {
        CORE_LOG_INFO("Attach UI layer");
    }

    virtual void OnEvent(Solar::Event& event) override
    {
        Solar::EventDispatcher dispatcher(event);
        dispatcher.Dispatcher<Solar::MouseButtonPressed>(std::bind(&UILayer::OnMousePressed, this, std::placeholders::_1));
    }

    bool OnMousePressed(Solar::MouseButtonPressed& event)
    {
        CORE_LOG_INFO("Mouse pressed in UI layer: {0}", event.ToString());
        return false;
    }
private:
};