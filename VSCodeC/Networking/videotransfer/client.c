#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#define SIZE 16384

void send_file(FILE *fp, int sockfd)
{
    int n;
    char buffer[SIZE] = {0};

    while (1)
    {
        ssize_t bytesRead = fread(buffer, 1, sizeof(buffer), fp);
        if (bytesRead <= 0)
            break; // EOF

        printf("Read %i bytes from file, sending them to network...\n", (int)bytesRead);
        if (send(sockfd, buffer, bytesRead, 0) != bytesRead)
        {
            perror("[-]Error while sending data!");
            break;
        }
    }
    printf("[+]Data sent successfully.\n");
}

int main(int argc,char * argv[]) // 
{
    char *ip = "192.168.230.231";//10.2.252.81
    int port = 8080;
    int e;

    int sockfd;
    struct sockaddr_in server_addr;
    FILE *fp;
    char *filename = "/home/ainesh/Downloads/payload.mp4";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("[-]Error in socket");
        exit(1);
    }
    printf("[+]Server socket created successfully.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    e = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (e == -1)
    {
        perror("[-]Error in socket");
        exit(1);
    }
    printf("[+]Connected to Server.\n");

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("[-]Error in reading file.");
        exit(1);
    }

    send_file(fp, sockfd);
    printf("[+]File data sent successfully.\n");

    printf("[+]Closing the connection.\n");
    close(sockfd);

    return 0;
}