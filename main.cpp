/*
    Jonathan Emmanuel Jose
    Comparison Race Generator
*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main(int ac, char **av)
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
    return 0;
}
