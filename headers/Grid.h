//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_GRID_H
#define OOP_GRID_H
#include <iostream>

class Grid {
    const int length;
    const int width;
public:
    explicit Grid(const int _length=40, const int _width=30);
    ~Grid()=default;

    friend std::ostream &operator<<(std::ostream &os, const Grid &grid);
};


#endif //OOP_GRID_H
