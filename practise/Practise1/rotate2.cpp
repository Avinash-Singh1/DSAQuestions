
#include <bits/stdc++.h>
using namespace std;

int main(){
   
 vector<int> arr={4,5,62,4,6,8};
 vector<int> temp;
 int n=arr.size();
 int d;
 cout<<"Number of Element to Rotate: "<<endl;
 cin>>d;

 for (int i = 0; i < d; i++)
 {
    temp.push_back(arr[i]);
 }

 for(int i =d;i<n;i++)
 {
    arr[i-d]=arr[i];
 }
 for (int i = n-d; i < n; i++)
 {
    arr[i]=temp[i-(n-d)];
 }
 
 for(auto i: arr)
 {
    cout<<"i: "<<i;
 }
 
   
 return 0;  
}