//
// Created by nalee on 11/26/2023.
//

#include "../headers/Grid.h"
Grid::Grid(const int _length, const int _width) : length(_length), width(_width){}
std::ostream &operator<<(std::ostream &os, const Grid &grid) {
    os << "length: " << grid.length << " width: " << grid.width;
    return os;
}