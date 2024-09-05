#pragma once
#include "pch.h"
#include "RenderCommand.h"
#include "Camera/Camera.h"
#include "Texture.h"


namespace Solar
{
    class Renderer2D
    {
    public:
        static void Init();
        static void Shudown();
        static void Resizing(uint32_t width, uint32_t height);
        static void BeginScene(const Camera& camera);
        static void EndScene();
        static void DrawQuad(glm::vec3& position, glm::vec2& size, Ref<Texture2D>& texture);
        static void DrawQuad(glm::vec2& position, glm::vec2& size, Ref<Texture2D>& texture);
        static void DrawQuad(glm::vec3& position, glm::vec2& size, glm::vec4& color);
        static void DrawQuad(glm::vec2& position, glm::vec2& size, glm::vec4& color);

        inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
    private:
    };
}