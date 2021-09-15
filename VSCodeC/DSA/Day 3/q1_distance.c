#include <stdio.h>
#include <stdlib.h>
typedef struct distance{
    int kilometres_1482;
    int metres_1482;
} distance;
int add(distance* ,distance* );

int main(){
    distance *d1_1482 , *d2_1482;
    d1_1482 = (distance *)malloc(sizeof(distance));
    d2_1482 = (distance *)malloc(sizeof(distance));
    printf("Enter first distance in km and m : ");
    scanf("%d%d",&d1_1482->kilometres_1482,&d1_1482->metres_1482);
    printf("Enter second distance in km and m : ");
    scanf("%d%d",&d2_1482->kilometres_1482,&d2_1482->metres_1482);
    add(d1_1482,d2_1482);
}
int add(distance *d1,distance *d2){
    int km , m;
    km = d1->kilometres_1482 + d2->kilometres_1482;
    m = d1->metres_1482 + d2->metres_1482;
    if (d1->metres_1482+d2->metres_1482 >= 1000) {
        m -= 1000;
        km++;
    }
     
    printf("Total distance is : %d km and %d m.",km,m);
}