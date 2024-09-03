#include "pch.h"
#include "Renderer.h"
#include <glm/gtc/type_ptr.hpp>
#include "Core/Platform/OpenGL/OpenGLShader.h"

namespace Solar
{
    void Renderer::Init()
    {
        RenderCommand::Init();
    }

    void Renderer::Resizing(uint32_t width, uint32_t height)
    {
        RenderCommand::ViewFrame(width, height);
    }

    void Renderer::BeginScene(const Camera& camera, const std::initializer_list<Ref<Shader>>& shader)
    {
        for(auto& shader : shader)
        {
            shader->Bind();
            DYNAMIC_CAST(shader, OpenGLShader)->UniformMat4("u_ViewProjection", camera.GetViewProjectionMatrix());
            shader->Unbind();
        }

    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(const Ref<VertexArray>& vertexArray, const Ref<Shader>& shader, const glm::mat4& transform)
    {
        shader->Bind();
        DYNAMIC_CAST(shader, OpenGLShader)->UniformMat4("u_ModelMatrix", transform);
        vertexArray->Bind();
        RenderCommand::DrawArrays(vertexArray);
        
    }
}