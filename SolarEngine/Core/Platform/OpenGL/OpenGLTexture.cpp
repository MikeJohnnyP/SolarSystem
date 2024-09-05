#include "OpenGLTexture.h"
#include "stb_image/stb_image.h"
#include <glad/glad.h>
#include "Core/Logger/Logger.h"

namespace Solar
{
    OpenGLTexture::OpenGLTexture(const std::string &filePath) 
        : m_Width(0), m_Height(0), m_Channels(0), m_Data(nullptr) 
    {
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(filePath.c_str(), &m_Width, &m_Height, &m_Channels, 0);
		SOLAR_ASSERT(data, "Failed to load image!");
		GLenum internalFormat = 0, dataFormat = 0;
		if (m_Channels == 4)
		{
			internalFormat = GL_RGBA8;
			dataFormat = GL_RGBA;
		}
		else if (m_Channels == 3)
		{
			internalFormat = GL_RGB8;
			dataFormat = GL_RGB;
		}

		m_InternalFormat = internalFormat;
		m_DataFormat = dataFormat;

		SOLAR_ASSERT(internalFormat & dataFormat, "Format not supported!");

		glCreateTextures(GL_TEXTURE_2D, 1, &m_TextureID);
		glTextureStorage2D(m_TextureID, 1, internalFormat, m_Width, m_Height);
		glTextureParameteri(m_TextureID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_TextureID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTextureSubImage2D(m_TextureID, 0, 0, 0, m_Width, m_Height, dataFormat, GL_UNSIGNED_BYTE, data);
		stbi_image_free(data);
    }

    OpenGLTexture::OpenGLTexture(uint32_t width, uint32_t height)
        : m_Width(width), m_Height(height), m_Channels(0), m_Data(nullptr)
    {
		m_InternalFormat = GL_RGBA8;
		m_DataFormat = GL_RGBA;

		glCreateTextures(GL_TEXTURE_2D, 1, &m_TextureID);
		glTextureStorage2D(m_TextureID, 1, m_InternalFormat, m_Width, m_Height);
		glTextureParameteri(m_TextureID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_TextureID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    void OpenGLTexture::SetData(void *data, uint32_t size)
    {
        uint32_t bpp = m_DataFormat == GL_RGBA ? 4 : 3;
        SOLAR_ASSERT(size == m_Width * m_Height * bpp, "Data must be entire texture!");
		glTextureSubImage2D(m_TextureID, 0, 0, 0, m_Width, m_Height, m_DataFormat, GL_UNSIGNED_BYTE, data); 
    }

    void OpenGLTexture::Bind(uint32_t slot) const
    {
        glBindTextureUnit(slot, m_TextureID);
    }

    void OpenGLTexture::Unbind() const
    {
        glBindTextureUnit(0, m_TextureID);
    }
}