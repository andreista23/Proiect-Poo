//
// Created by Andrei on 1/6/2024.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H
#include <iostream>
#include <vector>
#include "GridSquare.h"
#include "Fruit.h"
#include "Star.h"
#include "Player.h"
#include "Obstacle.h"
#include <random>
#include <../SFML/Graphics.hpp>

class Game {
    Player player1;
    Location delta_loc;
    Grid grd;
    std::mt19937 rng;
    std::mt19937 rng2;
    Fruit fruit;
    bool GameOver=false;
    float delta_time=0;
    const float switch_time=0.2;
    float total_time=0;
    static const int obstacle_number=20;
    vector <Obstacle,obstacle_number> obstacle;
    Location loc_to_avoid[obstacle_number];
    sf::Clock clock;
    sf::Texture GameOverTexture;
    void DrawGameOver(sf::RenderWindow& wnd);
    void DrawObstacles(sf::RenderWindow& wnd);
    void GenerateObstacles(std::mt19937& rng2);
    bool HitObstacle();
protected:
    Game();
public:
    void Loop();
    void Go();
    static Game& GetInstance(){
        static Game game;
        return game;
    }
    Game(const Game&) = delete;
    Game(Game&&) = delete;
    Game& operator=(const Game&) = delete;
};


#endif //OOP_GAME_H
