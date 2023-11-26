//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_FRUIT_H
#define OOP_FRUIT_H
#include <iostream>
#include "GridSquare.hpp"

class Fruit {
    GridSquare fruitsquare;
    const int score;
public:
    explicit Fruit(int _x=1,int _y=1,int _score=25);
    Fruit(const Fruit& other)= default;
    ~Fruit()=default;
    GridSquare  getfruitsquare();
    [[nodiscard]] int getscore() const;
    friend std::ostream &operator<<(std::ostream &os, const Fruit &fruit);
    Fruit& operator=([[maybe_unused]] const Fruit& other);
};


#endif //OOP_FRUIT_H
