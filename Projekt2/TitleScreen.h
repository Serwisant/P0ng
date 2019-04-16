#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <SFML\Graphics.hpp>

class TitleScreen {
public:
	enum WINNER {LEFT_PALLET, RIGHT_PALLET, NONE};

	explicit TitleScreen(sf::RenderWindow* window);

	void setWinner(WINNER winner);
	void update(float dt);
	void draw();

private:
	void drawP(float x, float y);
	void drawO(float x, float y);
	void drawN(float x, float y);
	void drawG(float x, float y);
	void drawSpaceButton(float x, float y);
	void drawCrown(float x, float y);
	void drawWinner();

	sf::RenderWindow* appWindow;
	float phase;
	WINNER lastWinner;
};

#endif