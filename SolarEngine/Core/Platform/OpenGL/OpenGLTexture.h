#pragma once 

#include "Core/Renderer/Texture.h"

namespace Solar
{
    class OpenGLTexture : public Texture2D
    {
    public:
        OpenGLTexture(const std::string& filePath);
        virtual void Bind(uint32_t slot = 0) const override;
        virtual void Unbind() const override;
        virtual int32_t GetWidth() override { return m_Width; }
        virtual int32_t GetHeight() override { return m_Height; }
        virtual int32_t GetChannels() override { return m_Channels; }
    private:
        uint32_t m_TextureID;
        int32_t m_Width, m_Height, m_Channels;
        unsigned char* m_Data;
        uint32_t m_InternalFormat, m_DataFormat;
    };
}