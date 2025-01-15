/*
    Rendu du Pojet du jeu de Serpent
    Nom: ALIDJINOU
    Prenom: Oscar
    Filière: SMI5

*/

#include "Fruit.hpp"
#include "Position.hpp"

Fruit::Fruit() {
    apple.setSize(sf::Vector2f(32, 32));
    apple.setOutlineColor(sf::Color::Black);
    apple.setFillColor(sf::Color::Red);
    apple.setOutlineThickness(1.0f);
    apple.setPosition(0, 0);
}
void Fruit::draw(sf::RenderWindow& window) {
    window.draw(apple);
}
void Fruit::change_pos(int a, int b) {
    rows = a; clos = b;
    apple.setPosition(a, b);
    position.x = a; position.y = b;
}
Point Fruit::get_pos() {
    return position;
}
