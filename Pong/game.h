#include "ball.h"
#include "paddle.h"


class Game
{
public:
    int player1Score;
    int player2Score;
    int level;
    int angleChangeCountdown;
    float compDelay;
    float currentCompDelay;
    float windowHeight;
    float windowWidth;
    float countDownToStart;
    int curveCountdown;
    bool compWaiting;
    bool curve;
    bool clockWiseCurve;
    
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
    void OnUpdate(Paddle& p1, Paddle& p2, Ball& b);
    void MovePaddleUp(Paddle& p);
    void MovePaddleDown(Paddle& p);
    void MoveComputerPaddle(Paddle& p, Ball& b);
    void MoveBall(Paddle& p1, Paddle& p2, Ball& b);
    void CheckBallDirection(Ball& b);
};
