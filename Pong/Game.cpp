#include "Game.hpp"

Game::Game()
{
    PLAYER_ONE.setSize(sf::Vector2f(20.f,140.f));
    PLAYER_TWO.setSize(sf::Vector2f(20.f,140.f));
    BALL.setSize(sf::Vector2f(20.f, 20.f));
    WINDOW = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");
}

Game::~Game()
{
    
}

void Game::Run()
{
    initScreen();
    resetBall();
}

void Game::initScreen()
{
    WINDOW -> setFramerateLimit(60);
    WINDOW -> setVerticalSyncEnabled(true);
    while (WINDOW -> isOpen())
    {
        // Process events
        sf::Event event;
        while (WINDOW -> pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                WINDOW -> close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                WINDOW -> close();
            }
        }
        WINDOW -> clear();
        Render();
        WINDOW -> display();
    }
}

void Game::Render()
{
    PLAYER_ONE.setPosition(20, SCREEN_HEIGHT/2);
    PLAYER_TWO.setPosition(1240, SCREEN_HEIGHT/2);
    WINDOW -> draw(PLAYER_ONE);
    WINDOW -> draw(PLAYER_TWO);
    WINDOW -> draw(BALL);
   
}

void Game::resetBall()
{
    BALL.setPosition(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
    
}

void Game::playerMove(float x_direction, sf::RectangleShape paddle)
{
    paddle.move(x_direction, 0);
}
