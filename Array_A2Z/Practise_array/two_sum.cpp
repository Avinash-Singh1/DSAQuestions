
#include <bits/stdc++.h>
using namespace std;
void better(int arr[],int n, int tar){
    unordered_map<int,int> mpp;
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        int more = tar-a;
        if(mpp.find(more) != mpp.end()){
            cout << more << " " << a << endl;
            cout<<"i: "<<i<<" j: "<<mpp[more]<<endl;
        }
        mpp[a]=i;
    }
    
}
void optimised(int arr[],int n, int tar){
    int left= 0; int right=n-1;
    
    while (left<right)
    {
        int sum =arr[left]+arr[right];
        if(sum==tar){
            cout<<"tar found\n";
            cout << arr[left] << " " << arr[right] << endl;
            break;
        }
        else if(sum<tar){
            left++;
        }
        else{
            right--;
        }

    }
    
}
int main(){
   
 int arr[]={2,6,5,8,11};
 int tar=14;
 int n = sizeof(arr)/sizeof(arr[0]);  
   for (int i = 0; i < n; i++)
   {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]+arr[j]==tar){
                cout<<"Pair with sum "<<tar<<" is "<<arr[i]<<" "<<arr[j]<<endl;
                cout<<" i: "<<i<<" j: "<<j<<endl;
                break;
            }
        }
        
   }
   cout<<"Better \n";

   better(arr,n,tar);
   cout<<"optimised \n";

   optimised(arr,n,tar);

   
 return 0;  
}