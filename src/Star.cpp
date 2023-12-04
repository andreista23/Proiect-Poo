//
// Created by nalee on 11/26/2023.
//

#include "../headers/Star.h"


Star::Star( int x_, int y_,int score_,int startype_):Objective(x_,y_,score_),startype(startype_) {}

std::ostream &operator<<(std::ostream &os, const Star &star) {
    os <<static_cast<const Objective&>(star)<<"startype: "<<star.startype;
    return os;
}

void Star::print() {
    std::cout<<"this is a star "<<std::endl;
}
