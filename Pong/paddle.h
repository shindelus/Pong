#pragma once

class Paddle
{
public:
    bool isComputer;
    float Xposition;
    float Yposition;
    float Yspeed;
    int width;
    int height;
    Paddle(float xpos, float ypos, bool isC);
    ~Paddle(){};
};
