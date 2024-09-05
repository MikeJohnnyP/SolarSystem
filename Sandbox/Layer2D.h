#pragma once

#include "pch.h"
#include "Solar.h"

class Layer2D : public Solar::Layer
{
public:
    Layer2D(std::string name)
    :Layer(name),
        m_CameraController(Solar::OrthographicCameraController((float)1280/720, true, true))
    {
    }
    ~Layer2D() {}
    virtual void OnAttach() override 
    {
        m_Texture = Solar::Texture2D::Create("../../../../../sandbox/assets/awesomeface.png");
    }
    virtual void OnDettach() override
    {

    }
    virtual void OnUpdate(Solar::TimeSteps& ts) override
    {
        m_CameraController.OnUpdate(ts); 
        Solar::RenderCommand::SetClearColor({0.1, 0.1, 0.1, 1.0});
        Solar::RenderCommand::Clear();

        Solar::Renderer2D::BeginScene(m_CameraController.GetCamera());
        for (auto i = 0; i < 10; i++)
        {
            for(auto y = 0; y < 10; y++)
            {
                Solar::Renderer2D::DrawQuad(glm::vec2(0.11f * i, 0.11f * y), glm::vec2(0.1f), glm::vec4(0.5f));
            }
        } 

        for (auto i = 0; i < 10; i++)
        {
            for(auto y = 0; y < 10; y++)
            {
                Solar::Renderer2D::DrawQuad(glm::vec2(0.22f * i, 0.11f * y), glm::vec2(0.1f), m_Texture);
            }
        } 

        Solar::Renderer2D::EndScene();
    }
    virtual void OnEvent(Solar::Event &event) override 
    {
        m_CameraController.OnEvent(event);
    }
private:
    Solar::Ref<Solar::Texture2D> m_Texture;
    Solar::ShaderLibrary m_ShaderLibarry;
    Solar::OrthographicCameraController m_CameraController;
};