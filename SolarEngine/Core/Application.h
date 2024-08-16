#pragma once
#include "Core/Defines.h"

namespace Solar
{
    class SOLAR_API Application
    {
    public:
        bool Init();
        void Run();
        void Shutdown();
        static Application* GetInstance();
        virtual ~Application();
    protected:
        Application() = default;
        Application(const Application& other) = delete;
        Application(const Application&& other) = delete;
    private:
        static Application* s_instance;
    };
    Application* createApplication();
}