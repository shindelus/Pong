#pragma once

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>

struct ServData
{
    // a is action
    // if a = 1, update score and level
    // b = score1
    // c = score2
    // d = level
    // e = message
    // if a = 0, update ball and paddle positions
    // b = ballX
    // c = ballY
    // d = paddle1Y
    // e = paddle2Y
    float a, b, c, d, e;
};


class Transfer
{
public:
    int soc;
    struct sockaddr_in servaddr;
    socklen_t slen;
    Transfer();
    ~Transfer(){};
    ServData SendPaddleDataAndUpdate(ServData& cd);
};
