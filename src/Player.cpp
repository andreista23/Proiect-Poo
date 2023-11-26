//
// Created by nalee on 11/26/2023.
//

#include "../headers/Player.h"

Player::Player(std::string _name, int _score, int _x, int _y):name{std::move(_name)}{
score=_score;
playersnake.getSnakeHead().setposition(_x,_y);
}
std::ostream& operator<<(std::ostream& os,const Player& pl){
    os<<"name: "<<pl.name<<" score= "<<pl.score<<" player_snake: "<<pl.playersnake;
    return os;
}
int Player::EatFruit(Fruit& fr){
    if(playersnake.getSnakeHead().isSameSquare(fr.getfruitsquare())){
        std::cout<<"fruct mancat"<<std::endl;
        score=score+fr.getscore();
        playersnake.IncreaseSize();
        return 1;
    }
    return 0;
}
int Player::EatStar(Star& st){
    if(playersnake.getSnakeHead().isSameSquare(st.getstarsquare())){
        std::cout<<"stea mancata"<<std::endl;
        score=score+st.getscore();
        playersnake.IncreaseSize();
        return 1;
    }
    return 0;
}