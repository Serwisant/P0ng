#include <SFML/Graphics.hpp>
#include "Engine.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "P0ng");
	sf::Clock timer;

	Engine* engine = new Engine(&window);
	sf::Keyboard::Key exitButton = sf::Keyboard::Escape;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(exitButton))
				window.close();
		}

		float deltaTime = timer.restart().asSeconds();
		engine->updateLoop(deltaTime);

		window.clear();
		engine->draw();
		window.display();
	}

	delete engine;

	return 0;
}