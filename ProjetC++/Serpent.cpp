/*
    Rendu du Pojet du jeu de Serpent
    Nom: ALIDJINOU
    Prenom: Oscar
    Filière: SMI5

*/

#include "Serpent.hpp"
//constructeur
serpent::serpent(sf::RenderWindow& window) {
    changer_fruit_pos(window);
    mTimeToUpdate = 250; 
    mCurrentTime = 0.0f;
    srand(std::time(0));
    mLeft = mUp = mDown = false;
    mRight = true;
    vitesse.setdown();
    vitesse.setleft();
    vitesse.setright();
    vitesse.setup();
    for (int i = 0;i < 11;i++)borders1();
    for (int i = 0;i < 11;i++)border2();
    AddCase();
}
// add case
void serpent::AddCase() {
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(32, 32));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1.0f);

    if (mSnakes.empty())
    {
        rect.setFillColor(sf::Color::Blue);
        rect.setPosition(320, 256);
        longeur++;
        position.setPos(320, 256);
        Body[0] = position;
    }
    else
    {
        rect.setFillColor(sf::Color::Yellow);
        rect.setPosition(mSnakes[longeur - 1].getPosition().x - rect.getSize().x, mSnakes[longeur - 1].getPosition().y);
        position.setPos(rect.getPosition().x, rect.getPosition().y);
        Body[longeur] = position;
        longeur++;
    }

    mSnakes.push_back(rect);
}
// draw serpent et fruit
void serpent::draw(sf::RenderWindow& window) {
    fruit.draw(window);
    for (unsigned int i = 0; i < longeur; i++) window.draw(mSnakes[i]);
    for (int i = 0; i < borders.size();i++)window.draw(borders[i]);
    for (int i = 0; i < border.size();i++)window.draw(border[i]);
}
// change fruit pos
void serpent::changer_fruit_pos(sf::RenderWindow& window) {
    int randomX;
    int randomY;
    int j;
    do {
        j = 0;
        randomX = rand() % (window.getSize().x / 32);
        for (int i = 0;i < longeur;i++) {
            for (int h = 0;h < k;h++)    if (randomX * 32 == Body[i].get_pos().x || randomX * 32 == bord[h].get_pos().x ) j++;
        }
    } while (j > 0);
    do {
        j = 0;
        randomY = rand() % (window.getSize().y / 32);
        for (int i = 0;i < longeur;i++) {
            for (int h = 0;h < k;h++)    if (randomY * 32 == Body[i].get_pos().y ||randomY * 32 == bord[h].get_pos().y ) j++;
        }
    } while (j > 0);
    fruit.change_pos(randomX * 32, randomY * 32);
}


// méthode cli
void serpent::cli(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left)
        {
            mLeft = true;
            mRight = false;
            mUp = false;
            mDown = false;
        }

        if (event.key.code == sf::Keyboard::Right)
        {
            mLeft = false;
            mRight = true;
            mUp = false;
            mDown = false;
        }

        if (event.key.code == sf::Keyboard::Up)
        {
            mLeft = false;
            mRight = false;
            mUp = true;
            mDown = false;
        }

        if (event.key.code == sf::Keyboard::Down)
        {
            mLeft = false;
            mRight = false;
            mUp = false;
            mDown = true;
        }
    }
}
// move body
void serpent::move_body() {
    if (mCurrentTime < mTimeToUpdate)
    {
        mCurrentTime += mClock.restart().asMilliseconds();
    }
    else
    {
        mCurrentTime = 0.0f;
        if (longeur > 1)
        {
            for (int i = longeur - 1; i > 0; i--)
            {
                mSnakes[i].setPosition(sf::Vector2f(mSnakes[i - 1].getPosition().x, mSnakes[i - 1].getPosition().y));
            }
        }

        if (mLeft)
        {
            mSnakes[0].move(-32, 0);
        }

        if (mRight)
        {
            mSnakes[0].move(32, 0);
        }

        if (mUp)
        {
            mSnakes[0].move(0, -32);
        }

        if (mDown)
        {
            mSnakes[0].move(0, 32);
        }
    }
}
// Borders 1
void serpent::borders1() {
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(32, 32));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1.0f);

    if (borders.empty())
    {
        rect.setFillColor(sf::Color::White);
        rect.setPosition(448, 384);
        bord[k].setPos(rect.getPosition().x, rect.getPosition().y);
        k++;
    }
    else
    {
        rect.setFillColor(sf::Color::White);
        rect.setPosition(borders[borders.size() - 1].getPosition().x - rect.getSize().x, borders[borders.size() - 1].getPosition().y);
        bord[k].setPos(rect.getPosition().x, rect.getPosition().y);
        k++;
    }

    borders.push_back(rect);
}
// Borders 2
void serpent::border2() {
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(32, 32));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1.0f);

    if (border.empty())
    {
        rect.setFillColor(sf::Color::White);
        rect.setPosition(448, 192);
        bord[k].setPos(rect.getPosition().x, rect.getPosition().y);
        k++;
    }
    else
    {
        rect.setFillColor(sf::Color::White);
        rect.setPosition(border[border.size() - 1].getPosition().x - rect.getSize().x, border[border.size() - 1].getPosition().y);
        bord[k].setPos(rect.getPosition().x, rect.getPosition().y);
        k++;
    }

    border.push_back(rect);
}
void serpent::is_injured_itself(sf::RenderWindow& window) {
    for (int i = 2; i < longeur; i++)
    {
        if (Body[0].get_pos().x == Body[i].get_pos().x
            && Body[0].get_pos().y == Body[i].get_pos().y)
        {
            window.close();
        }
    }

}

void serpent::is_colliding_wall(sf::RenderWindow& window) {
    for (int i = 0;i < 22;i++) {
        if (Body[0].get_pos().x == bord[i].get_pos().x
            && Body[0].get_pos().y == bord[i].get_pos().y)
        {
            window.close();
        }
        if (Body[0].get_pos().x > window.getSize().x) mSnakes[0].setPosition(0, Body[0].get_pos().y);
        if (Body[0].get_pos().x < -31)mSnakes[0].setPosition(600, Body[0].get_pos().y);
        if (Body[0].get_pos().y > window.getSize().y) mSnakes[0].setPosition(Body[0].get_pos().x, 0);
        if (Body[0].get_pos().y < -31)mSnakes[0].setPosition(Body[0].get_pos().x, 600);
    }
}
void serpent::move(sf::RenderWindow& window) {

    move_body();
    for (int i = 0;i < longeur;i++) Body[i].setPos(mSnakes[i].getPosition().x, mSnakes[i].getPosition().y);
    is_injured_itself(window);
    is_colliding_wall(window);
    if (Body[0].get_pos().x == fruit.get_pos().x
        && Body[0].get_pos().y == fruit.get_pos().y)
    {
        AddCase();
        changer_fruit_pos(window);
    }

}
