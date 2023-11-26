//
// Created by nalee on 11/26/2023.
//

#include "../headers/Fruit.h"
Fruit::Fruit(int _x,int _y,int _score):score{_score} {
    fruitsquare.setposition(_x,_y);
}
GridSquare Fruit::getfruitsquare() {
    return this->fruitsquare;
}
int Fruit::getscore() const{
    return score;
}
std::ostream &operator<<(std::ostream &os, const Fruit &fruit) {
    os <<fruit.fruitsquare<< " score: " << fruit.score;
    return os;
}
Fruit& Fruit::operator=([[maybe_unused]] const Fruit& other){
    this->fruitsquare=other.fruitsquare;
    return *this;
}