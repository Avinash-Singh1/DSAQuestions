
#include <bits/stdc++.h>
using namespace std;

int main(){
   
   vector<int> arr ={0,1,2,0,1,2,1,2,0,0,0,1};
   int cout0,count1,cout2=0;

   for (int i = 0; i < arr.size(); i++)
   {
        if(arr[i]==0)
        {
         cout0++;
        }else if(arr[i]==1){
            count1++;
        }
        else
        {
            cout2++;
        }
   }

  
  
   

   

   
   
 return 0;  
}