#pragma once
#include <iostream>
#include <string>
#include "ball.h"
#include "paddle.h"
#include "vertices.h"
#include "transfer.h"


class Game
{
public:
    int player1Score;
    int player2Score;
    int level;
    int angleChangeCountdown;
    int countDownToStart;
    int online;
    int onlineP;
    float compDelay;
    float currentCompDelay;
    float windowHeight;
    float windowWidth;
    float rIncrement;
    float gIncrement;
    float bIncrement;
    float red;
    float green;
    float blue;
    float redHi;
    float redLo;
    float blueHi;
    float blueLo;
    float greenHi;
    float greenLo;
    float messageNum;
    float messageNeedsUpdate;
    int messageUpdateCountdown;
    int curveCountdown;
    int playCountdown;
    float IP;
    std::string message;
    bool compWaiting;
    bool curve;
    bool clockWiseCurve;
    bool levelUp;
    bool lost;
    bool p1Scored;
    bool p2Scored;
    bool waitingForOpponent;
    bool playing;
    bool connected;
    
    
    Game(float& wH, float& wW);
    ~Game(){};
    
    bool BallIsOutLeft(Ball& b);
    bool BallIsOutRight(Ball& b);
    bool isPaddleAtTop(Paddle& p);
    bool isPaddleAtBottom(Paddle& p);
    void CheckForCollisions(Paddle& p1, Paddle& p2, Ball& b);
    void CheckForLeftCollision(Paddle& p, Ball& b);
    void CheckForRightCollision(Paddle& p, Ball& b);
    void CheckForTopCollision(Paddle& p, Ball& b);
    void CheckForBottomCollision(Paddle& p, Ball& b);
    void CheckForBallYBounds(Ball& b);
    void ResetLevel(Paddle& p1, Paddle& p2, Ball& b);
    void ResetGame(Paddle& p1, Paddle& p2, Ball& b);
    void OnUpdate(Paddle& p1, Paddle& p2, Ball& b, Transfer& t);
    void MovePaddleUp(Paddle& p);
    void MovePaddleDown(Paddle& p);
    void MoveComputerPaddle(Paddle& p, Ball& b);
    void MoveBall(Paddle& p1, Paddle& p2, Ball& b);
    void CheckBallDirection(Ball& b);
    void AddTextForOffline(Vertices& v);
    void AddTextForOnline(Vertices& v);
    void CreateBall(float left, float bottom, float width, float height, Vertices& v);
    void UpdateColor();
    void ChangeColor();
    void CheckPaddleMovement(Paddle& p1, Paddle& p2, Transfer& t);
};
