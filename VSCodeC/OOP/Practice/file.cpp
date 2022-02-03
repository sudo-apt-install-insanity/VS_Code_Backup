#include <iostream>
using namespace std;
class Doctor
{
    int age;
    string name, speciality, contact, address;

public:
    Doctor() {}
    Doctor(int age, string name, string speciality, string contact, string address)
    {
        this->age = age;
        this->name = name;
        this->speciality = speciality;
        this->contact = contact;
        this->address = address;
    }

    void show_data()
    {
        cout << "Name: " << this->name << endl;
        cout << "age: " << this->age << endl;
        cout << "speciality: " << this->speciality << endl;
        cout << "Contact number: " << this->contact << endl;
        cout << "Address: " << this->address << endl;
    }

    void edit_data()
    {
        cout << "\nEnter Details of the Doctor :"<< endl;
        cout << "\nName : " << endl;
        cin >> name;
        cout << "Age : " << endl;
        cin >> age;
        cout << "Speciality : " << endl;
        cin >> speciality;
        cout << "Contact Number : " << endl;
        cin >> contact;
        cout << "Address : " << endl;
        cin >> address;
        Doctor(age, name, speciality, contact, address);
    }
};
int main()
{
    int n;
    cout << "Enter value of n : ";
    cin >> n;
    Doctor *doctors = new Doctor[n];
    int age;
    string name, speciality, contact, address;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Details of the Doctor " << i + 1 << ":"<< endl;
        cout << "\nName : " << endl;
        cin >> name;
        cout << "Age : " << endl;
        cin >> age;
        cout << "Speciality : " << endl;
        cin >> speciality;
        cout << "Contact Number : " << endl;
        cin >> contact;
        cout << "Address : " << endl;
        cin >> address;
        doctors[i] = Doctor(age, name, speciality, contact, address);
    }
    cout << "Displaying Details of the doctor : \n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nDoctor " << i + 1 << endl;
        doctors[i].show_data();
    }
    return 0;
}