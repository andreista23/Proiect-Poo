//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_GRIDSQUARE_H
#define OOP_GRIDSQUARE_H
#include <iostream>
#include "Grid.h"
#include "Location.h"
#include "Exceptions.h"
class GridSquare{
    Location loc;
    bool full;
public:
    explicit GridSquare(int x_=1, int y_=1, bool full_=false);

    [[maybe_unused]] GridSquare(const GridSquare& other);
    ~GridSquare()=default;
    [[nodiscard]] bool isSameSquare(const GridSquare& other) const;
    void  setposition(Location newloc);
    void move(Location delta_loc);
    void Draw(Grid& grd,sf::RenderWindow& window,sf::Color color) const;
    [[nodiscard]] const Location &getLoc() const;
};
#endif //OOP_GRIDSQUARE_H
