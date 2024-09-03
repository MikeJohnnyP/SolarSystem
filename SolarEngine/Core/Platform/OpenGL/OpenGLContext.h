#pragma once
#include "pch.h"
#include "Core/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Solar
{
    class OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow *window);
        virtual void Init() override;
        virtual void SwapBuffer() override;
    private:
        GLFWwindow* m_WindowHandle;
    };
}