#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#define SIZE 16384

void write_file(int sockfd)
{
    int n;
    FILE *fp;
    char *filename = "recv.mp4";
    char buffer[SIZE];

    fp = fopen(filename, "w");

    char buf[SIZE];
    while (1)
    {
        ssize_t bytesReceived = recv(sockfd, buf, sizeof(buf), 0);
        if (bytesReceived < 0)
            perror("recv"); // network error?
        if (bytesReceived == 0)
            break; // sender closed connection, must be end of file

        printf("Received %i bytes from network, writing them to file...\n", (int)bytesReceived);
        if (fwrite(buf, 1, bytesReceived, fp) != (size_t)bytesReceived)
        {
            perror("fwrite");
            break;
        }
    }

    fclose(fp);
    return;
}

int main()
{
    int port = 8080;
    int e;

    int sockfd, new_sock;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("[-]Error in socket");
        exit(1);
    }
    printf("[+]Server socket created successfully.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    e = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (e < 0)
    {
        perror("[-]Error in bind");
        exit(1);
    }
    printf("[+]Binding successfull.\n");

    if (listen(sockfd, 10) == 0)
    {
        printf("[+]Listening....\n");
    }
    else
    {
        perror("[-]Error in listening");
        exit(1);
    }

    addr_size = sizeof(new_addr);
    new_sock = accept(sockfd, (struct sockaddr *)&new_addr, &addr_size);
    write_file(new_sock);
    printf("[+]Data written in the file successfully.\n");

    return 0;
}