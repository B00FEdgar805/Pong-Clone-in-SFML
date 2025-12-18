/*
 Remake of of the classic game Pong built using SFML 2.6.2
 This Version uses only one olayer and you face a CPU
 It can be easily changed to 2 players by sepreating the conterols in paddle movements and
 and replacing the cpu logic with 2nd player movements in update
 Controls are up arrow / W for up and down arrow / S for down
 */

#include "Game.hpp"

int main()
{
    Game game;
    game.Run();
   
}
