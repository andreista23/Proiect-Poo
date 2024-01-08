//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_GRID_H
#define OOP_GRID_H
#include <iostream>
#include "Location.h"
#include "SFML/Graphics.hpp"

class Grid {
    static const int length;
    static const int width;
    static const int square_size;
public:
    ~Grid()=default;
    [[nodiscard]]static int getLength();
    [[nodiscard]]static int getWidth();
    void DrawCell(Location draw_loc,sf::RenderWindow& window,sf::Color color = sf::Color::Black);
    void DrawCell(Location draw_loc,sf::RenderWindow& window,sf::Texture* texture,sf::Color color = sf::Color::Black);
};




#endif //OOP_GRID_H
