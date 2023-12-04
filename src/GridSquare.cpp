//
// Created by nalee on 11/26/2023.
//
#include "../headers/GridSquare.h"
GridSquare::GridSquare(int x_, int y_, bool full_) : x(x_), y(y_), full(full_) {
    if(x_<0||x_>Grid::getLength()||y_<0||y_>Grid::getWidth())
        throw ExceptionOutOfMapBounds();
}

[[maybe_unused]] GridSquare::GridSquare(const GridSquare& other){
    this->x=other.x;
    this->y=other.y;
    this->full=other.full;
}
bool GridSquare::isSameSquare(const GridSquare& other) const{
    if(other.x==this->x&&other.y==this->y)
        return true;
    return false;
}
void GridSquare::setposition(int x_, int y_){
    if(x_<0||x_>Grid::getLength()||y_<0||y_>Grid::getWidth())
        throw ExceptionOutOfMapBounds();
    this->x=x_;
    this->y=y_;
}
void GridSquare::move(int x_, int y_) {
    if(x+x_<0||x+x_>Grid::getLength()||y+y_<0||y+y_>Grid::getWidth())
        throw ExceptionMoveOutOfBounds();
    x=x+x_;
    y=y+y_;
}
std::ostream &operator<<(std::ostream &os, const GridSquare &square) {
    os << "x: " << square.x << " y: " << square.y << " full: " << square.full<<" square size: "<<GridSquare::square_size;
    return os;
}
