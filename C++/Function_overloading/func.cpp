
#include <bits/stdc++.h>
using namespace std;
void func(string val="No Parameter")
{
    cout<<"func1: "<<val<<endl;
}
int func(int num)
{
    return num*num;
}
float func(float num,float num2)
{
    return num*num2;
}
string func(string name,string bro)
{
    cout<<"Two string/n";
}
int main(){
   
 int n=10;
 string name="avinash";
 string brother="jawant";

 func();  
 cout<< "get square"<<func(n)<<endl; 
 cout<< "get float"<< func(2.4,4.2)<<endl; 

 func(name,brother);  
   
 return 0;  
}