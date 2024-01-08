//
// Created by Andrei on 11/27/2023.
//

#ifndef OOP_WORM_H
#define OOP_WORM_H
#include <iostream>
#include "Objective.h"

class Worm : public Objective{
    Location speed;
public:
    explicit Worm(int speedx_,int speedy_,std::mt19937 rng);
    Worm(const Worm& other)= default;
    ~Worm() override =default;
    [[nodiscard]] Objective* clone() const override{
        return new Worm(*this);
    }
    void move() override;
    [[maybe_unused]] void print() override;
};


#endif //OOP_WORM_H
