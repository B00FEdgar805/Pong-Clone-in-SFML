
#include "Paddle.hpp"

Paddle::Paddle()
{
    PADDLE.setSize(sf::Vector2f(20.f,140.f));
}

Paddle::~Paddle()
{
    
}

/*
void Paddle::setPosition(float x, float y)
{
    PADDLE.setPosition(x,y);
}
*/
void Paddle::paddleMovements()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        PADDLE.move(0.f, -1.f * PADDLE_SPEED);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        PADDLE.move(0.f, 1.f * PADDLE_SPEED);
    }
}

void Paddle::checkBounds()
{
    if(PADDLE.getPosition().y < 0 )
    {
        PADDLE.setPosition(PADDLE.getPosition().x, 0);
    }
    
    if(PADDLE.getPosition().y + 140.f > 720.f)
    {
        PADDLE.setPosition(PADDLE.getPosition().x, 580.f);
    }
}


void Paddle::cpuLogic()
{
 //   if()
    {
        
    }
}


void Paddle::Render(sf::RenderWindow &Window)
{
    Window.draw(PADDLE);
}
