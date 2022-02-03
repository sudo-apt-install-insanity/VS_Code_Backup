#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int n = 0;
    try
    {
        if (n == 0)
        {
            throw n;
        }
    }
    catch (float p)
    {
        cout << "Float Exception catch : Value :" << p;
    }
    catch (...)
    {
        cout << "Default Exception Catch";
    }
    getch();
    return 0;
}