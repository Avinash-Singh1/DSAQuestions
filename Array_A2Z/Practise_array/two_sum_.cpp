
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
   
 int arr[]={0,1,2,0,1,2,1,2,0,0,0,1};
 int tar=14;
 int n = sizeof(arr)/sizeof(arr[0]); 
 map<int,int>mpp;
 for(int i=0;i<n;i++){
    if(arr[i]==0){
        mpp[0]++;
    }else if(arr[i]==1){
    mpp[1]++;

    }
    else{
    mpp[2]++;

    }
 } 

for(auto i :mpp){
    cout<<i.first<<" "<<i.second<<endl;
}
   
 return 0;  
}