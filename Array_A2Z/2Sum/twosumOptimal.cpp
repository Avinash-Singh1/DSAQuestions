
#include <bits/stdc++.h>
using namespace std;

int main(){
   
 vector<int> arr ={2,6,5,8,11} ;
 int n =5;
 int target =14;

int left = 0;
int right = n-1;
sort(arr.begin(),arr.end());

while(left <right){
    int sum = arr[left]+arr[right];
    if(sum == target){
        cout<<"yes";
        break;
    }
    else if(sum<target){
        left++;
    }
    else{
        right--;
    }
}

 return 0;  
}