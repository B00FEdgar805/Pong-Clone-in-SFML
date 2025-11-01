#ifndef Game_hpp
#define Game_hpp

#include "SFML/Graphics.hpp"
#include <iostream>

class Game
{
private:
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    int BALL_VELOCITY = 5;
    float BALL_X = 1.f;
    float BALL_Y = 1.f;
    sf::RenderWindow *WINDOW;
    sf::RectangleShape  PLAYER_ONE;
    sf::RectangleShape  PLAYER_TWO;
    sf::RectangleShape BALL;
    
    

    
public:
    Game();
    ~Game();
    void Run();
    void Render();
    void Update();
    void Physics();
    void playerInputs();
    void initScreen();
    void resetBall();
    void playerMove(float x_direction, sf::RectangleShape paddle);
};

#endif
