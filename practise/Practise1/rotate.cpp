

#include <bits/stdc++.h>
using namespace std;
void myFunction(int arr[], int n ,int d){

    reverse(arr,0,d);
    reverse(arr,0+d,n);
    reverse(arr,0,n);
    
}
void reverse(int arr[], int start, int end){

    
    while (start<=end)
    {
        int temp= arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }

}
int main(){

    int arr[7]={1,2,3,4,5,6,7};
    int n=7;
    int d =3;

    myFunction(arr,n,d);
   
 return 0;  
}