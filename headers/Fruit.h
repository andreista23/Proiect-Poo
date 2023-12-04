//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_FRUIT_H
#define OOP_FRUIT_H
#include <iostream>
#include "GridSquare.h"
#include "Objective.h"

class Fruit : public Objective{
    std::string color;
public:
    explicit Fruit(int x_=1,int y_=1,int score_=25,const std::string& color_ = "red");
    Fruit(const Fruit& other)= default;
    ~Fruit() override =default;
    [[nodiscard]] Objective* clone() const override{
        return new Fruit(*this);
    }
    friend std::ostream &operator<<(std::ostream &os, const Fruit &fruit);
    void print() override;
};


#endif //OOP_FRUIT_H
