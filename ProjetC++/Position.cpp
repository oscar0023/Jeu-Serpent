/*
    Rendu du Pojet du jeu de Serpent
    Nom: ALIDJINOU
    Prenom: Oscar
    Filière: SMI5

*/


#include "Position.hpp"

Position Position::add(Position a, Position b) {
    Position c;
    c.pos.x = a.pos.x + b.pos.x;
    c.pos.y = a.pos.y + b.pos.y;
    return c;
}

Position Position::sub(Position a, Position b) {
    Position c;
    c.pos.x = a.pos.x - b.pos.y;
    c.pos.y = a.pos.y - b.pos.y;
    return c;
}

point Position::get_pos() {
    return pos;
}

void Position::setPos(int a, int b) {
    pos.x = a; pos.y = b;
}
