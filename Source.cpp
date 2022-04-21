#include <iostream>
#include "Bakteria.h"
#include "AnimalPool.h"
#include "Wirus.h"
#include <SFML/Graphics.hpp>

sf::RenderWindow window(sf::VideoMode(800, 600), "Symulacja zycia");

int main()
{
	srand(time(NULL));

	auto t = time(NULL);

	sf::View view(sf::Vector2f(5.f, 5.f), sf::Vector2f(11.f, 11.f));
	window.setView(view);

	//dodanie poczatkowych bytow
	for(int k = 0; k < 5; k++)
		AnimalPool::dodaj(std::make_unique<Bakteria>());
	AnimalPool::dodaj(std::make_unique<Wirus>());

	for(auto&& byt : AnimalPool::pool)
	{
		byt->koordynaty = {static_cast<float>(rand() % 10), static_cast<float>(rand() % 10)};
	}

	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


		//glowna petla
		if(t < time(NULL))
		{
        	window.clear();
			AnimalPool::iteracja();
			t = time(NULL);
		}

        window.display();
    }

	//sprawdzenie koordynatow
	std::cout << "\n\n";
	int z = 0;
	for (auto&& p : AnimalPool::pool)
	{
		std::cout << z << ": x " << p->koordynaty.x << " ; y " << p->koordynaty.y << std::endl;
		z++;
	}

	return 0;
}