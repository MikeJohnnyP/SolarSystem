#include "Window.h"
#include "InputPlatform.h"
#include "Event/Event.h"
#include "Event/KeyboardEvent.h"
#include "Event/MouseEvent.h"
#include "Event/ApplicationEvent.h"
#include "Layer/LayerStack.h"

namespace Solar
{
    class SOLAR_API Application
    {
    public:
        bool Init();
        void Run();
        void Shutdown();
        void OnEvent(Event& event);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);
        inline InputState* GetInputState() { return m_inputState; }
        Window *GetWindow();
        static Application* GetInstance();
        virtual bool ClientInit() = 0;
        virtual bool ClientShutdown() = 0;
        virtual ~Application();
    protected:
        Application() = default;
        Application(const Application& other) = delete;
        Application(const Application&& other) = delete;
    private:
        bool OnWindowClick(MouseButtonPressed& event);
    private:
        static Application* s_instance;
        Window* m_window;
        WindowSpec m_spec;
        InputState *m_inputState; 
        LayerStack m_LayerStack;
    };
    Application* createApplication();
}