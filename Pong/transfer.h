#pragma once

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>

struct BallPos
{
    float x, y;
};

class Transfer
{
public:
    int soc;
    struct sockaddr_in servaddr;
    socklen_t slen;
    Transfer();
    ~Transfer(){};
    BallPos SendPaddleDataAndUpdate(float pos[]);
};
