#include "AnimalPool.h"
#include "Istota.h"
#include <iostream>
#include <SFML/Graphics.hpp>

extern sf::RenderWindow window;

std::vector<std::unique_ptr<Byt>> AnimalPool::pool;

std::vector<Byt*> AnimalPool::bytyWZasiegu(Koordynaty k1, Koordynaty k2)
{

    std::vector<Byt*> pasujace;
    for (auto&& a : pool)
    {
        if ((*a).koordynaty.x > k1.x && (*a).koordynaty.y > k1.y && (*a).koordynaty.x < k2.x && (*a).koordynaty.y < k2.y)
            pasujace.push_back(a.get());
    }
    return pasujace;
}

void AnimalPool::dodaj(std::unique_ptr<Byt> p)
{
    pool.push_back(std::move(p));
}

void AnimalPool::iteracja()
{
    for (int i = 0; i < pool.size(); i++)
    {
        //iteracja
        pool.at(i)->iteruj();

        //ograniczenie terenu
        if (pool.at(i)->koordynaty.x < 0)
            pool.at(i)->koordynaty.x = 0;
        if (pool.at(i)->koordynaty.y < 0)
            pool.at(i)->koordynaty.y = 0;

        if (pool.at(i)->koordynaty.x > 10)
            pool.at(i)->koordynaty.x = 10;
        if (pool.at(i)->koordynaty.y > 10)
            pool.at(i)->koordynaty.y = 10;
    }

    //sprawdzenie
    for (int i = 0; i < pool.size(); i++)
    {
        std::cout << i << ": ";
        if (dynamic_cast<Istota*>(pool.at(i).get())) // 1 znaczy zyje, 0 znaczy umarlo
        {
            sf::CircleShape c(0.3f);
            c.setPosition(sf::Vector2f{pool.at(i).get()->koordynaty.x, pool.at(i).get()->koordynaty.y});
            if(dynamic_cast<Istota*>(pool.at(i).get())->getCzyZyje())
                c.setFillColor(sf::Color::Blue);
            else
                c.setFillColor(sf::Color::Red);
            window.draw(c);
            std::cout << dynamic_cast<Istota*>(pool.at(i).get())->getCzyZyje() << std::endl;
        }
        else
        {
            sf::CircleShape c(0.1f);
            c.setPosition(sf::Vector2f{pool.at(i).get()->koordynaty.x, pool.at(i).get()->koordynaty.y});
            c.setFillColor(sf::Color::Green);

            window.draw(c);
            std::cout << "wirus" << std::endl;
        }
    }
}
