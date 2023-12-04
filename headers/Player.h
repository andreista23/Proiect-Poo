//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <iostream>
#include "Star.h"
#include "Fruit.h"
#include "Worm.h"
#include "Snake.h"

class Player {
    std::string name;
    int score;
    Snake playersnake;
    Objective* worm;
public:
    explicit Player(std::string name_ = "player1", int score_=0, int x_=1, int y_=1);
    ~Player(){
        delete worm;
    }

    [[maybe_unused]] Player (Player& other);
    Player& operator=(Player other);
    friend std::ostream& operator<<(std::ostream& os,const Player& pl);
    int EatFruit(Fruit* fr);
    int EatStar(Star* st);
    void MoveWorm();
};


#endif //OOP_PLAYER_H
