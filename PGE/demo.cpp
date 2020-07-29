/*
 * demo.cpp
 *
 *  Created on: 26 Jul 2020
 *      Author: ethan
 */
#include "demo.h"

Demo::Demo() {

};

bool Demo::OnUserCreate() {

	sprDemo = new olc::Sprite("res/fern.png");
	dclDemo = new olc::Decal(sprDemo);

	return true;
}

float angle = 0;

bool Demo::OnUserUpdate(float fElapsedTime) {

	angle += 3*fElapsedTime;

	this->Clear(olc::VERY_DARK_BLUE);
	olc::vf2d mouse = { float(GetMouseX()), float(GetMouseY())};
	mouse.x -= sprDemo->width*0.25/2;
	mouse.y -= sprDemo->height*0.25/2;

	/*
	SetPixelMode(olc::Pixel::ALPHA);
	DrawSprite(mouse, sprDemo);
	SetPixelMode(olc::Pixel::NORMAL);
*/
	DrawDecal(mouse, dclDemo, {0.25f, 0.25f});
	DrawRotatedDecal(mouse, dclDemo, angle);

	return true;
}

