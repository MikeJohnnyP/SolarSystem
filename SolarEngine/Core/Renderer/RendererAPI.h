#pragma once 
#include "pch.h"
#include <glm/glm.hpp> 
#include "VertexArray.h"

namespace Solar
{
    class SOLAR_API RendererAPI
    {
    public:
        enum class API
        {
            None = 0, OpenGL = 1
        };
        virtual ~RendererAPI() {}

        virtual void Init() const = 0;
        virtual void ClearColor(const glm::vec4& color) = 0;
        virtual void Clear() = 0;
        virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) = 0;
        virtual void DrawArrays(const Ref<VertexArray>& vertexArray) = 0;
        virtual void ViewFrame(uint32_t width, uint32_t height) = 0; 
        inline static API GetAPI() { return s_Api; }

    private:
        static API s_Api;
    };
}