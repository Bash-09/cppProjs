//============================================================================
// Name        : PGE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#define OLC_PGE_APPLICATION
#include <iostream>
#include "pge.h"
using namespace std;

class demo : public olc::PixelGameEngine {


public:
	bool OnUserCreate() override {

		return true;
	}
	bool OnUserUpdate(float fElapsedTime) override {

		return true;
	}

}demo;

int main() {

	demo.Construct(600, 600, 1, 1);
	demo.Start();

	return 0;
}
