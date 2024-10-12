
#include <bits/stdc++.h>
using namespace std;

int main(){
   
 vector<int>  arr={2,4,3};
int n =3;
vector<int> ans;
 for(int i =0; i<n;i++){
    int cnt=0;
    for(int j = 0; j<i;j++){
        if(arr[i]>arr[j]){
            cnt=cnt+abs(arr[i]-arr[j]);
        }
        else{
            cnt=cnt-abs(arr[i]-arr[j]);
        }
    }
    ans.push_back(cnt);
 }

 for(auto i :ans){
    cout<<i<<" ";
 }
   
 return 0;  
}