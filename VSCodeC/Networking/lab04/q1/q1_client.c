#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


typedef struct data {
    int roll;
    char name[30];
    int marks[5];
} data;

int main(){
    int sockfd;
    struct sockaddr_in sa;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = 60018;

    connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));

    int roll_no;
    printf("Enter roll no: ");
    scanf("%d", &roll_no);
    send(sockfd, &roll_no, sizeof(roll_no), 0);
    
    data d;
    recv(sockfd, &d, sizeof(data), 0);

    printf("Roll no: %d\n", d.roll);
    printf("Name: %s\n", d.name);
    printf("Marks: ");
    for(int i=0; i<5; i++)
        printf("%d ", d.marks[i]);
    printf("\n");
    close(sockfd);
    

}