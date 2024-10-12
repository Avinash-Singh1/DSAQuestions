
#include <bits/stdc++.h>
using namespace std;

int main(){
   
 vector<int> arr ={2,6,5,8,11} ;
 int n =5;
 int target =14;
 for (int i = 0; i < n; i++)
 {
    for (int j = i+1; j < n; j++)
    {
        if(arr[i]+arr[j] == target){
            cout<<"index:"<<i<<", "<<j<<endl;
        }
    }
    
 }
 
   
 return 0;  
}