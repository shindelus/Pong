#pragma once

#include <iostream>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>

struct ClientData
{
    float a, b;
};

struct ServerData
{
    float a, b, c, d, e, f, g, h, i, j, k;
};

class Transfer
{
public:
    std::string hostIP;
    int soc;
    struct sockaddr_in servaddr;
    socklen_t slen;
    Transfer();
    ~Transfer(){};
    ServerData SendDataAndUpdate(ClientData& cd);
};
