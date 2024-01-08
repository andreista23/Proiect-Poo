//
// Created by nalee on 11/26/2023.
//
//clasa jucatorului, cu toate functiile necesare pentru aceasta

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <iostream>
#include "Star.h"
#include "Fruit.h"
#include "Snake.h"

class Player {
    std::string name;
    int score;
    Snake playersnake;
public:
    explicit Player(std::string name_ = "player1", int score_=0, int x_=1, int y_=1);
    ~Player()=default;
    [[maybe_unused]] Player (const Player& other);
    Player& operator=(Player other);
    bool Eat(Objective& obj);
    void Grow();
    void Move(Location delta_loc);
    void Draw(Grid& grd,sf::RenderWindow& window);
    bool IsOutsideGrid(Location delta_loc);
    bool HeadInTail(Location delta_loc);
    bool IsInsideSnake(Location loc);
    int getSize();
    Location GetHeadLocation();
};


#endif //OOP_PLAYER_H
