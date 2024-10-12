
#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> &arr, int s, int e){
    while(s<e){
        swap(arr[s],arr[e]);
        // int temp =arr[s];
        // arr[s]=arr[e];
        // arr[e]=temp;
        s++; e--;
    }
}
void OptimalLeftRotate( vector<int> &arr , int n ,int d){
    if(n==0)return ;
    d= d%n;
    cout<<"d: "<<d<<endl;
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);

    for(auto i: arr){
        cout<<i<<" ";
    }

}
int main(){
   
  int n = 7;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 10;

    cout << "Before rotation:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    OptimalLeftRotate(arr, n, d);

    // cout << "After rotation:" << endl;
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;  
   
 return 0;  
}