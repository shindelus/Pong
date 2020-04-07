

#include "paddle.h"

Paddle::Paddle(float xpos, float ypos, bool isC)
{
    Xposition = xpos;
    Yposition = ypos;
    Yspeed = 20.0f;
    height = 140;
    width = 20;
    isComputer = isC;
    isMovingUp = false;
    isMovingDown = false;
}
