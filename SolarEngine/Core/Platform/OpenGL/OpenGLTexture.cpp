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

        glGenTextures(1, &m_TextureID); 
        glBindTexture(GL_TEXTURE_2D, m_TextureID);
        // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        m_Data = stbi_load(filePath.c_str(), &m_Width, &m_Height, &m_Channels, 0);
        if(m_Data)
        {
            uint32_t internalFormat = 0, dataFormat = 0;
            if(m_Channels == 4) 
            {
                internalFormat = GL_RGBA8;
                dataFormat = GL_RGBA; 
            } else if(m_Channels == 3) 
            {
                internalFormat = GL_RGB8;
                dataFormat = GL_RGB; 
            }
            SOLAR_ASSERT(internalFormat & dataFormat, "Unknown format texture: {0}", filePath.c_str());
            m_InternalFormat = internalFormat;
            m_DataFormat = dataFormat;
            glTexImage2D(GL_TEXTURE_2D, 0, m_InternalFormat, m_Width, m_Height, GL_FALSE, m_DataFormat, GL_UNSIGNED_BYTE, m_Data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            CORE_LOG_ERROR("Load Texture false {0}", filePath.c_str());
            return;
        }

        stbi_image_free((void *)m_Data);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void OpenGLTexture::Bind(uint32_t slot) const
    {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, m_TextureID);
    }

    void OpenGLTexture::Unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}