//
// Created by Andrei on 11/27/2023.
//

#include "../headers/Worm.h"

Worm::Worm(int speedx_,int speedy_,std::mt19937 rng):Objective(rng),speed(speedx_,speedy_) {}

void Worm::move(){
    this->objsquare.move(speed);
}

void Worm::print() {
    std::cout<<"this is a star "<<std::endl;
}
