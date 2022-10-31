#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct data {
    int roll;
    char name[30];
    int marks[5];
} data;

int main(){
    FILE *fp = fopen("data.txt", "r");
    int sockfd,fd1,length,i;

    data list[3];
    for(int i=0;i<3;i++){
        fscanf(fp,"%d", &list[i].roll);
        fscanf(fp,"%s", list[i].name);
        for(int j=0;j<5;j++)
            fscanf(fp,"%d", &list[i].marks[j]);
    }
    fclose(fp);

    struct sockaddr_in sa,ta1;
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

    int roll_no;
    recv(fd1, &roll_no, sizeof(roll_no), 0);

    for(i=0;i<3;i++){
        if(list[i].roll == roll_no){
            send(fd1, &list[i], sizeof(data), 0);
            break;
        }
    }
    close(fd1);


}
