#include "TitleScreen.h"

TitleScreen::TitleScreen(sf::RenderWindow* window) : appWindow(window), phase(0), lastWinner(NONE) {

}

void TitleScreen::setWinner(WINNER winner) {
	lastWinner = winner;
}

void TitleScreen::update(float dt) {
	phase += dt;
}

void TitleScreen::draw() {
	drawP(417.F, 100.F);
	drawO(467.F, 100.F);
	drawN(517.F, 100.F);
	drawG(567.F, 100.F);
	drawSpaceButton(362.F, 728.F);
	drawWinner();
}

void TitleScreen::drawP(float x, float y) {
	sf::RectangleShape p1;
	p1.setSize(sf::Vector2f(10.F, 100.F));
	p1.setFillColor(sf::Color::White);
	p1.setPosition(x, y);
	appWindow->draw(p1);

	sf::RectangleShape p2;
	p2.setSize(sf::Vector2f(10.F, 50.F));
	p2.setFillColor(sf::Color::White);
	p2.setPosition(x + 30.F, y);
	appWindow->draw(p2);

	sf::RectangleShape p3;
	p3.setSize(sf::Vector2f(40.F, 10.F));
	p3.setFillColor(sf::Color::White);
	p3.setPosition(x, y);
	appWindow->draw(p3);

	sf::RectangleShape p4;
	p4.setSize(sf::Vector2f(40.F, 10.F));
	p4.setFillColor(sf::Color::White);
	p4.setPosition(x, y + 45.F);
	appWindow->draw(p4);
}

void TitleScreen::drawO(float x, float y) {
	sf::RectangleShape o1;
	o1.setSize(sf::Vector2f(10.F, 100.F));
	o1.setFillColor(sf::Color::White);
	o1.setPosition(x, y);
	appWindow->draw(o1);

	sf::RectangleShape o2;
	o2.setSize(sf::Vector2f(10.F, 100.F));
	o2.setFillColor(sf::Color::White);
	o2.setPosition(x + 30.F, y);
	appWindow->draw(o2);

	sf::RectangleShape o3;
	o3.setSize(sf::Vector2f(40.F, 10.F));
	o3.setFillColor(sf::Color::White);
	o3.setPosition(x, y);
	appWindow->draw(o3);

	sf::RectangleShape o4;
	o4.setSize(sf::Vector2f(40.F, 10.F));
	o4.setFillColor(sf::Color::White);
	o4.setPosition(x, y + 90.F);
	appWindow->draw(o4);
}

void TitleScreen::drawN(float x, float y) {
	sf::RectangleShape n1;
	n1.setSize(sf::Vector2f(10.F, 100.F));
	n1.setFillColor(sf::Color::White);
	n1.setPosition(x, y);
	appWindow->draw(n1);

	sf::RectangleShape n2;
	n2.setSize(sf::Vector2f(10.F, 100.F));
	n2.setFillColor(sf::Color::White);
	n2.setPosition(x + 30.F, y);
	appWindow->draw(n2);

	sf::RectangleShape n3;
	n3.setSize(sf::Vector2f(10.F, 50.F));
	n3.setFillColor(sf::Color::White);
	n3.setPosition(x + 10.F, y);
	appWindow->draw(n3);

	sf::RectangleShape n4;
	n4.setSize(sf::Vector2f(10.F, 50.F));
	n4.setFillColor(sf::Color::White);
	n4.setPosition(x + 20.F, y + 50.F);
	appWindow->draw(n4);
}

void TitleScreen::drawG(float x, float y) {
	sf::RectangleShape g1;
	g1.setSize(sf::Vector2f(10.F, 100.F));
	g1.setFillColor(sf::Color::White);
	g1.setPosition(x, y);
	appWindow->draw(g1);

	sf::RectangleShape g2;
	g2.setSize(sf::Vector2f(20.F, 10.F));
	g2.setFillColor(sf::Color::White);
	g2.setPosition(x + 20.F, y + 45.F);
	appWindow->draw(g2);

	sf::RectangleShape g3;
	g3.setSize(sf::Vector2f(10.F, 50.F));
	g3.setFillColor(sf::Color::White);
	g3.setPosition(x + 30.F, y + 50.F);
	appWindow->draw(g3);

	sf::RectangleShape g4;
	g4.setSize(sf::Vector2f(40.F, 10.F));
	g4.setFillColor(sf::Color::White);
	g4.setPosition(x, y + 90.F);
	appWindow->draw(g4);

	sf::RectangleShape g5;
	g5.setSize(sf::Vector2f(40.F, 10.F));
	g5.setFillColor(sf::Color::White);
	g5.setPosition(x, y);
	appWindow->draw(g5);
}

void TitleScreen::drawSpaceButton(float x, float y) {
	sf::RectangleShape spaceBar;
	float opacity = sin(phase * 2) * 127 + 127;

	spaceBar.setSize(sf::Vector2f(300.F, 20.F));
	spaceBar.setFillColor(sf::Color(255, 255, 255, opacity));
	spaceBar.setPosition(x, y);
	appWindow->draw(spaceBar);
}

void TitleScreen::drawWinner() {
	if (lastWinner == LEFT_PALLET)
		drawCrown(216.F, 324.F);
	else if (lastWinner == RIGHT_PALLET)
		drawCrown(728.F, 324.F);
}

void TitleScreen::drawCrown(float x, float y) {
	sf::RectangleShape crown1;
	crown1.setSize(sf::Vector2f(20.F, 60.F));
	crown1.setFillColor(sf::Color::Yellow);
	crown1.setPosition(x, y + 60.F);
	appWindow->draw(crown1);

	sf::RectangleShape crown2;
	crown2.setSize(sf::Vector2f(20.F, 80.F));
	crown2.setFillColor(sf::Color::Yellow);
	crown2.setPosition(x + 30.F, y + 20.F);
	appWindow->draw(crown2);

	sf::RectangleShape crown3;
	crown3.setSize(sf::Vector2f(20.F, 60.F));
	crown3.setFillColor(sf::Color::Yellow);
	crown3.setPosition(x + 60.F, y + 60.F);
	appWindow->draw(crown3);

	sf::RectangleShape crown4;
	crown4.setSize(sf::Vector2f(80.F, 20.F));
	crown4.setFillColor(sf::Color::Yellow);
	crown4.setPosition(x, y + 100.F);
	appWindow->draw(crown4);
}