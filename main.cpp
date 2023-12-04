#include <iostream>
#include <utility>
#include <vector>
#include "headers/GridSquare.h"
#include "headers/Grid.h"
#include "headers/Snake.h"
#include "headers/Fruit.h"
#include "headers/Star.h"
#include "headers/Player.h"
using namespace std;

const int GridSquare:: square_size=20;

int main() {
    vector<Objective*> objective;
    try{
    objective.push_back(new Fruit(2,3));
    }
    catch(exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }
    try{
    objective.push_back(new Fruit(5,10));
    }
    catch(exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }
    try{
    objective.push_back(new Star(1,1));
    } catch(exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }
    try{
    objective.push_back(new Star(2,3));
    } catch(exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }
    cout<<*dynamic_cast<Fruit*>(objective[0])<<endl;
    Player player1("andrei",0,2,3);
    cout<<player1<<endl;
    for (int i = 0; i<Objective::getnumber();i++){
        if(dynamic_cast<Fruit*>(objective[i]))
            player1.EatFruit(dynamic_cast<Fruit*>(objective[i]));
        else if(dynamic_cast<Star*>(objective[i]))
            player1.EatStar(dynamic_cast<Star*>(objective[i]));
    }
    player1.MoveWorm();
    cout<<player1;
    for (int i = 0; i<Objective::getnumber();i++)
        delete(objective[i]);
    return 0;
}