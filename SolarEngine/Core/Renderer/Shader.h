#pragma once
#include "pch.h"

namespace Solar
{
    class SOLAR_API Shader
    {
    public:
        virtual ~Shader() = default;
        
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual std::string GetName() const = 0;

        static Ref<Shader> create(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
        static Ref<Shader> create(const std::string& name, const std::string& filePath);
    };

    class SOLAR_API ShaderLibrary
    {
    public:
        void Add(const std::string& name, const Ref<Shader>& shader);
        void Add(Ref<Shader>& shader);
        Ref<Shader> Load(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
        Ref<Shader> Load(const std::string& name, const std::string& filePath);

        Ref<Shader> Get(const std::string& name);
        
        bool Exists(const std::string& name);
    private:
        std::unordered_map<std::string, Ref<Shader>> m_ShaderLibrary;
    };
}