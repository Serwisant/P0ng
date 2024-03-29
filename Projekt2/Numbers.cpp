#include "numbers.h"

Numbers::Numbers(Point position, sf::RenderWindow* window) : position(position), appWindow(window) {
	
}

void Numbers::drawNumber(int number) {
	switch (number)	{
	case 0:
		draw0();
		break;
	case 1:
		draw1();
		break;
	case 2:
		draw2();
		break;
	case 3:
		draw3();
		break;
	case 4:
		draw4();
		break;
	case 5:
		draw5();
		break;
	case 6:
		draw6();
		break;
	case 7:
		draw7();
		break;
	case 8:
		draw8();
		break;
	case 9:
		draw9();
		break;
	default:
		break;
	}
}

void Numbers::draw0() {
	drawTop();
	drawRightTop();
	drawRightBottom();
	drawBottom();
	drawLeftBottom();
	drawLeftTop();
}

void Numbers::draw1() {
	drawRightTop();
	drawRightBottom();
}

void Numbers::draw2() {
	drawTop();
	drawRightTop();
	drawMiddle();
	drawLeftBottom();
	drawBottom();
}

void Numbers::draw3() {
	drawTop();
	drawRightTop();
	drawMiddle();
	drawRightBottom();
	drawBottom();
}

void Numbers::draw4() {
	drawLeftTop();
	drawRightTop();
	drawMiddle();
	drawRightBottom();
}

void Numbers::draw5() {
	drawTop();
	drawLeftTop();
	drawMiddle();
	drawRightBottom();
	drawBottom();
}

void Numbers::draw6() {
	drawTop();
	drawLeftTop();
	drawMiddle();
	drawLeftBottom();
	drawBottom();
	drawRightBottom();
}

void Numbers::draw7() {
	drawTop();
	drawRightTop();
	drawRightBottom();
}

void Numbers::draw8() {
	drawTop();
	drawRightTop();
	drawRightBottom();
	drawBottom();
	drawLeftBottom();
	drawLeftTop();
	drawMiddle();
}

void Numbers::draw9() {
	drawTop();
	drawRightTop();
	drawRightBottom();
	drawBottom();
	drawLeftTop();
	drawMiddle();
}

void Numbers::drawTop() {
	sf::RectangleShape top(sf::Vector2f(50.F, 10.F));
	top.setPosition(position.x, position.y);

	appWindow->draw(top);
}

void Numbers::drawBottom() {
	sf::RectangleShape bottom(sf::Vector2f(50.F, 10.F));
	bottom.setPosition(position.x, position.y + 90.F);

	appWindow->draw(bottom);
}

void Numbers::drawRightTop() {
	sf::RectangleShape rightTop(sf::Vector2f(10.F, 50.F));
	rightTop.setPosition(position.x + 40.F, position.y);

	appWindow->draw(rightTop);
}

void Numbers::drawRightBottom() {
	sf::RectangleShape rightBottom(sf::Vector2f(10.F, 50.F));
	rightBottom.setPosition(position.x + 40.F, position.y + 50.F);

	appWindow->draw(rightBottom);
}

void Numbers::drawLeftTop() {
	sf::RectangleShape leftTop(sf::Vector2f(10.F, 50.F));
	leftTop.setPosition(position.x, position.y);

	appWindow->draw(leftTop);
}

void Numbers::drawLeftBottom() {
	sf::RectangleShape leftBottom(sf::Vector2f(10.F, 50.F));
	leftBottom.setPosition(position.x, position.y + 50.F);

	appWindow->draw(leftBottom);
}

void Numbers::drawMiddle() {
	sf::RectangleShape middle(sf::Vector2f(50.F, 10.F));
	middle.setPosition(position.x, position.y + 40.F);

	appWindow->draw(middle);
}