
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {4, 5, 0, 4, 6, 0, 0, 8};
    vector<int> temp;
    int n = arr.size();

   int j = 0;
   for (int i = 0; i < n; i++)
   {
        if (arr[i] == 0){
            j=i;
            break;
        }
   }

   for (int i = j+1; i < n; i++)
   {
    if(arr[i]!=0)
    {
        swap(arr[i],arr[j]);
        j++;
    }
   }

   for (int i = 0; i < n; i++)
   {
    cout<<" "<<arr[i]<<endl;
   }
   
   
   
    return 0;
}