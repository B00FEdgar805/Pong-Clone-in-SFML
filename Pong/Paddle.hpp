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

class Paddle
{
private:
    const int PADDLE_SPEED = 5;
    
public:
    sf::RectangleShape  PADDLE;
    Paddle();
    ~Paddle();
    void Render(sf::RenderWindow &Window);
    void checkBounds();
    void paddleMovements();
    void cpuLogic(sf::RectangleShape Ball);
};



#endif /* Paddle_hpp */
