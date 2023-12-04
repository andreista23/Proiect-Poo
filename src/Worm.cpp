//
// Created by Andrei on 11/27/2023.
//

#include "../headers/Worm.h"

Worm::Worm(int speedx_,int speedy_,int x_,int y_,int score_):Objective(x_,y_,score_),speedx(speedx_),speedy(speedy_) {}

void Worm::move(){
    this->objsquare.move(speedx,speedy);
}

void Worm::print() {
    std::cout<<"this is a star "<<std::endl;
}
