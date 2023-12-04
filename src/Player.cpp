//
// Created by nalee on 11/26/2023.
//

#include "../headers/Player.h"
Player::Player(std::string name_, int score_, int x_, int y_):name{std::move(name_)},playersnake{1,x_,y_}{
score=score_;
worm=new Worm(0,1,25, 29);
}
std::ostream& operator<<(std::ostream& os,const Player& pl){
    os<<"name: "<<pl.name<<" score= "<<pl.score<<" player_snake: "<<pl.playersnake;
    return os;
}
int Player::EatFruit(Fruit* fr){
    if(playersnake.getSnakeHead().isSameSquare(fr->getobjsquare())){
        std::cout<<"fruct mancat"<<std::endl;
        score=score+fr->getscore();
        playersnake.IncreaseSize();
        return 1;
    }
    return 0;
}
int Player::EatStar(Star* st){
    if(playersnake.getSnakeHead().isSameSquare(st->getobjsquare())){
        std::cout<<"stea mancata"<<std::endl;
        score=score+st->getscore();
        playersnake.IncreaseSize();
        return 1;
    }
    return 0;
}

void Player::MoveWorm() {
    try{
        worm->move();
    }
    catch(std::exception& e) {
        std::cerr << e.what() << '\n';
    }

}

Player& Player::operator=(Player other) {
    if(&other!=this){
        this->playersnake=other.playersnake;
        this->score=other.score;
        this->name=other.name;
        this->worm=other.worm;
    }
    return *this;
}

[[maybe_unused]] Player::Player(Player& other) {
    this->score=other.score;
    this->playersnake=other.playersnake;
    this->name=other.name;
    this->worm=new Worm(0,0);
    this->worm=other.worm;
}
