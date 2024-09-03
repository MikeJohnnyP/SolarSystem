#include "pch.h"
#include "Texture.h"
#include "Renderer.h"
#include "Core/Platform/OpenGL/OpenGLTexture.h"

namespace Solar
{
    Ref<Texture2D> Texture2D::Create(const std::string &filePath)
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
                return std::make_shared<OpenGLTexture>(filePath);
            }
        }
            return nullptr; 
    }
}