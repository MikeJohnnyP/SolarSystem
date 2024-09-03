#include "pch.h"
#include "Core/Logger/Logger.h"
#include "Buffer.h"
#include "Core/Platform/OpenGL/OpenGLBuffer.h"
#include "Renderer.h"
#include "RendererAPI.h"

namespace Solar
{
    Ref<VertexBuffer> VertexBuffer::create(float *vertex, uint32_t size)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::API::None: SOLAR_ASSERT(false, "Not Support API"); return nullptr;
            case RendererAPI::API::OpenGL: return std::make_shared<OpenGLVertexBuffer>(vertex, size);
        }
        SOLAR_ASSERT(false, "unknown renderer API");
        return nullptr;
    }
    Ref<IndexBuffer> IndexBuffer::create(uint32_t *indicies, uint32_t count)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::API::None: SOLAR_ASSERT(false, "Not Support API"); return nullptr;
            case RendererAPI::API::OpenGL : return std::make_shared<OpenGLIndexBuffer>(indicies, count);
        }
        SOLAR_ASSERT(false, "unknown renderer API");
        return nullptr;
    }

} 