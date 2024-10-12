#include <bits/stdc++.h>
using namespace std;

void mergeAll(int arr[], int l, int m, int r) {
 int i=l; int j=m+1; int k=l; int temp[6]={0};
//  cout<<"i: "<<i<<" m: "<<m<<" r: "<<r<<endl;
  while(i<=m && j<= r)
 {
    if(arr[i]<=arr[j])
    {
        temp[k]=arr[i];
        i++; k++;
    }
    else
    {
        temp[k]=arr[j];
        j++; k++;
    }
 }
 while (i<=m)
 {
     temp[k]=arr[i];
    i++; k++;
 }

 while (j<=r)
 {
    temp[k]=arr[j];
    j++; k++;
 }
 for (int i = l; i <=r; i++)
 {
    arr[i]=temp[i];
 }
 
 
}

/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
    int mid;
    if(l<r)
    {
        mid= (l+r)/2;
        cout<<"L :"<<l<<" r: "<<r<<"midL "<<mid<<endl;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        mergeAll(arr,l,mid,r);
    }
}

int main() {
  int myarray[6]={56,1, 68, 9, 1, 44};
  int arr_size = sizeof(myarray)/sizeof(myarray[0]);
//   int arr_size = 6;
cout<<"arr_size: "<<arr_size<<endl;

//   cout << "Enter 5 integers in any order: " << endl;
//   for (int i = 0; i < 5; i++) {
//     cin >> myarray[i];
//   }

  cout << "Before Sorting" << endl;
  for (int i = 0; i < 6; i++) {
    cout << myarray[i] << " ";
  }
  cout << endl;
  mergeSort(myarray, 0, 6-1); // mergesort(arr,left,right) called

  cout << "After Sorting" << endl;
  for (int i = 0; i < 6; i++) {
    cout << myarray[i] << " ";
  }

  return 0;
}