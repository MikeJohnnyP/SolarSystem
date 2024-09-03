#pragma once

#include "Solar.h"
#include "pch.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Core/Platform/OpenGL/OpenGLShader.h"
#include "Core/OrthograhicCameraController.h"
#include "Core/Renderer/Camera/PerspectiveCamera.h"

class GameLayer : public Solar::Layer
{
public:
    GameLayer(std::string name) : Layer(name),
            m_CameraController(Solar::OrthographicCameraController(1280/720, true, true)),
            m_PerspectiveCamera(Solar::PerspectiveCamera(glm::vec3(0.0f, 0.0f, -10.0f), 1280/720)) {}

    virtual void OnAttach() override
    {

        Solar::Ref<Solar::Shader> m_Shader = m_ShaderLibarry.Load(
                                        "Shader",
                                        "../../../../../sandbox/assets/Shader/VertexShader.glsl", 
                                        "../../../../../sandbox/assets/Shader/FragmentShader.glsl"); 
    
        m_VertexArray = Solar::VertexArray::Create();

		float vertices[4 * 5] = {
            -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, // top left
            0.5f, 0.5f, 0.0f, 1.0f, 1.0f,  // top right
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, //bottom left
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f // bottom right
		}; 

        float cube[] = {
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
        };

        // Solar::Ref<Solar::VertexBuffer> m_VBO;
        // m_VBO = Solar::VertexBuffer::create(vertices, sizeof(vertices));
    
        // Solar::BufferLayout layout({{Solar::ShaderDataType::Float3, "aPos"}, {Solar::ShaderDataType::Float2, "aTextureNormal"}});
        // m_VBO->SetLayout(layout);

        // m_VertexArray->AddVertexBuffer(m_VBO);

		// uint32_t indices[6] = { 0, 1, 2, 2, 3, 1 };
        // Solar::Ref<Solar::IndexBuffer> m_EBO;
        // m_EBO = Solar::IndexBuffer::create(indices, sizeof(indices));
        // m_VertexArray->SetIndexBuffer(m_EBO);

        Solar::Ref<Solar::VertexBuffer> m_CubeVBO;
        m_CubeVBO = Solar::VertexBuffer::create(cube, sizeof(cube)); 

        Solar::BufferLayout cubeLayout({{Solar::ShaderDataType::Float3, "aPos"}, {Solar::ShaderDataType::Float2, "aTextureNormal"}});
        m_CubeVBO->SetLayout(cubeLayout);

        m_VertexArray->AddVertexBuffer(m_CubeVBO);

        m_texture1 = Solar::Texture2D::Create("../../../../../SandBox/Assets/container.jpg");

        m_texture2 = Solar::Texture2D::Create("../../../../../sandbox/assets/awesomeface.png"); 

        DYNAMIC_CAST(m_Shader, Solar::OpenGLShader)->Bind();
        DYNAMIC_CAST(m_Shader, Solar::OpenGLShader)->UniformInt("texture1", 0);
    }

    virtual void OnUpdate(Solar::TimeSteps& ts) override
    {
        m_CameraController.OnUpdate(ts);
        Solar::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});
        Solar::RenderCommand::Clear();
        Solar::Ref<Solar::Shader> getShader = m_ShaderLibarry.Get("Shader");
        Solar::Renderer::BeginScene(m_PerspectiveCamera, {{getShader}});

        m_texture1->Bind();        
        Solar::Renderer::Submit(m_VertexArray, getShader);
           
        // Solar::Renderer::Submit(m_VertexArray, m_Shader);

        // for(int i = 0; i < 20; i++)
        // {
        //     for(int y = 0; y < 20; y++)
        //     {
        //         glm::vec3 position = {i * 0.11f, y * 0.11f, 0.11f}; 
        //         glm::mat4 model = glm::translate(glm::mat4(1.0f), position) 
        //                           * glm::scale(glm::mat4(1.0f), {0.1f, 0.1f, 0.1f});
        //         m_texture2->Bind();
                               
        //         Solar::Renderer::Submit(m_VertexArray, m_Shader, model);
        //     }
        // }     
        // m_texture2->Bind();
        // Solar::Renderer::Submit(m_VertexArray, getShader);
        Solar::Renderer::EndScene();
    }

    virtual void OnEvent(Solar::Event& event) override
    {
        Solar::EventDispatcher dispatcher(event);
        dispatcher.Dispatcher<Solar::MouseButtonPressed>(SOLAR_EVENT_BIND(GameLayer::OnMousePressed));
        m_CameraController.OnEvent(event);
    }

    bool OnMousePressed(Solar::MouseButtonPressed& event)
    {
        return false;
    }
private:
    Solar::Ref<Solar::VertexArray> m_VertexArray;
    Solar::Ref<Solar::Texture2D> m_texture1;
    Solar::Ref<Solar::Texture2D> m_texture2;
    Solar::ShaderLibrary m_ShaderLibarry;
    Solar::OrthographicCameraController m_CameraController;
    Solar::PerspectiveCamera m_PerspectiveCamera;
    
};
