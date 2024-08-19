#pragma once 
#include "pch.h"
#include "Layer.h"


namespace Solar
{
    class SOLAR_API LayerStack
    {
    public:
        LayerStack();
        virtual ~LayerStack();
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_LayerStack.begin(); }
        std::vector<Layer*>::iterator end() { return m_LayerStack.end(); }
    private:
        std::vector<Layer*> m_LayerStack;
        unsigned int m_LayerInsert;
    };
}