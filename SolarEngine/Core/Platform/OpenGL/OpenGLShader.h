#pragma once

#include "Core/Renderer/Shader.h"
#include <glm/glm.hpp>

namespace Solar
{
    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(const std::string name, const std::string& vertexPath, const std::string& fragmentPath);
        OpenGLShader(const std::string& name, const std::string& filePath);
        virtual ~OpenGLShader();

        virtual void Bind() const override;
        virtual void Unbind() const override;
        virtual std::string GetName() const override;

        void UniformMat4(const std::string& uniformName, const glm::mat4& value); 
        void UniformVec3(const std::string& uniformName, const glm::vec3& value);
        void UniformFloat(const std::string& uniformName, const float value);
        void UniformInt(const std::string& uniformName, const int value);
    private:
        std::string ReadFile(const std::string& filePath);
        std::unordered_map<uint32_t, std::string> Pairser(std::string& file);
        bool Compile(std::unordered_map<uint32_t, std::string> Pairser);
    private:
        uint32_t m_ProgramID;
        std::string m_Name;
    };
}