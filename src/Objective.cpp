//
// Created by Andrei on 11/26/2023.
//

#include "../headers/Objective.h"

Objective::Objective(int x_,int y_,  int score_) : score(score_), objsquare(x_,y_) {
    Objective::number++;
}

GridSquare Objective::getobjsquare() {
    return this->objsquare;
}
int Objective::getscore() const{
    return score;
}
std::ostream &operator<<(std::ostream &os, const Objective &obj) {
    os <<obj.objsquare<< " score: " << obj.score;
    return os;
}

[[maybe_unused]] void Objective::print() {
    std::cout<<"this is an objective ";
}
int Objective :: number = 0;

int Objective::getnumber() {
    return number;
}

