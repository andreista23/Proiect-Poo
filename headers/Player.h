//
// Created by nalee on 11/26/2023.
//

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
    explicit Player(std::string _name = "player1", int _score=0, int _x=1, int _y=1);
    ~Player()=default;
    friend std::ostream& operator<<(std::ostream& os,const Player& pl);
    int EatFruit(Fruit& fr);
    int EatStar(Star& st);
};


#endif //OOP_PLAYER_H
