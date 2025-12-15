#ifndef Game_hpp
#define Game_hpp

#include "Paddle.hpp"

class Game
{
private:
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const int BALL_VELOCITY = 6;
    float BALL_X = 1.f;
    float BALL_Y = 1.f;
    int PLAYER_ONE_SCORE = 0;
    int PLAYER_TWO_SCORE = 0;
   // std::unique_ptr<Paddle> PLAYER_ONE;
    //std::unique_ptr<Paddle> PLAYER_TWO;
    Paddle PLAYER_ONE;
    Paddle PLAYER_TWO;
    sf::RenderWindow *WINDOW;
    sf::RectangleShape BALL;
    sf::Font font;
    sf::Text text;
    
public:
    Game();
    ~Game();
    void Run();
    void Render();
    void Update();
    void ballPhysics();
    void initText();
    void initScreen();
    void resetBall();
    void gameLogic(bool win);
};

#endif
