
#include "crg.hpp"

void window_loop()
{
    
}

void on_window()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Comparison Race Generator", sf::Style::Close);

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
    on_window();
}