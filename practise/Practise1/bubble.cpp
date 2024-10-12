#include <bits/stdc++.h>
  using namespace std;

void insertionSort(int arr[]) {
 
for(int i =0;i<5;i++)
    for (int j = 0; j < 5; j++)
    {
        if(arr[j]>arr[j+1])
        {
            int temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]= temp;
            
        }
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