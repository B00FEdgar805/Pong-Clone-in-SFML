#include "Game.hpp"

Game::Game()
{
    WINDOW = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong"); // Set window size and title
    //init ball and paddles
    BALL.setSize(sf::Vector2f(20.f, 20.f));
    PLAYER_ONE.PADDLE.setPosition(20, SCREEN_HEIGHT/2 - 70.f);
    PLAYER_TWO.PADDLE.setPosition(1240, SCREEN_HEIGHT/2 - 70.f);
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
    if(!font.loadFromFile("Assets/Orbitron-Regular 2.ttf")) // Returns error if font cant be loaded
    {
       // return EXIT_FAILURE;
    }
    
    text.setFont(font);
    text.setString("0 : 0");
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    // Centers the text
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
        Render();   // Draws all the objects
        Update();   // Main game loop
        WINDOW -> display();
    }
}

void Game::ballPhysics()
{
    
    BALL.move(BALL_X * BALL_VELOCITY ,  BALL_Y * BALL_VELOCITY);
    
    if(BALL.getPosition().x > SCREEN_WIDTH) // If player wins
    {
        gameLogic(true);
        resetBall();
    }
    
    if(BALL.getPosition().x < 0)    // If player loses
    {
        gameLogic(false);
        resetBall();
    }
    
    if(BALL.getPosition().y > SCREEN_HEIGHT - 20 || BALL.getPosition().y < 0)   // Checks if ball is in bounds vertically
    {
        BALL_Y *= -1;
    }
    
    if(PLAYER_ONE.PADDLE.getGlobalBounds().intersects(BALL.getGlobalBounds()))  // Checks for collision with player paddle
    {
        BALL_X *= -1;
        
    }
    
    if(PLAYER_TWO.PADDLE.getGlobalBounds().intersects(BALL.getGlobalBounds()))  // Checks for collission with cpu paddle
    {
        BALL_X *= -1;
       
    }
}

void Game::Update() // Main game loop
{
    ballPhysics();
    PLAYER_ONE.paddleMovements();
    PLAYER_TWO.cpuLogic(BALL);
    PLAYER_ONE.checkBounds();
    PLAYER_TWO.checkBounds();
}


void Game::Render() // Where all objects are drawn
{
    PLAYER_ONE.Render(*WINDOW);
    PLAYER_TWO.Render(*WINDOW);
    WINDOW -> draw(BALL);
    WINDOW -> draw(text);
}

void Game::gameLogic(bool win)  // Handles when player wins or loses
{
    if (win == true)
    {
        PLAYER_ONE_SCORE++;
    }
    else
    {
        PLAYER_TWO_SCORE++;
    }

    // Updates the score borard
    text.setString(std::to_string(PLAYER_ONE_SCORE) + " : " + std::to_string(PLAYER_TWO_SCORE));
    // Re-center in case width changed and makes sure no QoS error
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    text.setPosition(SCREEN_WIDTH / 2.f, 40.f);
}

void Game::resetBall()
{
    BALL.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    
    // Set direction for begging of the game
    if (BALL_X == 0 && BALL_Y == 0)
    {
        BALL_X = 1; BALL_Y = 1;
    }
}

