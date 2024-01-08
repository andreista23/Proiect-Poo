//
// Created by Andrei on 1/7/2024.
//

#ifndef OOP_OBSTACLE_H
#define OOP_OBSTACLE_H

#include "GridSquare.h"

class Obstacle {
    GridSquare objsquare;
    sf::Color color;
public:
    Obstacle(Location loc=Location(0,0));
    void SetPosition(Location loc);
    void Draw(Grid& grd,sf::RenderWindow& window);
    Location GetLoc();
};


#endif //OOP_OBSTACLE_H
