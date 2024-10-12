#include <bits/stdc++.h>
using namespace std;

int partitionFun(int arr[], int s, int e) {
  int pivot = arr[e];
  int pindex= s;
  for (int i = s; i < e; i++)
  {
    if(arr[i]<=pivot)
    {
      swap(arr[i],arr[pindex]);
      pindex++;
    }
  }
      swap(arr[e],arr[pindex]);
  return pindex;
}

/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void QuickSort(int arr[], int s, int e) {
    int p;
    if(s<e)
    {
        p =partitionFun(arr,s,e);
        QuickSort(arr,e,p-1);
        QuickSort(arr,p+1,e);
        
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
  QuickSort(myarray, 0, (arr_size - 1)); // mergesort(arr,left,right) called

  cout << "After Sorting" << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }

  return 0;
}