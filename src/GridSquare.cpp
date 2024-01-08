//
// Created by nalee on 11/26/2023.
//
#include "../headers/GridSquare.h"
GridSquare::GridSquare(int x_, int y_, bool full_) : loc(x_,y_), full(full_) {
    if(x_<0||x_>Grid::getLength()||y_<0||y_>Grid::getWidth())
        throw ExceptionOutOfMapBounds();
}

[[maybe_unused]] GridSquare::GridSquare(const GridSquare& other){
    this->loc=other.loc;
    this->full=other.full;
}
bool GridSquare::isSameSquare(const GridSquare& other) const{
    if(this->loc==other.loc)
        return true;
    return false;
}
void GridSquare::setposition(Location newloc){
    this->loc=newloc;
}
void GridSquare::move(Location deltaloc) {

    loc.Add(deltaloc);
}

const Location &GridSquare::getLoc() const {
    return loc;
}

void GridSquare::Draw(Grid &grd,sf::RenderWindow& window,sf::Color color) const {
    grd.DrawCell(loc,window,color);
}


