#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r) {
 int i =l; int j = m+1; int k =l;
 int temp[5]={0};
 while (i <= m && j <= r) {
     if (arr[i] <= arr[j]) 
        {
            temp[k] = arr[i];
            k++; 
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++; j++;
        }
              
 }
   while (i<=m)
        {
            temp[k]=arr[i];
            k++;
            i++;
        }
         while (j<=r)
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
        for (int i = l; i <= r; i++) {
            arr[i] = temp[i];
        }
}

/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
    int mid;
    if(l<r)
    {
        mid =(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main() {
  int myarray[5]={56, 68, 9, 1, 44};
  //int arr_size = sizeof(myarray)/sizeof(myarray[0]);
  int arr_size = 5;

//   cout << "Enter 5 integers in any order: " << endl;
//   for (int i = 0; i < 5; i++) {
//     cin >> myarray[i];
//   }

  cout << "Before Sorting" << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }
  cout << endl;
  mergeSort(myarray, 0, (arr_size - 1)); // mergesort(arr,left,right) called

  cout << "After Sorting" << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }

  return 0;
}