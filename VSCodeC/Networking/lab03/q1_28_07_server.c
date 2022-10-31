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
    sa.sin_port = 60018;

    i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    printf("test %d%d\n", sockfd, i);

    listen(sockfd, 5);

    length = sizeof(sa);

    fd1 = accept(sockfd, (struct sockaddr *)&ta1, &length);



	for (int j = 0; j < 5; j++)
    {
        recv(fd1, buf, 100, 0);
        if(strcmp(buf,"exit") == 0){
            for (i = 0; i < 100; i++)
            buf[i] = '\0';
            break;
        }
	    printf("SERVER : %s\n", buf);
        strcat(buf,": from server");

        send(fd1,buf,100,0);
        for (i = 0; i < 100; i++)
            buf[i] = '\0';
    }
    strcpy(buf,"bye");
    send(fd1,buf,100,0);
    
    close(fd1);
}