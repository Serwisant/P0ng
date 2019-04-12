#ifndef NUMBERS_H
#define NUMBERS_H

#include "Point.h"
#include <SFML\Graphics.hpp>

class Numbers {
public:
	Numbers(Point position, sf::RenderWindow* window);
	void drawNumber(int number);

private:
	void draw0();
	void draw1();
	void draw2();
	void draw3();
	void draw4();
	void draw5();
	void draw6();
	void draw7();
	void draw8();
	void draw9();

	void drawTop();
	void drawBottom();
	void drawRightTop();
	void drawRightBottom();
	void drawLeftTop();
	void drawLeftBottom();
	void drawMiddle();

	Point position;
	sf::RenderWindow* appWindow;
};

#endif
