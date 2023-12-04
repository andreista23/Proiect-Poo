//
// Created by nalee on 11/26/2023.
//

#include "../headers/Fruit.h"

Fruit::Fruit(int x_,int y_,int score_,const std::string& color_):Objective(x_,y_,score_),color(color_) {
}

std::ostream &operator<<(std::ostream &os, const Fruit &fruit) {
    os << static_cast<const Objective &>(fruit) << " color: " << fruit.color;
    return os;
}

void Fruit::print() {
    std::cout<<"this is a fruit "<<std::endl;
}

