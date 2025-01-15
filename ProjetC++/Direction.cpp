/*
    Rendu du Pojet du jeu de Serpent
    Nom: ALIDJINOU
    Prenom: Oscar
    Filière: SMI5

*/

#include "Direction.hpp"

void Direction::setup() {
    up.x = 0; up.y = -32;
}
void Direction::setdown() {
    up.x = 0; up.y = 32;
}
void Direction::setleft() {
    up.x = -32; up.y = 0;
}
void Direction::setright() {
    up.x = 32; up.y = 0;
}
Point Direction::get_direction(int i) {
    if (i == 1) { dir = left;return left; }
    if (i == 2) { dir = right;return right; }
    if (i == 3) { dir = up;return up; }
    if (i == 4) { dir = down;return down; }
}
