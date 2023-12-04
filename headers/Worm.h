//
// Created by Andrei on 11/27/2023.
//

#ifndef OOP_WORM_H
#define OOP_WORM_H
#include <iostream>
#include "Objective.h"

class Worm : public Objective{
    int speedx;
    int speedy;
public:
    explicit Worm(int speedx_,int speedy_,int x_=1,int y_=1,int score_=25);
    Worm(const Worm& other)= default;
    ~Worm() override =default;
    [[nodiscard]] Objective* clone() const override{
        return new Worm(*this);
    }
    void move() override;
    void print() override;
};


#endif //OOP_WORM_H
