#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>

int main(){
    int sockfd, fd1, length, i;
    char buf[100];
    struct sockaddr_in sa, ta1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = INADDR_ANY;
    sa.sin_port = 60020;

    i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    printf("test %d%d\n", sockfd, i);

    listen(sockfd, 5);

    length = sizeof(sa);

    fd1 = accept(sockfd, (struct sockaddr *)&ta1, &length);

    int num_rec;
    recv(fd1,&num_rec, sizeof(num_rec), 0);
    printf("Received from client : %d\n",num_rec);
    int temp = num_rec;
    int rev;
    while(temp > 0){
        rev = rev*10 + temp%10;
        temp = temp/10;
    }
    send(fd1, &rev, sizeof(rev), 0);

}