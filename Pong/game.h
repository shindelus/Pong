#include "ball.h"
#include "paddle.h"


class Game
{
public:
    int player1Score;
    int player2Score;
    int level;
    float windowHeight;
    float windowWidth;
    float countDownToStart;
    
    Game(float& wH, float& wW);
    ~Game(){};
    
    void CheckForCollisions(Paddle& p1, Paddle& p2, Ball& b);
    void CheckForLeftCollision(Paddle& p, Ball& b);
    void CheckForRightCollision(Paddle& p, Ball& b);
    void CheckForTopCollision(Paddle& p, Ball& b);
    void CheckForBottomCollision(Paddle& p, Ball& b);
    bool BallIsOutLeft(Ball& b);
    bool BallIsOutRight(Ball& b);
    void CheckForBallYBounds(Ball& b);
    bool isPaddleAtTop(Paddle& p);
    bool isPaddleAtBottom(Paddle& p);
    void ResetLevel(Paddle& p1, Paddle& p2, Ball& b);
    void ResetGame(Paddle& p1, Paddle& p2, Ball& b);
    void OnUpdate(Paddle& p1, Paddle& p2, Ball& b);
    void MovePaddleUp(Paddle& p);
    void MovePaddleDown(Paddle& p);
    void MoveComputerPaddle(Paddle& p, Ball& b);
    void MoveBall(Paddle& p1, Paddle& p2, Ball& b);
};
