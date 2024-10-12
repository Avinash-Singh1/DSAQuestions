
#include <bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int> arr, int n, int k){
     int l = 0; int h = n-1;
     while(l<=h){
        int mid = (l+h)/2;
        if(arr[mid]== k){
            return mid;
           
        }
        else if(arr[mid]<k)
        {
            l= mid+1;
        }
        else{
             h= mid-1;
        }
     }
     
}
int recusiveBS(vector<int> arr,int low, int high, int k)
{ 
    if( low >high) return -1;
    int mid =(low+high)/2;
    if(arr[mid]==k) {
        return mid;
    }
    else if(arr[mid]>k){
        high =mid-1;
       return recusiveBS(arr,low, high,k);
    }
    else{
        // <=
        low =mid+1;
        return recusiveBS(arr,low,high,k);
    }

}
int main(){
   
//  vector<int> arr={32,45,3,1,90,5,3,} ;
 vector<int> arr={1,3,5,32,45,90} ;
 int n =arr.size();
 
cout<< BinarySearch(arr,n, 90)<<endl;
cout<< recusiveBS(arr, 0,n-1,45);

 return 0;  
}