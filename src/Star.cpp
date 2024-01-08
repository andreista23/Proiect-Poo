//
// Created by nalee on 11/26/2023.
//

#include "../headers/Star.h"


Star::Star( std::mt19937 rng,int startype_):Objective(rng),startype(startype_) {}


void Star::print() {
    std::cout<<"this is a star "<<std::endl;
}
