
#include <bits/stdc++.h>
using namespace std;
void reversearr(int arr[],int s, int l)
{
    if(s>=l)
    {
        return ;
    }
    else{
        swap(arr[s],arr[l]);
        reversearr(arr,s+1,l-1);
    }

}
void reversearr2(int arr2[],int s)
{ 
 int n =4;

    if(s>=n-s)
    {
        return ;
    }
    else{
        swap(arr2[s],arr2[n-s]);
        reversearr2(arr2,s+1);
    }

}
int main(){
   
 int arr[]={5,2,56,85,4};  
 reversearr(arr, 0,4);
   for(auto it: arr)
   {
    cout<<it<<" ";
   }
   cout<<endl;

 int arr2[]={15,25,56,85,40};  
 reversearr2(arr2, 0);
   for(auto it: arr2)
   {
    cout<<it<<" ";
   }

 return 0;  
}