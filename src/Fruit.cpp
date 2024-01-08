//
// Created by nalee on 11/26/2023.
//

#include "../headers/Fruit.h"

Fruit::Fruit(std::mt19937 rng,const std::string& color_):Objective(rng),color(color_) {
}

void Fruit::print() {
    std::cout<<"this is a fruit "<<std::endl;
}

void Fruit::Draw(Grid &grd, sf::RenderWindow &window,sf::Texture* texture,sf::Color color) {
    objsquare.Draw(grd,window,texture,color);
}

