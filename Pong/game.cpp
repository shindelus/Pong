
#include "game.h"

void Game::CheckForLeftCollision(Paddle& p, Ball& b)
{
    bool ballWithinVertWindow = b.Yposition + b.height > p.Yposition && b.Yposition < p.Yposition + p.height;
    bool ballWithinHorizWindow = b.Xposition + b.width < p.Xposition && b.Xposition + b.speed + b.width > p.Xposition;
    if (ballWithinVertWindow && ballWithinHorizWindow && b.Xspeed > 0)
    {
        b.Xposition = p.Xposition - b.width;
        b.Xspeed = -b.Xspeed;
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
    } else if (b.Yposition + b.Yspeed < 0.0f && b.Yspeed < 0)
    {
        b.Yposition = 0.0f;
        b.Yspeed = - b.Yspeed;
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
        if (b.Yposition > windowHeight - 60.0f - (p.height/2.0f) - (b.height/2) - b.Yspeed)
        {
            p.Yposition = windowHeight - 60.0f - p.height;
            
        } else if (b.Yposition < (p.height/2.0f) - (b.height/2.0f) + b.Yspeed)
        {
            p.Yposition = 0.0f;
            
        } else if (b.Yposition + (b.height/2.0f) > p.Yposition + (p.height/2.0f))
        {
            p.Yposition = p.Yposition + p.Yspeed;
            
        } else if (b.Yposition + (b.height/2.0f) < p.Yposition + (p.height/2.0f))
        {
            p.Yposition = p.Yposition - p.Yspeed;
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

void Game::MoveBall(Paddle& p1, Paddle& p2, Ball& b)
{
    CheckForBallYBounds(b);
    if (BallIsOutLeft(b))
    {
        player2Score++;
        if (player2Score == 7)
        {
            level++;
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
    b.speed = 20.0f;
    b.Xspeed = 10.0f;
    b.Yspeed = 10.0f;
    countDownToStart = 200.0f;
};

void Game::ResetGame(Paddle& p1, Paddle& p2, Ball& b)
{
    player1Score = 0;
    player2Score = 0;
    level = 1;
    ResetLevel(p1, p2, b);
};

void Game::OnUpdate(Paddle& p1, Paddle& p2, Ball& b)
{
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
}
