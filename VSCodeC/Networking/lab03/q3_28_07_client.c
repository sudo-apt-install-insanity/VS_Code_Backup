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
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = 60018;
    i = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    int n;
    scanf("%d", &n);
    int input[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }
    send(sockfd, &n, 4, 0);
    send(sockfd, &input, n * sizeof(int), 0);
    recv(sockfd, &input, n * sizeof(int), 0);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", input[i]);
    }
    close(sockfd);
}