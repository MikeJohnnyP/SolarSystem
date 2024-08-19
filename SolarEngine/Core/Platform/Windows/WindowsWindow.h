#include "Core/Window.h"

struct GLFWwindow;
namespace Solar
{
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(WindowSpec& spec);
        ~WindowsWindow() = default;
        virtual bool Init() override;
        virtual void Shutdown() override;
        virtual void SwapBuffer() override;
        virtual void PollEvent() override; 
        virtual bool IsWindowClose() override;
        virtual bool IsVsyncEnable() override;
        virtual void SetFunctionCallback(const EventFn& callback) override;
        virtual void* GetNativeWindow() override;
        virtual InputState* GetInputState() override;
    protected:

    private:
        GLFWwindow* m_GLFWwindow;

        struct WindowData
        {
            unsigned int width, height;
            const char* Title;
            bool vSync;
            InputState inputState;
            EventFn callback;
        };

        WindowData m_data;

    };
}

