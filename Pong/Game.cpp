#include "Game.hpp"

Game::Game()
{
    PLAYER_ONE.setSize(sf::Vector2f(20.f,140.f));
    PLAYER_TWO.setSize(sf::Vector2f(20.f,140.f));
    BALL.setSize(sf::Vector2f(20.f, 20.f));
    WINDOW = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");
    PLAYER_ONE.setPosition(20, SCREEN_HEIGHT/2);
    PLAYER_TWO.setPosition(1240, SCREEN_HEIGHT/2);
}

Game::~Game()
{
    delete WINDOW;
}

void Game::Run()
{
    resetBall();
    initScreen();
   
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
        Update();
        WINDOW -> display();
    }
}

void Game::Physics()
{
    if(BALL.getPosition().x > SCREEN_WIDTH || BALL.getPosition().x < 0)
    {
        BALL_X *= -1;
    }
    
    if(BALL.getPosition().y > SCREEN_HEIGHT - 20 || BALL.getPosition().y < 0)
    {
        BALL_Y *= -1;
    }
    
    if(PLAYER_ONE.getGlobalBounds().intersects(BALL.getGlobalBounds()))
    {
        BALL_X *= -1;
        
    }
    
    if(PLAYER_TWO.getGlobalBounds().intersects(BALL.getGlobalBounds()))
    {
        BALL_X *= -1;
       
    }
}

void Game::playerInputs()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        PLAYER_ONE.move(0.f, -5.f);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        PLAYER_ONE.move(0.f, 5.f);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        PLAYER_TWO.move(0.f, -5.f);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        PLAYER_TWO.move(0.f, 5.f);
    }
}

void Game::Update()
{
    BALL.move(BALL_X * BALL_VELOCITY * -1, 0 * BALL_Y * BALL_VELOCITY);
    Physics();
    playerInputs();
}

void Game::Render()
{
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
