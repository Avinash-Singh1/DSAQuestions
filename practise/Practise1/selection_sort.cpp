#include <bits/stdc++.h>
  using namespace std;

void insertionSort(int arr[]) {
    int minn =0;
 for (int i = 0; i < 5; i++)
 {
    minn =i;
    for (int j = i+1; j < 5; j++)
    {
        if(arr[j]<arr[minn])
        {
            minn =j;
        }

    }
    swap(arr[i],arr[minn]);
    // 64 25 12 22 11
 }
 

}

int main() {
  int myarray[5];
  cout << "Enter 5 integers in any order" << endl;
  for (int i = 0; i < 5; i++) {
    cin >> myarray[i];
  }

  cout << "Before Sorting: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }

  insertionSort(myarray);

  cout << endl << "After Sorting: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }

  return 0;
}