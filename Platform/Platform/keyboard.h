#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>

namespace Keyboard {

//Enum for all the important keys on the keyboard
    enum Key {
        //Alphabet
        a = SDL_KeyCode::SDLK_a,
        b = SDL_KeyCode::SDLK_b,
        c = SDL_KeyCode::SDLK_c,
        d = SDL_KeyCode::SDLK_d,
        e = SDL_KeyCode::SDLK_e,
        f = SDL_KeyCode::SDLK_f,
        g = SDL_KeyCode::SDLK_g,
        h = SDL_KeyCode::SDLK_h,
        i = SDL_KeyCode::SDLK_i,
        j = SDL_KeyCode::SDLK_j,
        k = SDL_KeyCode::SDLK_k,
        l = SDL_KeyCode::SDLK_l,
        m = SDL_KeyCode::SDLK_m,
        n = SDL_KeyCode::SDLK_n,
        o = SDL_KeyCode::SDLK_o,
        p = SDL_KeyCode::SDLK_p,
        q = SDL_KeyCode::SDLK_q,
        r = SDL_KeyCode::SDLK_r,
        s = SDL_KeyCode::SDLK_s,
        t = SDL_KeyCode::SDLK_t,
        u = SDL_KeyCode::SDLK_u,
        v = SDL_KeyCode::SDLK_v,
        w = SDL_KeyCode::SDLK_w,
        x = SDL_KeyCode::SDLK_x,
        y = SDL_KeyCode::SDLK_y,
        z = SDL_KeyCode::SDLK_z,
        //Function Buttons
        F1 = SDL_KeyCode::SDLK_F1,
        F2 = SDL_KeyCode::SDLK_F2,
        F3 = SDL_KeyCode::SDLK_F3,
        F4 = SDL_KeyCode::SDLK_F4,
        F5 = SDL_KeyCode::SDLK_F5,
        F6 = SDL_KeyCode::SDLK_F6,
        F7 = SDL_KeyCode::SDLK_F7,
        F8 = SDL_KeyCode::SDLK_F8,
        F9 = SDL_KeyCode::SDLK_F9,
        F10 = SDL_KeyCode::SDLK_F10,
        F11 = SDL_KeyCode::SDLK_F11,
        F12 = SDL_KeyCode::SDLK_F12,
        //Weird Buttons
        Space = SDL_KeyCode::SDLK_SPACE,
        LShift = SDL_KeyCode::SDLK_LSHIFT,
        RShift = SDL_KeyCode::SDLK_RSHIFT,
        LCntrl = SDL_KeyCode::SDLK_LCTRL,
        RCntrl = SDL_KeyCode::SDLK_RCTRL,
        Enter = SDL_KeyCode::SDLK_RETURN,
        Backspace = SDL_KeyCode::SDLK_BACKSPACE,
        Tab = SDL_KeyCode::SDLK_TAB,
        Escape = SDL_KeyCode::SDLK_ESCAPE,
        Caps = SDL_KeyCode::SDLK_CAPSLOCK,
        Up = SDL_KeyCode::SDLK_UP,
        Down = SDL_KeyCode::SDLK_DOWN,
        Left = SDL_KeyCode::SDLK_LEFT,
        Right = SDL_KeyCode::SDLK_RIGHT,
        //Numpad
        NP_Numlock = SDL_KeyCode::SDLK_NUMLOCKCLEAR,
        NP_Divide = SDL_KeyCode::SDLK_KP_DIVIDE,
        NP_Times = SDL_KeyCode::SDLK_KP_MULTIPLY,
        NP_Minus = SDL_KeyCode::SDLK_KP_MINUS,
        NP_Plus = SDL_KeyCode::SDLK_KP_PLUS,
        NP_Enter = SDL_KeyCode::SDLK_KP_ENTER,
        NP_Dot = SDL_KeyCode::SDLK_KP_PERIOD,
        NP_1 = SDL_KeyCode::SDLK_KP_1,
        NP_2 = SDL_KeyCode::SDLK_KP_2,
        NP_3 = SDL_KeyCode::SDLK_KP_3,
        NP_4 = SDL_KeyCode::SDLK_KP_4,
        NP_5 = SDL_KeyCode::SDLK_KP_5,
        NP_6 = SDL_KeyCode::SDLK_KP_6,
        NP_7 = SDL_KeyCode::SDLK_KP_7,
        NP_8 = SDL_KeyCode::SDLK_KP_8,
        NP_9 = SDL_KeyCode::SDLK_KP_9,
        NP_0 = SDL_KeyCode::SDLK_KP_0,
        //Symbols
        Comma = SDL_KeyCode::SDLK_COMMA,
        Dot = SDL_KeyCode::SDLK_PERIOD,
        Slash = SDL_KeyCode::SDLK_SLASH,
        Semicolon = SDL_KeyCode::SDLK_SEMICOLON,
        Apostrophe = SDL_KeyCode::SDLK_QUOTE,
        Tilde = SDL_KeyCode::SDLK_BACKQUOTE,
        Hyphen = SDL_KeyCode::SDLK_MINUS,
        Minus = SDL_KeyCode::SDLK_MINUS,
        Plus = SDL_KeyCode::SDLK_PLUS,
        SquareBracketOpen = SDL_KeyCode::SDLK_LEFTBRACKET,
        SquareBracketClose = SDL_KeyCode::SDLK_RIGHTBRACKET,
        Backslash = SDL_KeyCode::SDLK_BACKSLASH,
    };

//Store the keyboard state
    std::unordered_map<Key, bool> keyboard;

//Set and check keyboard state
    void press(Key key) {
        keyboard.erase(key);
        keyboard.insert({key, true});
    }
    void press(SDL_Keycode key) {
        press((Key)key);
    }
    void release(Key key) {
        keyboard.erase(key);
        keyboard.insert({key, false});
    }
    void release(SDL_Keycode key) {
        release((Key)key);
    }
    bool isPressed(Key key) {
        return keyboard[key];
    }
    unsigned char getChar(Key key) {
        return static_cast<unsigned char>(key);
    }


    void nextFrame() {

    }


}