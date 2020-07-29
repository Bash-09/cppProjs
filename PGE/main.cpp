/*
 * main.cpp
 *
 *  Created on: 25 Jul 2020
 *      Author: ethan
 */

#define OLC_PGE_APPLICATION

#include <iostream>
#include "demo.h"


int main() {

	Demo demo;
	if(demo.Construct(600, 600, 1, 1)) {
		demo.Start();
	}

	return 0;
}


