//
// Created by nalee on 11/26/2023.
//

#include "../headers/Snake.h"

Snake::Snake(int _size,int _x, int _y) : size(_size) {
    body.at(0).setposition(Location(_x,_y));
    head_color = sf::Color::Green;
    body_color = sf::Color(1,80,42);
}
GridSquare& Snake::getSnakeHead(){
    return this-> body.at(0);
}
void Snake::IncreaseSize(){
    size++;
    body.at(size-1).setposition(body.at(size-2).getLoc());
}
void Snake::Move(Location delta_loc){
    int i;
    for(i=this->size-1;i>0;i--)
        body.at(i).setposition(body.at(i-1).getLoc());
    body.at(0).move(delta_loc);
}

void Snake::Draw(Grid &grd,sf::RenderWindow& window) {
    int i;
    body.at(0).Draw(grd,window,head_color);
    for(i=1;i<size;i++)
        body.at(i).Draw(grd,window,body_color);
}

bool Snake::IsOutsideGrid(Location delta_loc) {
    Location loc=getSnakeHead().getLoc();
    loc.Add(delta_loc);
    if(loc.getX()<0||loc.getX()>=Grid::getLength())
        return true;
    if(loc.getY()<0||loc.getY()>=Grid::getWidth())
        return true;
    return false;

}

bool Snake::IsInsideSnake(Location loc) {
    int i;
    for(i=size-2;i>0;i--)
        if(loc == body.at(i).getLoc())
            return true;
    return false;
}

int Snake::getSize() const {
    return size;
}
