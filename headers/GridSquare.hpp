//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_GRIDSQUARE_HPP
#define OOP_GRIDSQUARE_HPP
#include <iostream>
class GridSquare{
    int x;
    int y;
    bool full;
    static const int square_size;
public:
    explicit GridSquare(int _x=1, int _y=1, bool _full=false);
    GridSquare(const GridSquare& other);
    ~GridSquare()=default;
    [[nodiscard]] bool isSameSquare(const GridSquare& other) const;
    void  setposition(int x_, int y_);
    friend std::ostream &operator<<(std::ostream &os, const GridSquare &square);
    GridSquare& operator=(const GridSquare& gr)= default;
};
#endif //OOP_GRIDSQUARE_HPP
