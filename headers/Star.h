//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_STAR_H
#define OOP_STAR_H
#include <iostream>
#include "GridSquare.hpp"

class Star {
    GridSquare starsquare;
    const int score;
public:
    explicit Star( int _x=1, int _y=1,int _score=50);
    Star(const Star& other)= default;
    ~Star()=default;
    GridSquare  getstarsquare();
    [[nodiscard]] int getscore() const;
    friend std::ostream &operator<<(std::ostream &os, const Star &star);
    Star& operator=([[maybe_unused]] const Star& other);
};


#endif //OOP_STAR_H
