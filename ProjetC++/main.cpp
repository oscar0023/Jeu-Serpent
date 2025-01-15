/*
    Rendu du Pojet du jeu de Serpent
    Nom: ALIDJINOU
    Prenom: Oscar
    Filière: SMI5

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Serpent.hpp"
using namespace std;
void game();

int main()
{
    game();
    return 0;
}


void game() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "Jeu Serpent");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    serpent cobra(window);
    while (window.isOpen())
    {
        cobra.move(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            cobra.cli(event);

        }

        window.clear(sf::Color::Green);
        cobra.draw(window);
        window.display();

    }
}
