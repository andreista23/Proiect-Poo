//
// Created by Andrei on 1/6/2024.
//

#include "../headers/Location.h"

void Location::Add(Location delta_loc) {
    this->x=this->x + delta_loc.x;
    this->y=this->y + delta_loc.y;
}

Location::Location(int x, int y) : x(x), y(y) {}

bool Location::operator==(const Location &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Location::operator!=(const Location &rhs) const {
    return !(rhs == *this);
}

void Location::SetLoc(Location newloc) {
   // if(newloc.x<0||newloc.x>Grid::getLength()||newloc.y<0||newloc.y>Grid::getWidth())
       // throw ExceptionMoveOutOfBounds();
        this->x=newloc.getX();
        this->y=newloc.getY();
}

int Location::getX() const {
    return x;
}

int Location::getY() const {
    return y;
}

Location Location::operator+(const Location &other) const{
    Location newloc;
    newloc.x=x+other.x;
    newloc.y=y+other.y;
    return newloc;
}

