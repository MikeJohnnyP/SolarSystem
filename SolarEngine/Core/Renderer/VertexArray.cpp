#include "pch.h"
#include "VertexArray.h"
#include "Renderer.h"    
#include "Core/Logger/Logger.h"
#include "Core/Platform/OpenGL/OpenGLVertexArray.h"

namespace Solar
{
    Ref<VertexArray> VertexArray::Create()
    {
        RendererAPI::API type = Renderer::GetAPI();
        switch(type)
        {
            case RendererAPI::API::None : 
            {
                SOLAR_ASSERT(false, "unknown Renderer API");
                return nullptr;
            }
            case RendererAPI::API::OpenGL :
            {
                return std::make_shared<OpenGLVertexArray>();
            }
        }
            return nullptr;
    }
}