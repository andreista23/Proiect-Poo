//
// Created by nalee on 11/26/2023.
//
#include "../headers/GridSquare.hpp"
GridSquare::GridSquare(int _x, int _y, bool _full) : x(_x), y(_y), full(_full) {}
GridSquare::GridSquare(const GridSquare& other){
    this->x=other.x;
    this->y=other.y;
    this->full=other.full;
}
bool GridSquare::isSameSquare(const GridSquare& other) const{
    if(other.x==this->x&&other.y==this->y)
        return true;
    return false;
}
void GridSquare::setposition(int _x, int _y){
    this->x=_x;
    this->y=_y;
}

std::ostream &operator<<(std::ostream &os, const GridSquare &square) {
    os << "x: " << square.x << " y: " << square.y << " full: " << square.full<<" square size: "<<GridSquare::square_size;
    return os;
}
