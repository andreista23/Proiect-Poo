//
// Created by nalee on 11/26/2023.
//

#include "../headers/Player.h"
Player::Player(std::string name_, int score_, int x_, int y_):name{std::move(name_)},playersnake{1,x_,y_}{
score=score_;
//worm=new Worm(0,1,25, 29);
}


Player& Player::operator=(Player other) {
    if(&other!=this){
        this->playersnake=other.playersnake;
        this->score=other.score;
        this->name=other.name;
    }
    return *this;
}

[[maybe_unused]] Player::Player(const Player&  other) {
    this->score=other.score;
    this->playersnake=other.playersnake;
    this->name=other.name;
}

void Player::Grow() {
    playersnake.IncreaseSize();
}

void Player::Move(Location delta_loc) {
    playersnake.Move(delta_loc);
}

void Player::Draw(Grid &grd,sf::RenderWindow& window) {
    playersnake.Draw(grd,window);
}

bool Player::Eat(Objective &obj) {
    if(obj.getobjsquare().getLoc()==playersnake.getSnakeHead().getLoc())
        return true;
    return false;
}

bool Player::IsOutsideGrid(Location delta_loc) {
    return playersnake.IsOutsideGrid(delta_loc);
}

bool Player::HeadInTail(Location delta_loc) {
    return playersnake.IsInsideSnake(playersnake.getSnakeHead().getLoc() + delta_loc);
}

int Player::getSize() {
    return playersnake.getSize();
}

Location Player::GetHeadLocation() {
    return playersnake.getSnakeHead().getLoc();
}

bool Player::IsInsideSnake(Location loc) {
    return playersnake.IsInsideSnake(loc);
}
