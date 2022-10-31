#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){
    int sockfd;
    struct sockaddr_in sa;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = 60018;

    connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));

    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    send(sockfd, &num, sizeof(num), 0);

    recv(sockfd, &num, sizeof(num), 0);
    printf("Number recieved from client 2 : %d", num);
    
    close(sockfd);
}