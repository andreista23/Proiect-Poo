
#include "headers/Game.h"

using namespace std;
//controale:: W-sus A-stanga S-jos D-dreapta
int main() {
    Game& game = Game::GetInstance();
    game.Go();
    return 0;
}