/*
	Rendu du Pojet du jeu de Serpent
	Nom: ALIDJINOU
	Prenom: Oscar
	Filière: SMI5

*/




#include<iostream>
#include <SFML/Graphics.hpp>
#ifndef  __POSITION_H__
#define __POSITION_H__
using namespace std;


typedef struct point {
	int x, y;
}Point;

class Position {
public:
	Point pos;
private:
	Position add(Position a, Position b);
	Position sub(Position a, Position b);
public:
	point get_pos();
	void setPos(int a, int b);
};
#endif

