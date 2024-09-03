#include "pch.h"
#include "RenderCommand.h"
#include "Core/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Solar
{
    Ref<RendererAPI> RenderCommand::s_RendererAPI =  std::make_shared<OpenGLRendererAPI>();
}