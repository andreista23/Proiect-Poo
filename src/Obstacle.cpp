//
// Created by Andrei on 1/7/2024.
//

#include "../headers/Obstacle.h"

Obstacle::Obstacle(Location loc): objsquare(loc.x,loc.y), color(155,155,155){

}

void Obstacle::SetPosition(Location loc) {
    objsquare.setposition(loc);
}

void Obstacle::Draw(Grid& grd,sf::RenderWindow& window) {
    grd.DrawCell(objsquare.getLoc(),window,color);
}

Location Obstacle::GetLoc() {
    return objsquare.getLoc();
}
