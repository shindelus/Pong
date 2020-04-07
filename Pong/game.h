#include "ball.h"
#include "paddle.h"


class Game
{
public:
    int player1Score;
    int player2Score;
    float windowHeight;
    float windowWidth;
    float countDownToStart;
    
    Game(float& wH, float& wW);
    ~Game(){};
    
    void CheckForXCollision(Paddle& p, Ball& b);
    void CheckForYCollision(Paddle& p, Ball& b);
    void CheckForBallXBounds(Ball& b);
    void CheckForBallYBounds(Ball& b);
    void CheckForPaddleYBounds(Paddle& p);
    void ResetLevel(Paddle& p1, Paddle& p2, Ball& b);
    void ResetGame(Paddle& p1, Paddle& p2, Ball& b);
    void OnUpdate(Paddle& p1, Paddle& p2, Ball& b);
    void MovePaddleUp(Paddle& p);
    void MovePaddleDown(Paddle& p);
    void MoveComputerPaddle(Paddle& p);
    void MoveBall(Ball& b);
};
