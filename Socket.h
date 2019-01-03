#pragma once
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>


int init_socket() {
    int my_sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "127.0.0.1", &hint.sin_addr);
    int res = bind(my_sock, (sockaddr *) &hint, sizeof(hint));
    listen(my_sock, SOMAXCONN);
    sockaddr_in client;
    socklen_t clientsize = sizeof(client);
    int client_sock = accept(my_sock, (sockaddr*) &client, &clientsize);
    close(my_sock);
    return client_sock;
}


void close_socks(int client_socket){
    close(client_socket);
}