
#include <bits/stdc++.h>
using namespace std;
class Student{
    public:
    string name;
    string roll;
    int age;
    Student(){
        name="avinash singh";
        roll="ac-1255";
        age=21;
    }
    Student(string name1, string roll1, int age1){
        name=name1;
        roll=roll1;
        age=age1;
    }
    
};
int main(){
    Student s1;
    cout<<"name: "<<s1.name<<" roll: "<<s1.roll<<" age: "<<s1.age;
    // Student s1,s2("Jaswant singh", "ac-1256", 25);

   
   
   
 return 0;  
}