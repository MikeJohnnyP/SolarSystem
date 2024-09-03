#pragma once 
#include "pch.h"
#include "Core/TimeSteps.h"
#include "Core/Event/Event.h"

namespace Solar
{
    class SOLAR_API Layer
    {
    public:
        virtual ~Layer();
        virtual void OnAttach() {}
        virtual void OnDettach() {}
        virtual void OnUpdate(TimeSteps& ts) {}
        virtual void OnEvent(Event &event) {}

    protected:
        Layer(const std::string name = "");

    private:
        std::string m_DebugName;
    };
}