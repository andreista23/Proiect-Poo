//
// Created by nalee on 11/26/2023.
//

#include "../headers/Star.h"


Star::Star( int _x, int _y,int _score):score{_score} {
    starsquare.setposition(_x,_y);
}
GridSquare  Star::getstarsquare() {
    return this->starsquare;
}
int Star::getscore() const{
    return score;
}
std::ostream &operator<<(std::ostream &os, const Star &star) {
    os <<star.starsquare<< " score: " << star.score;
    return os;
}
Star& Star::operator=([[maybe_unused]] const Star& other){
    starsquare=other.starsquare;
    return *this;
}