#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MYPORT 4952 // the port users will be connecting to
#define MAXBUFLEN 200
int main()
{
    int sockfd;
    struct sockaddr_in my_addr;    // my address information
    struct sockaddr_in their_addr; // connector's address information
    socklen_t addr_len;
    int numbytes;
    int n1, n2;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }
    my_addr.sin_family = AF_INET;         // host byte order
    my_addr.sin_port = htons(MYPORT);     // short, network byte order
    my_addr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP
    // memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr) == -1)
    {
        perror("bind");
        exit(1);
    }
    addr_len = sizeof their_addr;
    recvfrom(sockfd, &n1, sizeof(int), 0, (struct sockaddr *)&their_addr, &addr_len);
    recvfrom(sockfd, &n2, sizeof(int), 0, (struct sockaddr *)&their_addr, &addr_len);
    printf("got packet from %s\n", inet_ntoa(their_addr.sin_addr));
    // printf("sum is = %d", n1 + n2);
    int sum = n1+n2;
    sendto(sockfd, &sum, sizeof(int), 0, (struct sockaddr *)&their_addr, (socklen_t)sizeof their_addr);
    printf("Sum is : %d ",sum);
    close(sockfd);
    return 0;
}