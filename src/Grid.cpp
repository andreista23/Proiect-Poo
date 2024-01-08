//
// Created by nalee on 11/26/2023.
//

#include "../headers/Grid.h"

int Grid::getLength() {
    return length;
}

int Grid::getWidth() {
    return width;
}
const int Grid::length=32;
const int Grid::width=24;
const int Grid::square_size=25;

void Grid::DrawCell(Location draw_loc,sf::RenderWindow& window,sf::Color color) {
    sf::RectangleShape cell(sf::Vector2f(Grid::square_size, Grid::square_size));
    cell.setPosition((float)draw_loc.getX()*Grid::square_size,(float)draw_loc.getY()*Grid::square_size);
    cell.setFillColor(color);
    window.draw(cell);
}

void Grid::DrawCell(Location draw_loc, sf::RenderWindow &window, sf::Texture* texture) {
    sf::RectangleShape cell(sf::Vector2f(Grid::square_size, Grid::square_size));
    cell.setPosition((float)draw_loc.getX()*Grid::square_size,(float)draw_loc.getY()*Grid::square_size);
    //cell.setFillColor(color);
    cell.setTexture(texture);
    window.draw(cell);
}

