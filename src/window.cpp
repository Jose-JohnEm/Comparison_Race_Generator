
#include "crg.hpp"

int on_window()
{
    sf::Window window;

    window.create(sf::VideoMode(800, 600, 32), "Comparison Race Generator");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}

void displayer(HUD hud)
{
    
}