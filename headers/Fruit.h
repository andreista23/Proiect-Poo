//
// Created by nalee on 11/26/2023.
//

#ifndef OOP_FRUIT_H
#define OOP_FRUIT_H
#include <iostream>
#include "GridSquare.h"
#include "Objective.h"

class Fruit : public Objective{
    std::string color;
public:
    explicit Fruit(std::mt19937 rng,const std::string& color_ = "red");
    Fruit(const Fruit& other)= default;
    ~Fruit() override =default;
    [[nodiscard]] Objective* clone() const override{
        return new Fruit(*this);
    }
    [[maybe_unused]] void print() override;
    void Draw(Grid& grd,sf::RenderWindow& window,sf::Texture* texture);
};


#endif //OOP_FRUIT_H
