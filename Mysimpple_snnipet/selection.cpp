#include <bits/stdc++.h>
  using namespace std;

void selectionSort(int arr[])
{
    int min;
    for (int i = 0; i < 5; i++)
    {
        min =i;
        for (int j = i+1; j < 5; j++)
        {
            if(arr[j]<arr[min])
            {
                min =j;
            }
           
        }
        
        if(min!= i)
        {
            swap(arr[i] ,arr[min]);
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

  selectionSort(myarray);

  cout << endl << "After Sorting: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }

  return 0;
}