#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int sockfd,fd1,fd2,length,i;

    struct sockaddr_in sa,ta1,ta2;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = INADDR_ANY;
    sa.sin_port = 60018;

    i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));

    printf("test %d%d",sockfd,i);
    fflush(stdout);

    listen(sockfd, 5);
    length = sizeof(sa);
    fd1 = accept(sockfd, (struct sockaddr *)&ta1, &length);
    fd2 = accept(sockfd, (struct sockaddr *)&ta2, &length);

    int fromc1,fromc2;

    recv(fd1, &fromc1, sizeof(fromc1), 0);
    recv(fd2, &fromc2, sizeof(fromc2), 0);


    send(fd1, &fromc2, sizeof(fromc2), 0);
    send(fd2, &fromc1, sizeof(fromc1), 0);

    close(fd1);
    close(fd2);

}