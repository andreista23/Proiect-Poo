//
// Created by Andrei on 1/6/2024.
//

#include "../headers/Game.h"

sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");

Game::Game() : rng(std::random_device()()), rng2(std::random_device()()), fruit(rng) {
    GameOverTexture.loadFromFile("../textures/GameOver.png");
    GenerateObstacles(rng2);
    fruit.respawn(rng,loc_to_avoid,obstacle_number);
}

void Game::Go()
{
    while (window.isOpen())
    {
        delta_time=clock.restart().asSeconds();

        sf::Event evnt{};
        while (window.pollEvent(evnt))
        {

            if (evnt.type == sf::Event::Closed)
                window.close();
        }
        if(!GameOver)
            this->Loop();

    }
}
void Game::Loop() {
    total_time+=delta_time;
    Location next_delta_loc;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        Location new_delta_loc(-1,0);
        next_delta_loc=new_delta_loc;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        Location new_delta_loc(1,0);
        next_delta_loc=new_delta_loc;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        Location new_delta_loc(0,-1);
        next_delta_loc=new_delta_loc;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        Location new_delta_loc(0,1);
        next_delta_loc=new_delta_loc;
    }
    //conditia se asigura ca sarpele nu isi schimba directia in sens in invers
    if(next_delta_loc!=Location(0,0)){
        if (!(next_delta_loc.x + delta_loc.x == 0 && next_delta_loc.y + delta_loc.y == 0)||player1.getSize() == 1)
            delta_loc = next_delta_loc;
    }
    if(total_time>=switch_time){
        if(player1.IsOutsideGrid(delta_loc)||player1.HeadInTail(delta_loc)||HitObstacle())
            GameOver=true;

        else
            player1.Move(delta_loc);
        total_time-=switch_time;
    }
    if(!GameOver){
        if(player1.Eat(fruit)){
            player1.Grow();
            fruit.respawn(rng,loc_to_avoid,obstacle_number);
        }
    }
    window.clear();
    player1.Draw(grd,window,sf::Color::Green);
    fruit.Draw(grd,window,sf::Color::Red);
    DrawObstacles(window);
    if(GameOver){
        DrawGameOver(window);
    }
    window.display();
}

void Game::DrawGameOver(sf::RenderWindow &wnd) {
    sf::RectangleShape GameOverScreen(sf::Vector2f(200, 200));
    GameOverScreen.setPosition(300, 200);
    //GameOverScreen.setFillColor(sf::Color::Red);
    GameOverScreen.setTexture(&GameOverTexture);
    wnd.draw(GameOverScreen);
}

void Game::GenerateObstacles(std::mt19937 &rng3) {
    int i;
    Location newLoc;
    for(i=0;i<obstacle_number;i++) {
        std::uniform_int_distribution<int> xDist(0, Grid::getLength() - 1);
        std::uniform_int_distribution<int> yDist(0, Grid::getWidth() - 1);
        do {
            newLoc.x = xDist(rng3);
            newLoc.y = yDist(rng3);
        } while (player1.IsInsideSnake(newLoc));
        obstacle.at(i).SetPosition(newLoc);
        loc_to_avoid[i]=newLoc;
    }
}

void Game::DrawObstacles(sf::RenderWindow &wnd) {
    int i;
    for(i=0;i<obstacle_number;i++)
        obstacle.at(i).Draw(grd,wnd);
}

bool Game::HitObstacle() {
    int i;
    for(i=0;i<obstacle_number;i++)
        if(player1.GetHeadLocation()+delta_loc==obstacle.at(i).GetLoc())
            return true;
    return false;
}
