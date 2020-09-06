#include <iostream>
#include <thread>

#include "maths.h"
#include "platform_Linux.h"


void thread1() {

    for(int i = 0; i < 50; i++) {
        std::cout << "Thread2 looping " << i << " times." << std::endl;
    }

}

int main() {

    std::thread(thread1).detach();
    //thread.detach();

    for(int i = 0; i < 50; i++) {
        std::cout << "Thread1 looping " << i << " times." << std::endl;
    }

    return 0;
}