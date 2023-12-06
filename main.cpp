#include <iostream>
#include <vector>
#include "headers/GridSquare.h"
#include "headers/Fruit.h"
#include "headers/Star.h"
#include "headers/Player.h"
using namespace std;

const int GridSquare:: square_size=20;

int main() {
    vector<Objective*> objective;
    try{
    objective.push_back(new Fruit(8,3));
    }
    catch(exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }
    try{
    objective.push_back(new Fruit(3,3));
    }
    catch(exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }
    try{
    objective.push_back(new Star(1,3));
    }
    catch(exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }
    try{
    objective.push_back(new Star(3,3));
    }
    catch(exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }
    cout<<Objective::getnumber();
    Player player1("andrei",0,3,3);
    cout<<player1<<endl;
    for (auto & i : objective){
        if(auto fruit = dynamic_cast<Fruit*>(i))
            player1.EatFruit(fruit);
        else if(auto star = dynamic_cast<Star*>(i))
            player1.EatStar(star);
    }
    objective[0]->print();
    objective[2]->print();
    player1.MoveWorm();
    cout<<player1;
    for (int i = 0; i<Objective::getnumber();i++)
        delete(objective[i]);
    return 0;
}