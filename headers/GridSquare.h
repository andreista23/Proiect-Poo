//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_GRIDSQUARE_H
#define OOP_GRIDSQUARE_H
#include <iostream>
#include "Grid.h"
#include "Exceptions.h"
class GridSquare{
    int x;
    int y;
    bool full;
    static const int square_size;
public:
    explicit GridSquare(int x_=1, int y_=1, bool full_=false);

    [[maybe_unused]] GridSquare(const GridSquare& other);
    ~GridSquare()=default;
    [[nodiscard]] bool isSameSquare(const GridSquare& other) const;
    void  setposition(int x_, int y_);
    void move(int x_, int y_);
    friend std::ostream &operator<<(std::ostream &os, const GridSquare &square);
    GridSquare& operator=(const GridSquare& gr)= default;
};
#endif //OOP_GRIDSQUARE_H
