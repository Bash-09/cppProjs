#include "Keyboard.h"

namespace Keyboard {

    //Store key events from since the last frame
    std::vector<KeyEvent> keyEvents;

    //Store the keyboard state
    std::unordered_map<Key, bool> keyboard;

    //Set and check keyboard state
    void press(Key key) {
        keyboard.erase(key);
        keyboard.insert({key, true});
        keyEvents.push_back({true, key});
    }
    void release(Key key) {
        keyboard.erase(key);
        keyboard.insert({key, false});
        keyEvents.push_back({false, key});
    }
    bool isPressed(Key key) {
        return keyboard[key];
    }

    //Clear queued events
    void nextFrame() {
        keyEvents.clear();
    }

    std::vector<KeyEvent> getEvents() {
        return keyEvents;
    }

    unsigned char getChar(Key key) {
        switch(key) {
            case Key::NP_0:
                return '0';
            case Key::NP_1:
                return '1';
            case Key::NP_2:
                return '2';
            case Key::NP_3:
                return '3';
            case Key::NP_4:
                return '4';
            case Key::NP_5:
                return '5';
            case Key::NP_6:
                return '6';
            case Key::NP_7:
                return '7';
            case Key::NP_8:
                return '8';
            case Key::NP_9:
                return '9';
            case Key::NP_Divide:
                return '/';
            case Key::NP_Times:
                return '*';
            case Key::NP_Minus:
                return '-';
            case Key::NP_Plus:
                return '+';
            case Key::NP_Dot:
                return '.';
            case Key::LShift:
                return '\0';
            case Key::RShift:
                return '\0';
            case Key::LCntrl:
                return '\0';
            case Key::RCntrl:
                return '\0';
            case Key::Enter:
                return '\n';
            case Key::Backspace:
                return '\b';
            case Key::Escape:
                return '\0';
            case Key::Caps:
                return '\0';
            case Key::Up:
                return '\0';
            case Key::Down:
                return '\0';
            case Key::Left:
                return '\0';
            case Key::Right:
                return '\0';
            default:
                return static_cast<unsigned char>(key);
        }

    }

}