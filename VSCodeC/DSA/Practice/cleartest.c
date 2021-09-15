#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("\e[1;1H\e[2J");
    printf("3\n");
    sleep(2);

    printf("\e[1;1H\e[2J");
    printf("2\n");
    sleep(2);

    printf("\e[1;1H\e[2J");
    printf("1\n");
    sleep(2);

    printf("\e[1;1H\e[2J");
    printf("0\n");

    return 0;
}