//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_SNAKE_H
#define OOP_SNAKE_H
#include <iostream>
#include "vector.h"
#include "GridSquare.h"

class Snake {
    int size;
    static const int max_size=100;
    vector<GridSquare,max_size>body;
    sf::Color body_color;
    sf::Color head_color;
public:
    explicit Snake(int _size=1,int _x=1, int _y=1);
    Snake(const Snake& other)=default;
    ~Snake()=default;
    GridSquare& getSnakeHead();
    void IncreaseSize();
    void Move(Location delta_loc);
    void Draw(Grid& grd,sf::RenderWindow& window);
    bool IsOutsideGrid(Location delta_loc);
    bool IsInsideSnake(Location delta_loc);

    int getSize() const;
};


#endif //OOP_SNAKE_H
