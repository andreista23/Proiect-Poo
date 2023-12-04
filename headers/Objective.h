//
// Created by Andrei on 11/26/2023.
//

#ifndef OOP_OBJECTIVE_H
#define OOP_OBJECTIVE_H
#include <iostream>
#include "GridSquare.h"

class Objective {
    const int score;
    static int number;
protected:
    GridSquare objsquare;
public:
    [[maybe_unused]] [[nodiscard]] virtual Objective* clone() const =0;
    Objective(int x_,int y_, int score);
    virtual ~Objective()=default;
    GridSquare  getobjsquare();
    [[nodiscard]] int getscore() const;
    friend std::ostream &operator<<(std::ostream &os, const Objective &obj);
    [[maybe_unused]] virtual void print();
    static int getnumber();
    virtual void move(){}
};

#endif //OOP_OBJECTIVE_H
