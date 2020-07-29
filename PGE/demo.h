/*
 * main.h
 *
 *  Created on: 25 Jul 2020
 *      Author: ethan
 */

#ifndef DEMO_H_
#define DEMO_H_

#include "pge.h"

class Demo : public olc::PixelGameEngine {

public:
	Demo();

	bool OnUserCreate() override;
	bool OnUserUpdate(float felapsedTime) override;

	olc::Sprite* sprDemo = nullptr;
	olc::Decal* dclDemo = nullptr;
};



#endif /* DEMO_H_ */
