#pragma once
#include "pch.h"
#include "RenderCommand.h"
#include "Camera/Camera.h"
#include "Shader.h"

namespace Solar
{
    enum class SOLAR_API DrawType
    {
        Buffer,
        Index
    };

    class SOLAR_API Renderer
    {
    public:
        static void Init();
        static void Resizing(uint32_t width, uint32_t height);
        static void BeginScene(const Camera& camera,const std::initializer_list<Ref<Shader>>& shader);
        static void EndScene();

        static void Submit(const Ref<VertexArray>& vertexArray, const Ref<Shader>& shader, const glm::mat4& transform = glm::mat4(1.0f));

        inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
    private:
    };
}