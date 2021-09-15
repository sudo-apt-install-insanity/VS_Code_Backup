#include <iostream>
using namespace std;
void cycle(int *,int *,int *);
int main(){
    int a,b,c;
    cin >> a >> b >> c ;
    cout << "A = " << a << " B = " << b << " C = " << c << endl;
    cycle(&a,&b,&c);
    cout << "A = " << a << " B = " << b << " C = " << c << endl;
}
void cycle(int *a,int *b,int *c){
    int temp = *c;
    *c = *b;
    *b = *a;
    *a = temp;
}