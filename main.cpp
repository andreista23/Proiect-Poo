#include <iostream>
#include <utility>
#include "headers/GridSquare.hpp.."
#include "headers/Grid.h"
#include "headers/Snake.h"
#include "headers/Fruit.h"
#include "headers/Star.h"
#include "headers/Player.h"
using namespace std;

const int GridSquare:: square_size=20;

int main() {
    Grid grid(30,30);
    cout<<"grid: "<<grid<<endl;
    Player player1("andrei",0,2,3);
    Fruit fr1(2,3),fr2(5,10);
    Star st(1,1),st2(2,3);
    player1.EatFruit(fr1);
    player1.EatFruit(fr2);
    player1.EatStar(st);
    player1.EatStar(st2);
    cout<<player1;
    return 0;
}