#include <iostream>
#include <conio.h>

using namespace std;

class ballot
{
    int candidate; //candidate you want to create for voting
    int vote[50];
    int ballot[3];
    static int spballot; //spoil ballot
public:
    void getdisplay(void);
};
int ballot :: spballot;
void ballot ::getdisplay(void)
{
    cout << "\n\n\nEnter how many candidate you want to make:-";
    cin >> candidate;

    static int a, b, c;
    a = b = c = 0;

    cout << "\nEnter 1-3 Integers\n";
    for (int i = 0; i < candidate; i++)
    {
        cin >> vote[i];
        switch (vote[i])
        {
        case 1:
            ballot[a];
            a++;
            break;
        case 2:
            ballot[b];
            b++;
            break;
        case 3:
            ballot[c];
            c++;
            break;
        default:
            ++spballot;
        }
    }

    //for displaying
    int choice;
    bool flag = true;
    do
    {
        cout << "Choices Available" << endl;
        cout << "1)  Scored By Ballot A" << endl;
        cout << "2)  Scored By Ballot B" << endl;
        cout << "3)  Scored By Ballot C" << endl;
        cout << "4)  Spoilt Ballot" << endl;
        cout << "5)  Exit" << endl;

        cin >>choice;
        switch (choice)
        {
        case 1:
            cout << "Scored By Ballot A is "<<a << endl;
                break;
        case 2:
            cout <<"Scored By Ballot B is "<<b << endl;
                break;
        case 3:
            cout <<"Scored By Ballot C is "<<c << endl;
                break;
        case 4:
            cout <<"Spoil Ballot were "<<spballot << endl;
                break;
        case 5:
            flag = false;
        }
    } while (flag);
}

int main()
{
    ballot o1;
    o1.getdisplay();
}