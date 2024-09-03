#include "pch.h"
#include "OpenGLContext.h"
#include "Core/Logger/Logger.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Solar
{
    OpenGLContext::OpenGLContext(GLFWwindow *window) : m_WindowHandle(window)
    {
        SOLAR_ASSERT(m_WindowHandle, "m_WindowHandle is null");
    }
    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int sucess = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (!sucess) 
        {
            SOLAR_ASSERT(false, "initialize Glad failed");
            glfwTerminate();
            return;
        }
        CORE_LOG_INFO("Load Glad Sucess");
        
    }
    void OpenGLContext::SwapBuffer()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}