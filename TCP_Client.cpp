#include "TCP_Client.h"

int TCP_Client::vytvorSpojenie() {

    server = gethostbyname(this->adresa);
    if (server == NULL) {
        fprintf(stderr, "Server sa nenašiel\n");
        return 2;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(
            (char *) server->h_addr,
            (char *) &serv_addr.sin_addr.s_addr,
            server->h_length
    );
    serv_addr.sin_port = htons(this->port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Nepodarilo sa vytvorit socket");
        return 3;
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Nepodarilo sa pripojit k socketu");
        return 4;
    }
    return sockfd;
}

char* TCP_Client::prijmiSpravu(int socket) {
    char* sprava;
    n = read(socket, sprava, 255);
    if (n < 0) {
        perror("Nepodarilo sa citat zo socketu");
        return nullptr;
    }
    return sprava;
}

int TCP_Client::posliSpravu(int socket, char* sprava){
    n = write(socket, sprava, strlen(sprava));
    if (n < 0) {
        perror("Nepodarilo sa citat zo socketu");
        return 4;
    }
    return 0;
}

void TCP_Client::zatvorSpojenie() {
    close(sockfd);
}

