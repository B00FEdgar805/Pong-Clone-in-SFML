#ifndef Game_hpp
#define Game_hpp

#include "SFML/Graphics.hpp"

class Game
{
private:
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    int BALL_VELOCITY = 50;
    sf::RenderWindow *WINDOW;
    sf::RectangleShape  PLAYER_ONE;
    sf::RectangleShape  PLAYER_TWO;
    sf::RectangleShape BALL;
    
    

    
public:
    Game();
    ~Game();
    void Run();
    void Render();
    void initScreen();
    void resetBall();
    void playerMove(float x_direction, sf::RectangleShape paddle);
};

#endif
