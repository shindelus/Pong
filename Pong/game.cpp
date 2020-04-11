#include <iostream>
#include "game.h"

void Game::CheckForLeftCollision(Paddle& p, Ball& b)
{
    bool ballWithinVertWindow = b.Yposition + b.height > p.Yposition && b.Yposition < p.Yposition + p.height;
    bool ballWithinHorizWindow = b.Xposition + b.width < p.Xposition && b.Xposition + b.speed + b.width > p.Xposition;
    if (ballWithinVertWindow && ballWithinHorizWindow && b.Xspeed > 0)
    {
            
        if (p.isMovingUp && !p.isComputer && !curve)
        {
            curve = true;
            clockWiseCurve = false;
            curveCountdown = 2;
            
        } else if (p.isMovingDown && !p.isComputer && !curve)
        {
            curve = true;
            clockWiseCurve = true;
            curveCountdown = 2;
        }
        b.Xposition = p.Xposition - b.width;
        b.Xspeed = - b.Xspeed;
        clockWiseCurve = !clockWiseCurve;
        
        printf("--------HIT RIGHT----------\n");
        
    }
};

void Game::CheckForRightCollision(Paddle& p, Ball& b)
{
    bool ballWithinVertWindow = b.Yposition + b.height > p.Yposition && b.Yposition < p.Yposition + p.height;
    bool ballWithinHorizWindow = b.Xposition > p.Xposition + p.width && b.Xposition + b.Xspeed < p.Xposition + p.width;
    if (ballWithinVertWindow && ballWithinHorizWindow && b.Xspeed < 0)
    {
        b.Xposition = p.Xposition + p.width;
        b.Xspeed = -b.Xspeed;
        printf("---------HIT LEFT----------\n");
        
        if (curve)
        {
            clockWiseCurve = !clockWiseCurve;
        }

    }


};

void Game::CheckForTopCollision(Paddle& p, Ball& b)
{
    bool ballWithinVertWindow = b.Yposition > p.Yposition + p.height && b.Yposition + b.speed < p.Yposition + p.height;
    bool ballWithinHorizWindow = b.Xposition + b.width > p.Xposition && b.Xposition < p.Xposition + p.width;
    if (ballWithinVertWindow && ballWithinHorizWindow && b.Yspeed < 0)
    {
        b.Yposition = p.Yposition + p.height;
        b.Yspeed = -b.Yspeed;
    }
};

void Game::CheckForBottomCollision(Paddle& p, Ball& b)
{
    bool ballWithinVertWindow = b.Yposition + b.height < p.Yposition && b.Yposition + b.speed + b.height > p.Yposition;
    bool ballWithinHorizWindow = b.Xposition + b.width > p.Xposition && b.Xposition < p.Xposition + p.width;
    if (ballWithinVertWindow && ballWithinHorizWindow && b.Yspeed > 0)
    {
        b.Yposition = p.Yposition - b.height;
        b.Yspeed = -b.Yspeed;
    }
};

void Game::CheckForCollisions(Paddle& p1, Paddle& p2, Ball& b)
{
    CheckForTopCollision(p1, b);
    CheckForTopCollision(p2, b);
    CheckForLeftCollision(p2, b);
    CheckForRightCollision(p1, b);
};

bool Game::BallIsOutRight(Ball& b)
{
    if (b.Xposition + b.width + b.Xspeed > windowWidth)
    {
        return true;
    }
    return false;
};

bool Game::BallIsOutLeft(Ball& b)
{
    if (b.Xposition + b.Xspeed < 0.0f)
    {
        return true;
    }
    return false;
};

void Game::CheckForBallYBounds(Ball& b)
{
    if (b.Yposition + b.height + b.Yspeed > windowHeight - 60.0f && b.Yspeed > 0)
    {
        b.Yposition = windowHeight - b.height - 60.0f;
        b.Yspeed = - b.Yspeed;
        b.direction = 26 - b.direction;
        printf("--------HIT TOP----------\n");


    } else if (b.Yposition + b.Yspeed < 0.0f && b.Yspeed < 0)
    {
        b.Yposition = 0.0f;
        b.Yspeed = - b.Yspeed;
        b.direction = 26 - b.direction;
        printf("--------HIT BOTTOM--------\n");


    }
};

bool Game::isPaddleAtTop(Paddle& p)
{
    if (p.Yposition + p.height + p.Yspeed > windowHeight - 60.0f)
    {
        p.Yposition = windowHeight - p.height - 60.0f;
        return true;
    }
    return false;
};

bool Game::isPaddleAtBottom(Paddle& p)
{
    if (p.Yposition - p.Yspeed < 0.0f)
    {
        p.Yposition = 0.0f;
        return true;
    }
    return false;
};

void Game::MoveComputerPaddle(Paddle& p, Ball& b)
{
    if (p.isComputer)
    {
        if (p.Yspeed != b.Yspeed || p.Yspeed != -b.Yspeed)
        {
            if (b.Yspeed > 0)
            {
                p.Yspeed = b.Yspeed;
                
            } else {
                p.Yspeed = - b.Yspeed;
            }
        }
        
        if (currentCompDelay < 0.0f)
            currentCompDelay = 0.0f;
        
        if (compWaiting && currentCompDelay == 0)
        {
            compWaiting = false;
            compDelay = compDelay + 0.3f;
            
        } else if (currentCompDelay > 0)
        {
            currentCompDelay = currentCompDelay - 1.0f;
            return;
        }
        
        if (b.Yposition > windowHeight - p.height)
        {
            if (!p.isMovingUp)
            {
                compWaiting = true;
                currentCompDelay = compDelay;
                p.isMovingUp = true;
                p.isMovingDown = false;
            } else {
                p.Yposition = windowHeight - 60.0f - p.height;
            }
        } else if (b.Yposition + (b.height/2.0f) > p.Yposition + (p.height/2.0f))
        {
            if (!p.isMovingUp)
            {
                compWaiting = true;
                currentCompDelay = compDelay;
                p.isMovingUp = true;
                p.isMovingDown = false;
            } else {
                p.Yposition = p.Yposition + p.Yspeed;
            }
        } else if (b.Yposition < p.height - 60.0f)
        {
            if (!p.isMovingDown)
            {
                compWaiting = true;
                currentCompDelay = compDelay;
                p.isMovingUp = false;
                p.isMovingDown = true;
            } else {
                p.Yposition = 0.0f;
            }
        } else if (b.Yposition + (b.height/2.0f) < p.Yposition + (p.height/2.0f))
        {
            if (!p.isMovingDown)
            {
                compWaiting = true;
                currentCompDelay = compDelay;
                p.isMovingUp = false;
                p.isMovingDown = true;
            } else {
                p.Yposition = p.Yposition - p.Yspeed;
            }
        }
    }
};

void Game::MovePaddleUp(Paddle& p)
{
    if (!isPaddleAtTop(p))
    {
        p.Yposition = p.Yposition + p.Yspeed;
    }
};

void Game::MovePaddleDown(Paddle& p)
{
    if (!isPaddleAtBottom(p))
    {
        p.Yposition = p.Yposition - p.Yspeed;
    }
};

void Game::CheckBallDirection(Ball& b)
{
    
    if (curve && curveCountdown > 0)
    {
        curveCountdown--;
        return;
    }
    
    if (curve && curveCountdown == 0)
    {
        
        if (b.Xspeed > 0 && clockWiseCurve && b.direction < 26)
        {
            b.direction++;
            
        } else if (b.Xspeed > 0 && !clockWiseCurve && b.direction > 0)
        {
            b.direction--;
            
        } else if (b.Xspeed < 0 && clockWiseCurve && b.direction < 26)
        {
            b.direction++;
            
        } else if (b.Xspeed < 0 && !clockWiseCurve && b.direction > 0)
        {
            b.direction--;
        }
        
                
        if (b.direction > 13)
        {
            b.Yspeed = - b.speed * b.Yangle[b.direction];
            
        } else {
            b.Yspeed = b.speed * b.Yangle[b.direction];
        }
        
        
        
        if (b.Xspeed > 0 && b.speed > 0)
        {
            b.Xspeed = b.speed * b.Xangle[b.direction];
            
        } else if (b.speed > 0)
        {
            b.Xspeed = - b.speed * b.Xangle[b.direction];
            
        } else if (b.speed < 0 && b.speed < 0)
        {
            b.Xspeed = b.speed * b.Xangle[b.direction];
            
        } else {
            
            b.Xspeed = - b.speed * b.Xangle[b.direction];
        }
        
        curveCountdown = 6;
    }
};

void Game::MoveBall(Paddle& p1, Paddle& p2, Ball& b)
{
    CheckBallDirection(b);
    CheckForBallYBounds(b);
        
    if (BallIsOutLeft(b))
    {
        player2Score++;
        if (player2Score == 1)
        {
            level++;
            b.speed = b.speed + 3.0f;
        }
        ResetLevel(p1, p2, b);
        
    } else if (BallIsOutRight(b))
    {
        player1Score++;
        if (player1Score == 7)
        {
            level = 1;
            ResetGame(p1, p2, b);
        } else {
            ResetLevel(p1, p2, b);
        }
    } else {
        b.Xposition = b.Xposition + b.Xspeed;
        b.Yposition = b.Yposition + b.Yspeed;
    }
};

void Game::ResetLevel(Paddle& p1, Paddle& p2, Ball& b)
{
    p1.Yposition = (windowHeight/2.0f) - 70.0f;
    p2.Yposition = (windowHeight/2.0f) - 70.0f;
    b.Xposition = 100.0f;
    b.Yposition = 387.5f;
    b.speed = 17.0f;
    b.direction = 10;
    b.Xspeed = b.speed * b.Xangle[b.direction];
    b.Yspeed = b.speed * b.Yangle[b.direction];
    countDownToStart = 200.0f;
    currentCompDelay = 0;
    compDelay = 0;
    curve = false;
    clockWiseCurve = false;
};

void Game::ResetGame(Paddle& p1, Paddle& p2, Ball& b)
{
    player1Score = 0;
    player2Score = 0;
    level = 1;
    ResetLevel(p1, p2, b);
    compDelay = 0.0f;
};

void Game::OnUpdate(Paddle& p1, Paddle& p2, Ball& b)
{
    if (curve && curveCountdown == 0 && countDownToStart == 0)
    {
        printf("CLOCKWISE --- %d\n", clockWiseCurve);
        printf("DIRECTION --- %d\n", b.direction);
        printf("COUNTDOWN --- %d\n", curveCountdown);
        printf("----------------\n");
    }

    if (countDownToStart != 0)
    {
        countDownToStart--;
    } else {
        CheckForCollisions(p1, p2, b);
        MoveComputerPaddle(p1, b);
        MoveComputerPaddle(p2, b);
        MoveBall(p1, p2, b);
    }
};

Game::Game(float& wH, float& wW)
{
    player1Score = 0;
    player2Score = 0;
    level = 1;
    windowHeight = wH;
    windowWidth = wW;
    countDownToStart = 200.0f;
    compDelay = 0;
    currentCompDelay = 0;
    compWaiting = false;
    curve = false;
    clockWiseCurve = false;
}
