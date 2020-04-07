
#include "game.h"

void Game::CheckForXCollision(Paddle& p, Ball& b)
{
    
};

void Game::CheckForYCollision(Paddle& p, Ball& b)
{
    
};

void Game::CheckForBallXBounds(Ball& b)
{
    
};

void Game::CheckForBallYBounds(Ball& b)
{

};

void Game::CheckForPaddleYBounds(Paddle& p)
{
    
};

void Game::MoveComputerPaddle(Paddle& p)
{
    if (p.isComputer)
    {
    
    }
};

void Game::MovePaddleUp(Paddle& p)
{
    p.Yposition = p.Yposition + p.Yspeed;
};

void Game::MovePaddleDown(Paddle& p)
{
    p.Yposition = p.Yposition - p.Yspeed;
};

void Game::MoveBall(Ball& b)
{
    CheckForBallXBounds(b);
    CheckForBallYBounds(b);
    b.Xposition = b.Xposition + b.Xspeed;
    b.Yposition = b.Yposition + b.Yspeed;
};

void Game::ResetLevel(Paddle& p1, Paddle& p2, Ball& b)
{
    
};

void Game::ResetGame(Paddle& p1, Paddle& p2, Ball& b)
{
    
};

void Game::OnUpdate(Paddle& p1, Paddle& p2, Ball& b)
{
    if (countDownToStart != 0)
    {
        countDownToStart--;
    } else {
        MoveComputerPaddle(p1);
        MoveComputerPaddle(p2);
        MoveBall(b);
    }
};

Game::Game(float& wH, float& wW)
{
    player1Score = 0;
    player2Score = 0;
    windowHeight = wH;
    windowWidth = wW;
    countDownToStart = 200.0f;
}
