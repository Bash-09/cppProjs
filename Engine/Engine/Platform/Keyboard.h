#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>
#include <vector>

namespace Keyboard {

//Enum for all the important keys on the keyboard
    enum Key {
        //Alphabet
        A = SDL_KeyCode::SDLK_a,
        B = SDL_KeyCode::SDLK_b,
        C = SDL_KeyCode::SDLK_c,
        D = SDL_KeyCode::SDLK_d,
        E = SDL_KeyCode::SDLK_e,
        F = SDL_KeyCode::SDLK_f,
        G = SDL_KeyCode::SDLK_g,
        H = SDL_KeyCode::SDLK_h,
        I = SDL_KeyCode::SDLK_i,
        J = SDL_KeyCode::SDLK_j,
        K = SDL_KeyCode::SDLK_k,
        L = SDL_KeyCode::SDLK_l,
        M = SDL_KeyCode::SDLK_m,
        N = SDL_KeyCode::SDLK_n,
        O = SDL_KeyCode::SDLK_o,
        P = SDL_KeyCode::SDLK_p,
        Q = SDL_KeyCode::SDLK_q,
        R = SDL_KeyCode::SDLK_r,
        S = SDL_KeyCode::SDLK_s,
        T = SDL_KeyCode::SDLK_t,
        U = SDL_KeyCode::SDLK_u,
        V = SDL_KeyCode::SDLK_v,
        W = SDL_KeyCode::SDLK_w,
        X = SDL_KeyCode::SDLK_x,
        Y = SDL_KeyCode::SDLK_y,
        Z = SDL_KeyCode::SDLK_z,
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

    struct KeyEvent {
        bool press;
        Key key;
    };

    //Set and check keyboard state
    void press(Key key);
    void release(Key key);
    bool isPressed(Key key);
    unsigned char getChar(Key key);
    std::vector<KeyEvent> getEvents();

    //TODO
    /*
        Something about an event queue - Key presses and releases
    */

    //Clear queued events
    void nextFrame();


}