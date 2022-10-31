#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
void bubbleSort(int arr[], int n)
{
    printf("\nSorting the array ....");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
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
    int n;
    recv(fd1, &n, 4, 0);
    int input[n];
    recv(fd1, &input, n * sizeof(int), 0);
    printf("\nReceived the array ...");
    bubbleSort(input, n);
    send(fd1, &input, n * sizeof(int), 0);
    close(fd1);
}