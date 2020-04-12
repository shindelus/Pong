#include <iostream>
#include <math.h>
#include "game.h"
#include "word.h"
#include "vertices.h"

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

    } else if (b.Yposition + b.Yspeed < 0.0f && b.Yspeed < 0)
    {
        b.Yposition = 0.0f;
        b.Yspeed = - b.Yspeed;
        b.direction = 26 - b.direction;

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

void Game::AddText(Vertices& v)
{

    if (p1Scored && !lost)
    {
        message = "computer scores";
        p1Scored = false;
        countDownToStart = 300.0f;
    }
    if (p2Scored && !levelUp)
    {
        message = " player scores ";
        p2Scored = false;
        countDownToStart = 300.0f;
    }
    if (lost)
    {
        message = "   you lose   ";
        lost = false;
        countDownToStart = 300.0f;
    }
    if (levelUp)
    {
        message = "    you win    ";
        levelUp = false;
        countDownToStart = 300.0f;
    }

    
    if (countDownToStart > 200.0f && countDownToStart <= 300.0f)
    {
        Word w(message, 400.0f, 380.0f, 50.0f, v);
        levelUp = false;
        p1Scored = false;
        p2Scored = false;
        lost = false;
    }
    if (countDownToStart > 150.0f && countDownToStart <= 200.0f)
    {
        Word w("start", 570.0f, 380.0f, 50.0f, v);

    } else if (countDownToStart > 100.0f && countDownToStart <= 150.0f)
    {
        Word w("3", 650.0f, 380.0f, 50.0f, v);

    } else if (countDownToStart > 50.0f && countDownToStart <= 100.0f)
    {
        Word w("2", 650.0f, 380.0f, 50.0f, v);

    } else if (countDownToStart > 0.0f && countDownToStart <= 50.0f)
    {
        Word w("1", 650.0f, 380.0f, 50.0f, v);
    }
    
    std::stringstream p1ScoreStr;
    p1ScoreStr << player1Score;
    Word scoreP1(p1ScoreStr.str(), 30.0f, windowHeight - 45.0f, 35.0f, v);
    
    std::stringstream p2ScoreStr;
    p2ScoreStr << player2Score;
    Word scoreP2(p2ScoreStr.str(), windowWidth - 50.0f, windowHeight - 45.0f, 35.0f, v);
    
    std::stringstream levelStr;
    levelStr << level;
    Word level("level " + levelStr.str(), (windowWidth/2) - 75.0f, windowHeight - 45.0f, 35.0f, v);

    Vertex vertices[v.m_vertData.size()];
    std::copy(v.m_vertData.begin(), v.m_vertData.end(), vertices);
}

void Game::CreateBall(float left, float bottom, float width, float height, Vertices& v)
{
    
    float dia = 25.0f;
    float angle = 5.0f;
    while (angle < 90.0f)
    {
        float rad = angle * (3.14159f / 180.0f);
        float horiz = sin(rad) * dia;
        float vert = cos(rad) * dia;
        float l = (dia - horiz) / 2;
        float b = (dia - vert) / 2;
        float w = horiz;
        float h = vert;
        v.AddVertData(left + l, bottom + b, w, h);
        angle = angle + 5.0f;
    }
}

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
        p2Scored = true;
        if (player2Score == 7)
        {
            level++;
            player1Score = 0;
            player2Score = 0;
            levelUp = true;
            b.speed = b.speed + 2.0f;
            player2Score = 0;
        }
        ResetLevel(p1, p2, b);
        
    } else if (BallIsOutRight(b))
    {
        player1Score++;
        p1Scored = true;
        if (player1Score == 7)
        {
            level = 1;
            lost = true;
            ResetGame(p1, p2, b);
        } else {
            ResetLevel(p1, p2, b);
        }
    } else {
        b.Xposition = b.Xposition + b.Xspeed;
        b.Yposition = b.Yposition + b.Yspeed;
    }
};

void Game::ChangeColor()
{
    if (red > redHi)
        rIncrement = -0.03f;
    else if (red < redLo)
        rIncrement = 0.03f;
    red += rIncrement;

    if (green > greenHi)
        gIncrement = -gIncrement;
    else if (green < greenLo)
        gIncrement = -gIncrement;
    green += gIncrement;

    if (blue > blueHi)
        bIncrement = -bIncrement;
    else if (blue < blueLo)
        bIncrement = -bIncrement;
    blue += bIncrement;
};

void Game::UpdateColor()
{
    if (level == 1)
    {
        redHi =    0.8f;
        redLo =    0.3f;
        red =      0.8f;
        greenHi =  0.1f;
        greenLo =  0.1f;
        green =    0.1f;
        blueHi =   1.0f;
        blueLo =   1.0f;
        blue =     1.0f;
        rIncrement = 0.005f;
        gIncrement = 0.0f;
        bIncrement = 0.0f;
    } else if (level == 2)
    {
        redHi =    0.0f;
        redLo =    0.0f;
        red =      0.0f;
        greenHi =  1.0f;
        greenLo =  0.5f;
        green =    1.0f;
        blueHi =   1.0f;
        blueLo =   0.5f;
        blue =     0.5f;
        rIncrement = 0.00f;
        gIncrement = 0.03f;
        bIncrement = 0.03f;
    } else if (level == 3)
    {
        redHi =    1.0f;
        redLo =    0.5f;
        red =      0.5f;
        greenHi =  1.0f;
        greenLo =  0.5f;
        green =    1.0f;
        blueHi =   0.0f;
        blueLo =   0.0f;
        blue =     0.0f;
        rIncrement = 0.02f;
        gIncrement = 0.02f;
        bIncrement = 0.00f;
    } else if (level == 4)
    {
        redHi =    1.0f;
        redLo =    0.0f;
        red =      0.0f;
        greenHi =  1.0f;
        greenLo =  0.0f;
        green =    1.0f;
        blueHi =   1.0f;
        blueLo =   1.0f;
        blue =     1.0f;
        rIncrement = 0.03f;
        gIncrement = 0.03f;
        bIncrement = 0.00f;
    } else if (level == 5)
    {
        redHi =    0.9f;
        redLo =    0.3f;
        red =      0.9f;
        greenHi =  0.4f;
        greenLo =  0.4f;
        green =    0.4f;
        blueHi =   0.4f;
        blueLo =   0.4f;
        blue =     0.4f;
        rIncrement = 0.01f;
        gIncrement = 0.0f;
        bIncrement = 0.0f;
    } else if (level == 6)
    {
        redHi =    0.1f;
        redLo =    0.1f;
        red =      0.1f;
        greenHi =  0.8f;
        greenLo =  0.3f;
        green =    0.8f;
        blueHi =   1.0f;
        blueLo =   1.0f;
        blue =     1.0f;
        rIncrement = 0.0f;
        gIncrement = 0.01f;
        bIncrement = 0.0f;
    } else if (level == 7)
    {
        redHi =    0.9f;
        redLo =    0.9f;
        red =      0.9f;
        greenHi =  0.6f;
        greenLo =  0.3f;
        green =    0.6f;
        blueHi =   0.1f;
        blueLo =   0.1f;
        blue =     0.1f;
        rIncrement = 0.0f;
        gIncrement = 0.02f;
        bIncrement = 0.0f;
    } else if (level == 8)
    {
        redHi =    1.0f;
        redLo =    1.0f;
        red =      1.0f;
        greenHi =  0.4f;
        greenLo =  0.1f;
        green =    0.4f;
        blueHi =   0.1f;
        blueLo =   0.1f;
        blue =     0.1f;
        rIncrement = 0.0f;
        gIncrement = 0.02f;
        bIncrement = 0.0f;
    } else
    {
        redHi =    0.8f;
        redLo =    0.3f;
        red =      0.8f;
        greenHi =  0.8f;
        greenLo =  0.3f;
        green =    0.8f;
        blueHi =   1.0f;
        blueLo =   1.0f;
        blue =     1.0f;
        rIncrement = 0.03f;
        gIncrement = 0.03f;
        bIncrement = 0.0f;
    }
}

void Game::ResetLevel(Paddle& p1, Paddle& p2, Ball& b)
{
    p1.Yposition = (windowHeight/2.0f) - 70.0f;
    p2.Yposition = (windowHeight/2.0f) - 70.0f;
    b.Xposition = 100.0f;
    b.Yposition = 387.5f;
    b.direction = 10;
    b.Xspeed = b.speed * b.Xangle[b.direction];
    b.Yspeed = b.speed * b.Yangle[b.direction];
    currentCompDelay = 0;
    compDelay = 0.0f;
    curve = false;
    clockWiseCurve = false;
    UpdateColor();
};

void Game::ResetGame(Paddle& p1, Paddle& p2, Ball& b)
{
    player1Score = 0;
    player2Score = 0;
    level = 1;
    ResetLevel(p1, p2, b);
    compDelay = 0.0f;
    countDownToStart = 200.0f;
};

void Game::CheckPaddleMovement(Paddle& p)
{
    if (p.isMovingUp)
    {
        MovePaddleUp(p);
    } else if (p.isMovingDown)
    {
        MovePaddleDown(p);
    }
}

void Game::OnUpdate(Paddle& p1, Paddle& p2, Ball& b)
{
    ChangeColor();
    CheckPaddleMovement(p2);
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
    compDelay = 0.0f;
    currentCompDelay = 0;
    compWaiting = false;
    curve = false;
    clockWiseCurve = false;
    levelUp = false;
    lost = false;
    p1Scored = false;
    p2Scored = false;
    redHi =    0.8f;
    redLo =    0.3f;
    red =      0.8f;
    greenHi =  0.1f;
    greenLo =  0.1f;
    green =    0.1f;
    blueHi =   1.0f;
    blueLo =   1.0f;
    blue =     1.0f;
    rIncrement = 0.005f;
    gIncrement = 0.0f;
    bIncrement = 0.0f;
}
