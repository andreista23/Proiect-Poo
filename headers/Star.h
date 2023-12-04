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
    explicit Star( int x_=1, int y_=1,int score_=50,int startype_=1);
    Star(const Star& other)= default;
    ~Star() override =default;
    friend std::ostream &operator<<(std::ostream &os, const Star &star);
    [[nodiscard]] Objective* clone() const override{
        return new Star(*this);
    }
    [[maybe_unused]] void print() override;
};


#endif //OOP_STAR_H
