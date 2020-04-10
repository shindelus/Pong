
#include "ball.h"


Ball::Ball()
{
    speed = 17.0f;
    direction = 10;
    Xspeed = speed * Xangle[direction];
    Yspeed = speed * Yangle[direction];
    Xposition = 100.0f;
    Yposition = 387.5f;
    height = 25.0f;
    width = 25.0f;
}
