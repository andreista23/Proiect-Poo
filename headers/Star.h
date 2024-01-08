//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_STAR_H
#define OOP_STAR_H
#include <iostream>
#include "GridSquare.h"
#include "Objective.h"
class Star : public Objective{
    int startype;
public:
    explicit Star( std::mt19937 rng,int startype_=1);
    Star(const Star& other)= default;
    ~Star() override =default;
    [[nodiscard]] Objective* clone() const override{
        return new Star(*this);
    }
    [[maybe_unused]] void print() override;
};


#endif //OOP_STAR_H
