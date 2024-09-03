#include "pch.h"
#include "Shader.h"
#include "Renderer.h"
#include "Core/Platform/OpenGL/OpenGLShader.h"

namespace Solar
{
    Ref<Shader> Shader::create(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::API::None: SOLAR_ASSERT(false, "Not Support API"); return nullptr;
            case RendererAPI::API::OpenGL: return std::make_shared<OpenGLShader>(name, vertexPath, fragmentPath);
        }
        SOLAR_ASSERT(false, "unknown renderer API");
        return nullptr;
    }
    Ref<Shader> Shader::create(const std::string& name, const std::string& filePath)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::API::None: SOLAR_ASSERT(false, "Not Support API"); return nullptr;
            case RendererAPI::API::OpenGL: return std::make_shared<OpenGLShader>(name, filePath);
        }
        SOLAR_ASSERT(false, "unknown renderer API");
        return nullptr; 
    }
    void ShaderLibrary::Add(const std::string &name, const Ref<Shader> &shader)
    {
        SOLAR_ASSERT(!Exists(name), "{0} is Exists", name);
        m_ShaderLibrary[name] = shader;
    }

    void ShaderLibrary::Add(Ref<Shader> &shader)
    {
        SOLAR_ASSERT(!Exists(shader->GetName()), "{0} is Exists", shader->GetName());
        m_ShaderLibrary[shader->GetName()] = shader; 
    }

    Ref<Shader> ShaderLibrary::Load(const std::string &name, const std::string &vertexPath, const std::string &fragmentPath)
    {
        Ref<Shader> result = Shader::create(name, vertexPath, fragmentPath);
        Add(result);
        return result;
    }

    Ref<Shader> ShaderLibrary::Load(const std::string& name, const std::string& filePath)
    {
        Ref<Shader> result = Shader::create(name,filePath);
        Add(result);
        return result;
    }

    Ref<Shader> ShaderLibrary::Get(const std::string &name)
    {
        return m_ShaderLibrary[name];
    }

    bool ShaderLibrary::Exists(const std::string &name)
    {
        return !(m_ShaderLibrary.find(name) == m_ShaderLibrary.end());
    }
} 