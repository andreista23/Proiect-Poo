//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_SNAKE_H
#define OOP_SNAKE_H
#include <iostream>
#include "GridSquare.h"

class Snake {
    int size;
    static const int max_size=10;
    GridSquare body[max_size];
public:
    explicit Snake(int _size=1,int _x=1, int _y=1);
    Snake(const Snake& other)=default;
    ~Snake()=default;
    GridSquare& getSnakeHead();
    void IncreaseSize();
    friend std::ostream &operator<<(std::ostream &os, const Snake &snake);
};


#endif //OOP_SNAKE_H
