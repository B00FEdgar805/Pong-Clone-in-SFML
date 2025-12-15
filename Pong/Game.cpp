#include "Game.hpp"

Game::Game()
{
    BALL.setSize(sf::Vector2f(20.f, 20.f));
    WINDOW = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");
    PLAYER_ONE.PADDLE.setPosition(20, SCREEN_HEIGHT/2);
    PLAYER_TWO.PADDLE.setPosition(1240, SCREEN_HEIGHT/2);
    initText();
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

void Game::initText()
{
    if(!font.loadFromFile("Assets/Orbitron-Regular 2.ttf"))
        return EXIT_FAILURE;
    text.setFont(font);
    text.setString("0 : 0");
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    text.setPosition(SCREEN_WIDTH / 2.f, 40.f);
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

void Game::ballPhysics()
{
    
    if(BALL.getPosition().x > SCREEN_WIDTH)
    {
        gameLogic(true);
        resetBall();
    }
    
    if(BALL.getPosition().x < 0)
    {
        gameLogic(false);
        resetBall();
    }
    
    if(BALL.getPosition().y > SCREEN_HEIGHT - 20 || BALL.getPosition().y < 0)
    {
        BALL_Y *= -1;
    }
    
    if(PLAYER_ONE.PADDLE.getGlobalBounds().intersects(BALL.getGlobalBounds()))
    {
        BALL_X *= -1;
        
    }
    
    if(PLAYER_TWO.PADDLE.getGlobalBounds().intersects(BALL.getGlobalBounds()))
    {
        BALL_X *= -1;
       
    }
}

void Game::Update()
{
    BALL.move(BALL_X * BALL_VELOCITY ,  BALL_Y * BALL_VELOCITY);
    ballPhysics();
    PLAYER_ONE.paddleMovements();
    PLAYER_ONE.checkBounds();
    PLAYER_TWO.checkBounds();
}


void Game::Render()
{
    //std::cout << PLAYER_ONE;
    
    PLAYER_ONE.Render(*WINDOW);
    PLAYER_TWO.Render(*WINDOW);
    WINDOW -> draw(BALL);
    WINDOW -> draw(text);
}

void Game::gameLogic(bool win)
{
    if (win == true)
    {
        PLAYER_ONE_SCORE++;
    }
    else
    {
        PLAYER_TWO_SCORE++;
    }


    text.setString(std::to_string(PLAYER_ONE_SCORE) + " : " + std::to_string(PLAYER_TWO_SCORE));
    // Re-center in case width changed
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    text.setPosition(SCREEN_WIDTH / 2.f, 40.f);
}

void Game::resetBall()
{
    BALL.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    
    //Randomize ball direction if needed
    if (BALL_X == 0 && BALL_Y == 0)
    {
        BALL_X = 1; BALL_Y = 1;
    }
}

