#include <SFML/Graphics.hpp>

#include <iostream>
#include <iomanip>
#include "API/Gravity.hpp"

#define TIME_FACTOR 200000000

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Garavity, damn it!");

	sf::View view = window.getDefaultView();
	view.zoom(2);
	window.setView(view);


	World world;

	Object Earth(Vector(500,500), Vector(0, 0.0001), 7000000);
	Object Moon(Vector(700,700), Vector(0.001,0), 300000);
	Object Sun(Vector(300,300), Vector(-0.001,0), 300000);

	world.addObject(Earth);
	world.addObject(Moon);
	world.addObject(Sun);

	sf::CircleShape gSun(15.f);
	gSun.setPosition(Sun.getPosition().x, Sun.getPosition().y);
	gSun.setFillColor(sf::Color::Yellow);

	sf::CircleShape gEarth(20.f);
	gEarth.setPosition(Earth.getPosition().x, Earth.getPosition().y);
	gEarth.setFillColor(sf::Color::Blue);

	sf::CircleShape gMoon(15.f);
	gMoon.setPosition(Moon.getPosition().x, Moon.getPosition().y);
	gMoon.setFillColor(sf::Color::White);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		sf::Clock clock;
		world.step(clock.getElapsedTime().asSeconds() * TIME_FACTOR);

		gSun.setPosition(Sun.getPosition().x, Sun.getPosition().y);
		gMoon.setPosition(Moon.getPosition().x, Moon.getPosition().y);
		gEarth.setPosition(Earth.getPosition().x, Earth.getPosition().y);

		window.draw(gSun);
		window.draw(gMoon);
		window.draw(gEarth);

		window.display();




		double k = clock.restart().asSeconds() * 1000;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			view.zoom(1 + k / 500);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			view.zoom(1 - k / 500);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			view.move(-k, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			view.move(k, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			view.move(0, -k);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			view.move(0, k);
		}

		window.setView(view);
	}

	return 0;
}
