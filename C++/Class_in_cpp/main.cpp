
#include <bits/stdc++.h>
using namespace std;

class myclass{
    public:
    int myNum;
    string myString;
    myclass(){
        this->myNum=56;
        this->myString="avinash singh";
    }
    void myfunction(){
        cout<<"Wlcome to myfunction inside c++"<<endl;
    }

};

class Car {
  public:
    string brand;   
    string model;
    int year;
    int mycarcost();
    int CarSpeed(int speed);
};
int Car::mycarcost(){
    return 10000;
}
int Car::CarSpeed(int speed){
    return speed*2;
}


int main(){
  myclass obj;
  cout<<obj.myNum<<endl<<obj.myString<<endl;

   // Create another object of Car
  Car carObj2;
  carObj2.brand = "Ford";
  carObj2.model = "Mustang";
  carObj2.year = 1969;

  // Print attribute values
//   cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
  cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
  cout << carObj2.brand << " " << carObj2.mycarcost() << "\n";
 // calling function of myclass function
 cout<<"calling function of myclass function"<<endl;
 obj.myfunction();

 int speed=300;
cout<< carObj2.CarSpeed(speed)<<endl;
    
   
 return 0;  
}