#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>
#include <vector>

enum Key {
    //Alphabet
    A = 97,
    B = 98,
    C = 99,
    D = 100,
    E = 101,
    F = 102,
    G = 103,
    H = 104,
    I = 105,
    J = 106,
    K = 107,
    L = 108,
    M = 109,
    N = 110,
    O = 111,
    P = 112,
    Q = 113,
    R = 114,
    S = 115,
    T = 116,
    U = 117,
    V = 118,
    W = 119,
    X = 120,
    Y = 121,
    Z = 122,
    //Function Buttons
    F1 = 1073741882,
    F2 = 1073741883,
    F3 = 1073741884,
    F4 = 1073741885,
    F5 = 1073741886,
    F6 = 1073741887,
    F7 = 1073741888,
    F8 = 1073741889,
    F9 = 1073741890,
    F10 = 1073741891,
    F11 = 1073741892,
    F12 = 1073741893,
    //Weird Buttons
    Space = 32,
    LShift = 1073742049,
    RShift = 1073742053,
    LCntrl = 1073742048,
    RCntrl = 1073742052,
    Enter = 13,
    Backspace = 8,
    Tab = 9,
    Escape = 27,
    Caps = 1073741881,
    Up = 1073741906,
    Down = 1073741905,
    Left = 1073741904,
    Right = 1073741903,
    //Numpad
    NP_Numlock = 1073741907,
    NP_Divide = 1073741908,
    NP_Times = 1073741909,
    NP_Minus = 1073741910,
    NP_Plus = 1073741911,
    NP_Enter = 1073741912,
    NP_Dot = 1073741923,
    NP_1 = 1073741913,
    NP_2 = 1073741914,
    NP_3 = 1073741915,
    NP_4 = 1073741916,
    NP_5 = 1073741917,
    NP_6 = 1073741918,
    NP_7 = 1073741919,
    NP_8 = 1073741920,
    NP_9 = 1073741921,
    NP_0 = 1073741922,
    //Symbols
    Comma = 44,
    Dot = 46,
    Slash = 47,
    Semicolon = 59,
    Apostrophe = 39,
    Tilde = 96,
    Minus = 45,
    Plus = 43,
    SquareBracketOpen = 91,
    SquareBracketClose = 93,
    Backslash = 92,
};

struct KeyEvent {
    bool press;
    Key key;
};

class Keyboard {
public:
//Enum for all the important keys on the keyboard
    
    //Set and check keyboard state
    void press(Key key);
    void release(Key key);
    bool isPressed(Key key);
    unsigned char getChar(Key key);
    std::vector<KeyEvent> getEvents();

    //Clear queued events
    void nextFrame();
private:

    //Store key events from since the last frame
    std::vector<KeyEvent> keyEvents;
    //Store the keyboard state
    std::unordered_map<Key, bool> keyboard;

};

