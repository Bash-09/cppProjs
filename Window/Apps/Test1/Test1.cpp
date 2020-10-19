#include "Test1.h"

Test1::Test1(Window* window, Renderer* rend) : Engine(window, rend) {



}

void Test1::Init() {

}

void Test1::Update(float delta) {
    auto thingo = keyboard.getEvents();
    for(auto i = thingo.begin(); i != thingo.end(); i++) {
        if(!i->press) continue;
        std::cout << keyboard.getChar(i->key) << "\n";
    }
}

void Test1::Render() {

}

void Test1::Close() {

}

Test1::~Test1() {
    
}