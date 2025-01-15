/*
	Rendu du Pojet du jeu de Serpent
	Nom: ALIDJINOU
	Prenom: Oscar
	Fili�re: SMI5

*/

#include<iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Position.hpp"
#include "Direction.hpp"
#include "Fruit.hpp"
#ifndef  __SERPENT_H__
#define __SERPENT_H__
using namespace std;

void game();

class serpent {
private:
	sf::Clock mClock;
	int mTimeToUpdate;
	float mCurrentTime;
	std::vector<sf::RectangleShape> mSnakes;
	std::vector<sf::RectangleShape> borders;
	std::vector<sf::RectangleShape> border;
	Position bord[22];
	int k = 0;
	bool mLeft, mRight, mUp, mDown;
	Position position;
	Direction vitesse;
	int longeur = 0;
	Position Body[200]; // Ou bien in tableau c�est le corps de votre serpent
	Fruit fruit;
private:
	void changer_fruit_pos(sf::RenderWindow& window); //voir si un changement de position de fruit  a eu lieu
	void move_body(); //bouger le serpent
	void is_injured_itself(sf::RenderWindow& window); // v�rifier si le serpent s�est suicider
	void is_colliding_wall(sf::RenderWindow& window); // Pas n�cessaire dans notre code (le serpent peut p�n�trer
	// les murs) donc vous y �crite le code au cas o� vous avez
	//des obstacles
public:
	void borders1();
	void border2();
	serpent(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	string self_collision;
	string wall_collision;
	void AddCase();
	void move(sf::RenderWindow& window);
	void cli(sf::Event& event);	//pour les inputs du clavier

};
#endif
