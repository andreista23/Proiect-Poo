
#include "headers/Game.h"

using namespace std;

int main() {
    Game& game = Game::GetInstance();
    game.Go();
    return 0;
}