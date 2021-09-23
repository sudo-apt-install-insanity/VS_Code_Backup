#include <stdio.h>
#include <string.h>
#include <time.h>
#define ESC 27
#define SPACE 32
#define TAB 9

struct system
{
    char username[20];
    char password[20];
}sys;

void delay(int);
void signup();
void login();

void main()
{
    char ch;
    do{
        
        printf("\e[1;1H\e[2J");
        printf("\n\n\n\n\n\n");
        printf("\t****************************************");
        printf("****************************************");
        printf("\n\n\t\t\tWELCOME TO LOGIN DETAILS ");
        printf("\n\t\t\tPress SPACE For Login");
        printf("\n\t\t\tPress TAB For Signup");
        printf("\n\t\t\tPress ESC For Exit");
        printf("\n\n\n\t**************************************************************************");
        delay(1);
    
        ch = getch();   
        switch(ch)
        {
            case SPACE:
                printf("\n\n\n\tProcessing..................................................................................");
                delay(1);
                login();
                break;
            case TAB:
                printf("\n\n\n\tProcessing..................................................................................");
                delay(1);
                signup();
                break;
            case ESC:
                printf("\n\n\n\tEXITING ..........\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                exit(0);
                break;

        }
    }while(ch != ESC);  
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}

void signup()
{
    printf("\e[1;1H\e[2J");
    char c;
    printf("\n\n\n\n\n\n");
    printf("\t****************************************");
    printf("****************************************");
    printf("\n\n\n\t\t\t!!!!!!!!!!   READY FOR SIGNUP   !!!!!!!!!!");
    printf("\n\n\t\t\t:::::::::  ENTER YOUR DETAILS  ::::::::: \n\n");
    printf("\n\t\t\t****************************************\n");

    printf("\n\t\t\t\t SET  USERNAME\t  :\t");
    gets(sys.username);
    printf("\n\n\t\t\t\t SET  PASSSWORD\t  :\t");
    gets(sys.password);
    printf("\n\t\t\t\t********************** DETAILS SAVED SUCCESSFULLY ***********************");   
}

void login()
{
    printf("\e[1;1H\e[2J");
    char c = '+';
    int j;
    char user[20];
    char pass[20];
    int check_user;
    int check_pass;
    printf("\n\n\n\n\n\n");
    printf("\t****************************************");
    printf("****************************************");
    printf("\n\n\n\t\t\t\t!!!!!!!!!   READY FOR LOGIN   !!!!!!!!!");
    printf("\n\n\t\t\t\t:::::::::  ENTER THE DETAILS   :::::::::\n\n");
    printf("\n\t\t\t\t****************************************\n");    
    do
    {
    printf("\n\t\t\t\t ENTER  USERNAME\t:\t");
    gets(user);
    j = strcmp(sys.username, user);
    }while(j!=0);
    printf("\n\t\t\t\t ENTER  PASSWORD\t:\t"); 

    int i=0;
    while(c!=13)
    {
        c = getch();
        if(c == 13)
            break;
        printf("*");
        pass[i] = c;
        i++;        
    }
 
    check_user = strcmp(sys.username, user);
    check_pass = strcmp(sys.password, pass);
    printf("\e[1;1H\e[2J");
    // printf("pass : %s",sys.password);
    // printf(" user : %s", sys.username);
    // printf("\npass : %s",pass);
    // printf(" user : %s", user);
    // printf("\ncheck pass : %d", check_pass);
    // printf(" check user : %d", check_user);
    printf("\n\n\n\n\n\n");
    if(check_user != 0 && check_pass != 0)
    {
        printf("\n\t\t\t\t****************************************\n");
        printf("\n\n\t\t\t\t\tINVALID USERNAME AND PASSWORD\n\t\t\t\t\t\tTRY AGAIN\n");
        printf("\n\t\t\t\t****************************************\n");
    }
    else if(check_user != 0 && check_pass == 0)
    {
        printf("\n\t\t\t\t****************************************\n");
        printf("\n\t\t\t\t\t  INVALID USERNAME\n\t\t\t\t\t      TRY AGAIN\n");
        printf("\n\t\t\t\t****************************************\n");       
    }
    else if(check_user == 0 && check_pass != 0)
    {
        printf("\n\t\t\t\t****************************************\n");
        printf("\n\t\t\t\t\t  INVALID PASSWORD\n\t\t\t\t\t      TRY AGAIN\n");
        printf("\n\t\t\t\t****************************************\n");       
    }
    else
    {

        printf("\n\t\t\t\t****************************************\n");
        printf("\n\t\t\t\t\tLOGGED IN SUCCESSFULLY\n\t\t\t\t\tYOU ARE WELCOME %s\n", user);
        printf("\n\t\t\t\t****************************************\n");       
    }
}

void delay(int sec)
{
    int ms = 1000 * sec;
    clock_t start = clock();
    while(clock() < start + ms);
}