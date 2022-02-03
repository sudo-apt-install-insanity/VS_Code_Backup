#include <iostream>
using namespace std;

class player{
    int number;
    string name;
    int score;

    friend ostream &operator << (ostream &out , const player &p);
    friend istream &operator >> (istream &in , player &p);
};
ostream &operator << (ostream &out , const player &p){
        out << "PLayer number -> " << p.number << endl;
        out << "PLayer name -> " << p.name << endl;
        out << "PLayer score -> " << p.score << endl;
}
istream &operator >> (istream &in , player &p){
        cout << "Enter number : "; 
        in >> p.number;
        cout << "Enter name : "; 
        in >> p.name;
        cout << "Enter score : "; 
        in >> p.score;
        return in;
}

int main(){
    player p;
    cin >> p;
    cout <<p;
}