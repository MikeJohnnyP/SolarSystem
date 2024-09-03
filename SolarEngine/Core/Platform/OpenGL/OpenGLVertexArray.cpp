#include "pch.h"
#include "OpenGLVertexArray.h"
#include <glad/glad.h>

namespace Solar
{
    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
			case Solar::ShaderDataType::Float:    return GL_FLOAT;
			case Solar::ShaderDataType::Float2:   return GL_FLOAT;
			case Solar::ShaderDataType::Float3:   return GL_FLOAT;
			case Solar::ShaderDataType::Float4:   return GL_FLOAT;
			case Solar::ShaderDataType::Mat3:     return GL_FLOAT;
			case Solar::ShaderDataType::Mat4:     return GL_FLOAT;
			case Solar::ShaderDataType::Int:      return GL_INT;
			case Solar::ShaderDataType::Int2:     return GL_INT;
			case Solar::ShaderDataType::Int3:     return GL_INT;
			case Solar::ShaderDataType::Int4:     return GL_INT;
			case Solar::ShaderDataType::Bool:     return GL_BOOL;
		}

		SOLAR_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

    OpenGLVertexArray::OpenGLVertexArray()
    {
        glGenVertexArrays(1, &m_VAO);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_VAO);
    }

    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_VAO);
    }

    void OpenGLVertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer> &vertexBuffer)
    {
        SOLAR_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex buffer has no layout");
        glBindVertexArray(m_VAO);
        vertexBuffer->Bind();

        uint32_t index = 0;
        auto& layout = vertexBuffer->GetLayout();
        for(auto& element : layout)
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(  index, 
                                    element.GetComponentCount(), 
                                    ShaderDataTypeToOpenGLBaseType(element.Type), 
                                    element.Normalized ? GL_TRUE : GL_FALSE, 
                                    layout.GetStride(), 
                                    (const void*)element.Offset);
            index++;
        }

        m_VertexBuffer.push_back(vertexBuffer);
    }

    void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
    {
        glBindVertexArray(m_VAO);
        indexBuffer->Bind();

        m_IndexBuffer = indexBuffer;
    }

} 