
#include <bits/stdc++.h>
using namespace std;
void func(string name ="avinash"){
    cout<<"name: "<<name;
}
void swapval(int& x,int& y)
{
    int temp = x;
    x =y;
    y = temp;
}
void chage_arrayVal(int arr[])
{
    arr[2]=89;

}
int main(){
   
 string s = "pizza"  ;
 string *s2 = &s;
 cout << *s2 << endl;
//  func("jaswant"); cout<<"\n";
//  func();
int x =5;
int y= 15;
// cout << x << " " << y << endl;
swapval(x,y);
// cout << x << " " << y << endl;
int arr[]={3,4,5,6,7};
cout<<"original Array: \n";
for(auto i:arr){
    cout<<i<<" ";
}
cout<<"\nUpdated Array: \n";

chage_arrayVal(arr);
for(auto i:arr){
    cout<<i<<" ";
}

   
 return 0;  
}