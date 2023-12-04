//
// Created by nalee on 11/26/2023.
//

#include "../headers/Snake.h"

Snake::Snake(int _size,int _x, int _y) : size(_size) {
    body[0].setposition(_x,_y);
}
GridSquare& Snake::getSnakeHead(){
    return this->body[0];
}
void Snake::IncreaseSize(){
    size++;
}
std::ostream &operator<<(std::ostream &os, const Snake &snake) {
    os << "size: " << snake.size << " max_size: " <<Snake::max_size << " body: ";
    for(int i=0;i<snake.size;i++)
        std::cout<<snake.body[i];
    return os;
}