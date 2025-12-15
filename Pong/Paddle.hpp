//
//  Player.hpp
//  Pong
//
//  Created by Edgar Alamillo on 12/12/25.
//  Copyright © 2025 Edgar Alamillo. All rights reserved.
//

#ifndef Paddle_hpp
#define Paddle_hpp

#include "SFML/Graphics.hpp"
#include <memory>
#include <iostream>

class Paddle
{
private:
    const int PADDLE_SPEED = 5;
    
public:
    sf::RectangleShape  PADDLE;
    Paddle();
    ~Paddle();
   // void setPosition(float x, float y);
    void Render(sf::RenderWindow &Window);
    void checkBounds();
    void paddleMovements();
    void cpuLogic();
};



#endif /* Paddle_hpp */
