//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_GRID_H
#define OOP_GRID_H
#include <iostream>

class Grid {
    static const int length;
    static const int width;
public:
    ~Grid()=default;
    [[nodiscard]]static int getLength();
    [[nodiscard]]static int getWidth();
};




#endif //OOP_GRID_H
