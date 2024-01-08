//
// Created by Andrei on 11/26/2023.
//

#ifndef OOP_OBJECTIVE_H
#define OOP_OBJECTIVE_H
#include <iostream>
#include "GridSquare.h"
#include <random>
class Objective {
    const int score;
protected:
    GridSquare objsquare;
public:
    [[maybe_unused]] [[nodiscard]] virtual Objective* clone() const =0;
    explicit Objective(std::mt19937& rng, int score=50);
    virtual ~Objective()=default;
    GridSquare  getobjsquare();

    [[maybe_unused]] [[nodiscard]] int getscore() const;
    [[maybe_unused]] virtual void print();
    virtual void move(){}
    void respawn( std::mt19937& rng,Location loc_to_avoid[],int size);
};

#endif //OOP_OBJECTIVE_H
