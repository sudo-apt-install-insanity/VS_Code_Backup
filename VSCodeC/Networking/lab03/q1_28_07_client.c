#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int i, sockfd;
    char buf[100];
    struct sockaddr_in sa;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("10.5.46.25");
    sa.sin_port = 60018;

    i = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));

    for (int j = 0; j < 5; j++)
    {
        char input[100];
        scanf("%s", input);

        strcpy(buf, input);
        send(sockfd, buf, 100, 0);

        recv(sockfd, buf, 100, 0);
        if (strcmp(buf, "bye") == 0)
        {
            printf("CLIENT: %s\n", buf);
            break;
        }
        printf("CLIENT: %s\n", buf);
    }

    close(sockfd);
}