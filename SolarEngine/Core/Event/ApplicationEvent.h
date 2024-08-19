#pragma once 

#include "Event.h"
#include <sstream>

namespace Solar
{
    class SOLAR_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) 
            : m_width(width), m_height(height) {};

        EVENT_CLASS(WindowResize);
        
        inline unsigned int GetWidth() { return m_width; }
        inline unsigned int GetHeight() { return m_height; }
        inline virtual std::string ToString() override 
        { 
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_width << ", " << m_height;
            return ss.str();
        }

    private:
        unsigned int m_width;
        unsigned int m_height;
    };

    class SOLAR_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}
        EVENT_CLASS(WindowClose);
        inline virtual std::string ToString() override 
        { 
            std::stringstream ss;
            ss << "Closed Window";
            return ss.str();
        } 
    private:
    };

    class SOLAR_API WindowFocusEvent : public Event
    {
    public:
        WindowFocusEvent() {}
        EVENT_CLASS(WindowFocus);
        inline virtual std::string ToString() override 
        { 
            std::stringstream ss;
            ss << "Focus Window";
            return ss.str();
        } 
    private:
    };
}
