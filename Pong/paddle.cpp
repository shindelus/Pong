

#include "paddle.h"

Paddle::Paddle(float xpos, float ypos, bool isC)
{
    Xposition = xpos;
    Yposition = ypos;
    height = 140;
    width = 20;
    isComputer = isC;
    Yspeed = 20.0f;
    isMovingUp = false;
    isMovingDown = false;
}
