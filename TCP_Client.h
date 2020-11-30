#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string>
using namespace std;


#ifndef ANT_TCP_CLIENT_H
#define ANT_TCP_CLIENT_H


class TCP_Client {
private:
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;
    char buffer[256];
    char* adresa;
    int port;
public:
    int vytvorSpojenie();
    TCP_Client(char* adresa,int port){
        this->adresa=adresa;
        this->port=port;
    }
    int posliSpravu(int socket, char* sprava);
    char* prijmiSpravu(int socket);
    void zatvorSpojenie();

};


#endif //ANT_TCP_CLIENT_H
