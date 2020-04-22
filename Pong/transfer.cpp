
#include "transfer.h"

#include <iostream>
#include <fstream>
#include <string>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>

#define BUFLEN 2048
#define MSGS 5


Transfer::Transfer()
{
    short int myport = 8888;

    if ((soc = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("cannot create socket");
    }
    
    struct sockaddr_in myaddr;

    /* bind to an arbitrary return address */
    /* because this is the client side, we don't care about the address */
    /* since no application will initiate communication here - it will */
    /* just send responses */
    /* INADDR_ANY is the IP address and 0 is the socket */
    /* htonl converts a long integer (e.g. address) to a network representation */
    /* htons converts a short integer (e.g. port) to a network representation */

    memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myaddr.sin_port = htons(myport);

    if (bind(soc, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0) {
        perror("bind failed");
    }

    int port = 1153;
    
    struct hostent *hp;     /* host information */
//    struct sockaddr_in servaddr;    /* server address */

    /* fill in the server's address and data */
    memset((char*)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);

    char *host = "192.168.0.20";
    /* look up the address of the server given its name */
    hp = gethostbyname(host);
    if (!hp) {
        fprintf(stderr, "could not obtain address of %s\n", host);
    }

    /* put the host's address into the server address structure */
    memcpy((void *)&servaddr.sin_addr, hp->h_addr_list[0], hp->h_length);

    slen = sizeof(servaddr);

}

ServData Transfer::SendPaddleDataAndUpdate(ServData& cd)
{
    float buf[BUFLEN];
    
    long recvlen;
    
    float data[] = { cd.a, cd.b, cd.c, cd.d, cd.e };

    if (sendto(soc, data, 20, 0, (struct sockaddr *)&servaddr, slen) < 0) {
        perror("sendto failed");
    }
    recvlen = recvfrom(soc, buf, BUFLEN, 0, (struct sockaddr *)&servaddr, &slen);
    if (recvlen >= 0) {
        buf[recvlen] = 0;
//        printf("%f\n", buf[0]);
    }
    return { buf[0], buf[1], buf[2], buf[3], buf[4] };
}

