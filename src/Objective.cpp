//
// Created by Andrei on 11/26/2023.
//

#include "../headers/Objective.h"

Objective::Objective(std::mt19937& rng,  int score_) : score(score_) {
    this->respawn(rng, nullptr,0);
}

GridSquare Objective::getobjsquare() {
    return this->objsquare;
}

[[maybe_unused]] int Objective::getscore() const{
    return score;
}

[[maybe_unused]] void Objective::print() {
    std::cout<<"this is an objective ";
}

void Objective::respawn(std::mt19937 &rng, Location loc_to_avoid[],int size ) {
    std::uniform_int_distribution<int> xDist(0,Grid::getLength()-1);
    std::uniform_int_distribution<int> yDist(0,Grid::getWidth()-1);
    Location newLoc;
    bool ok;
    do{
        ok=true;
        newLoc.x = xDist(rng);
        newLoc.y = yDist(rng);
        for(int i=0;i<size;i++)
            if(newLoc==loc_to_avoid[i]){
                ok=false;
                break;
            }
    }while(!ok);
    objsquare.setposition(newLoc);
}

