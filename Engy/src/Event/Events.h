#pragma once

#include <string>
#include "Keyboard/Keyboard.h"

namespace Event {

enum class EventType {
    None = 0,
    WindowClose, WindowResize, WindowLoseFocus, WindowGainFocus, WindowMoved,
    KeyPressed, KeyReleased,
    MousePressed, MouseReleased, MouseMoved, MouseScrolled
};

enum EventCategory {
    None = 0,
    Window,
    Keyboard,
    Mouse,
};

class Event {
    public:
        virtual EventType getEventType() const  = 0;
        virtual EventCategory getEventCategory() const = 0;
};



//Window Events start here!

class WindowCloseEvent : public Event {
    public:
        static EventType getStaticEventType() { return EventType::WindowClose; }
        EventType getEventType() const override {return EventType::WindowClose;}
        EventCategory getEventCategory() const override {return EventCategory::Window;}
};

class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(int width, int height) : width(width), height(height) {}
        static EventType getStaticEventType() { return EventType::WindowResize; }
        EventType getEventType() const override { return EventType::WindowResize; }
        EventCategory getEventCategory() const override { return EventCategory::Window; }
        
        int getWidth() const { return width; }
        int getHeight() const { return height; }
    private:
        int width;
        int height;
};

class WindowMovedEvent : public Event {
    public:
        WindowMovedEvent(int x, int y) : x(x), y(y) {}
        static EventType getStaticEventType() { return EventType::WindowMoved; }
        EventType getEventType() const override { return EventType::WindowMoved; }
        EventCategory getEventCategory() const override { return EventCategory::Window; }

        int getX() const { return x;}
        int getY() const {return y;}
    private:
        int x;
        int y;
};

class WindowLoseFocus : public Event {
    public:
        static EventType getStaticEventType() { return EventType::WindowLoseFocus; }
        EventType getEventType() const override { return EventType::WindowLoseFocus; }
        EventCategory getEventCategory() const override { return EventCategory::Window; }
};

class WindowGainFocus : public Event {
    public:
        static EventType getStaticEventType() { return EventType::WindowGainFocus; }
        EventType getEventType() const override { return EventType::WindowGainFocus; }
        EventCategory getEventCategory() const override { return EventCategory::Window; }
};


//Keyboard Events start here!
class KeyPressed : public Event {
    public:
        KeyPressed(Key key) : key(key) {}
        static EventType getStaticEventType() { return EventType::KeyPressed; }
        EventType getEventType() const override { return EventType::KeyPressed; }
        EventCategory getEventCategory() const override { return EventCategory::Keyboard; }

        Key getKey() const { return key; }
    private:
        Key key;
};


class KeyReleased : public Event {
    public:
        KeyReleased(Key key) : key(key) {}
        static EventType getStaticEventType() { return EventType::KeyReleased; }
        EventType getEventType() const override { return EventType::KeyReleased; }
        EventCategory getEventCategory() const override { return EventCategory::Keyboard; }

        Key getKey() const { return key; }
    private:
        Key key;
};

//Mouse events start here!
class MousePressed : public Event {
    public:
        MousePressed(int mButton) : mButton(mButton) {}
        static EventType getStaticEventType() { return EventType::MousePressed; }
        EventType getEventType() const override { return EventType::MousePressed; }
        EventCategory getEventCategory() const override { return EventCategory::Mouse; }

        int getMouseButton() const { return mButton; }
    private:
        int mButton;
};

class MouseReleased : public Event {
    public:
        MouseReleased(int mButton) : mButton(mButton) {}
        static EventType getStaticEventType() { return EventType::MouseReleased; }
        EventType getEventType() const override { return EventType::MouseReleased; }
        EventCategory getEventCategory() const override { return EventCategory::Mouse; }

        int getMouseButton() const { return mButton; }
    private:
        int mButton;
};

class MouseMoved : public Event {
    public:
        MouseMoved(int x, int y) : x(x), y(y) {}
        static EventType getStaticEventType() { return EventType::MouseMoved; }
        EventType getEventType() const override { return EventType::MouseMoved; }
        EventCategory getEventCategory() const override { return EventCategory::Mouse; }

        int getX() const { return x; }
        int getY() const { return y; }
    private:
        int x;
        int y;
};

class MouseScrolled : public Event {
    public:
        MouseScrolled(int ticks) : ticks(ticks) {}
        static EventType getStaticEventType() { return EventType::MouseScrolled; }
        EventType getEventType() const override { return EventType::MouseScrolled; }
        EventCategory getEventCategory() const override { return EventCategory::Mouse; }

        int getTicks() const { return ticks; }
    private:
        int ticks;
};


}
