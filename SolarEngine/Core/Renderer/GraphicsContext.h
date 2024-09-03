#pragma once
#include "pch.h"

namespace Solar 
{
    class SOLAR_API GraphicsContext
    {
    public:
        virtual void Init() {}
        virtual void SwapBuffer() {}
    protected:
        GraphicsContext() {}
        virtual ~GraphicsContext() {}
    };
}