#include <iostream>
using namespace std;
#define MAX_SIZE 10

typedef struct{
    int rollno;
    string name;
    char sex;
}info;

class stu_list{
    private:
    info list[MAX_SIZE];
    int f,r;
    public:
    stu_list();
    void insert_at_beg(info);
    void insert_at_end(info);
    void delete_fr_front();
    void delete_fr_rear();
    void print_front();
    void print_rear();
    info get_info();

};
stu_list::stu_list(){
    f = -1;
    r = -1;
}
void stu_list::insert_at_beg(info i) {
   if(f==-1) {
      f=0;
      list[++r] = i;
      cout<<"\n Item inserted.";
   } else if(f!=0) {
      list[--f] = i;
      cout<<"\n Item inserted.";
   } else {
      cout<<"\n Insertion is not possible, overflow!!!";
   }
}
void stu_list::insert_at_end(info i) {
   if(r>=MAX_SIZE-1) {
      cout<<"\n Insertion is not possible, overflow!!!!";
   } else {
      if(f==-1) {
         f++;
         r++;
      } else {
         r=r+1;
      }
      list[r] = i;
      cout<<"\nItem inserted.";
   }
}
void stu_list::delete_fr_front() {
   if(f==-1) {
      cout<<"Deletion is not possible: List empty.";
      return;
   }
   else {
      cout<<"Item deleted.";
      if(f==r) {
         f=r=-1;
         return;
      } else
         f=f+1;
    }
}
void stu_list::delete_fr_rear() {
      if(f==-1) {
         cout<<"Deletion is not possible:List empty";
         return;
      }
      else {
         cout<<"Element deleted.";
         if(f==r) {
            f=r=-1;
         } else
            r=r-1;
      }
}
void stu_list::print_front() {
      if(f==-1) {
         cout<<"List is empty";
      } else {
         for(int i=f;i<=r;i++) {
            cout<<"Student " << i+1 << " -> Name : " << list[i].name << " Roll No. : " << list[i].rollno << " Sex : " << list[i].sex << endl;  ;
         }
      }
}
void stu_list::print_rear() {
      if(f==-1) {
         cout<<"List is empty";
      } else {
         for(int i=r;i>=f;i--) {
            cout<<"Student " << i+1 << " -> Name : " << list[i].name << " Roll No. : " << list[i].rollno << " Sex : " << list[i].sex << endl;  ;
         }
      }
}
info stu_list::get_info(){
    info temp;
    cout << "Enter name : ";
    cin >> temp.name;
    cout << "Enter roll no. : ";
    cin >> temp.rollno;
    cout << "Enter sex : ";
    cin >> temp.sex;
    return temp;
}
int main() {
      int c;
      stu_list student_list;
      info i;
      bool flag = true;
      do { //perform switch opeartion 
      cout<<"\n 1.Insert at beginning";
      cout<<"\n 2.Insert at end";
      cout<<"\n 3.Print from front";
      cout<<"\n 4.Print from rear";
      cout<<"\n 5.Deletion from front";
      cout<<"\n 6.Deletion from rear";
      cout<<"\n 7.Exit";
      cout<<"\n Enter your choice:";
      cin>>c;
      switch(c) {
         case 1:
            i = student_list.get_info();
            student_list.insert_at_beg(i);
         break;
         case 2:
            i = student_list.get_info();
            student_list.insert_at_end(i);
         break;
         case 3:
            student_list.print_front();
         break;
         case 4:
            student_list.print_rear();
         break;
         case 5:
            student_list.delete_fr_front();
         break;
         case 6:
            student_list.delete_fr_rear();
         break;
         case 7:
            flag = false;
         break;
         default:
            cout<<"Invalid choice";
         break;
      }
   }while(flag);
}