
#include <bits/stdc++.h>
using namespace std;

int main(){
   
 vector<int> arr={2,6,5,8,12};
 int n=arr.size();
 int target =13;
 int a =0; 
 int more=0;
 map<int,int> mpp;
 for(int i=0;i<n;i++){
     a =arr[i];
    cout<<"a: "<<a<<endl;
     more = target - a;
    if(mpp.find(more)!= mpp.end()){
        cout<<"indexes of result "<< mpp[more]<<" "<<i<<endl;
    }
    mpp[a]=i;
 }
   
 return 0;  
}