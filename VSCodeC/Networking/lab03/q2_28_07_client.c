#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>

int main(){
    int i, sockfd;
    char buf[100];
    struct sockaddr_in sa;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("10.5.46.25");
    sa.sin_port = 60020;

    i = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));

    int input;
    printf("Enter a number : ");
    scanf("%d",&input);
    printf("Sent from client : %d\n",input);    
    send(sockfd, &input, sizeof(input), 0);
    int num_rec;

    recv(sockfd, &num_rec, sizeof(num_rec), 0);
    printf("Received from server : %d\n",num_rec);

}