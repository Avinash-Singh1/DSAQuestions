
#include <bits/stdc++.h>
using namespace std;
void MOveZerosOptimised(vector<int> arr)
{
    int i,j;
    int n = arr.size();
   for (int itr = 0; itr < n; itr++)
   {
        if(arr[itr]==0)
        {
            j=itr;
            break;
        }
   }
   cout<<"First Z: "<<j<<endl;
   for ( i = j+1; i < n; i++)
   {
    if(arr[i]!=0)
    {
        swap(arr[i],arr[j]);
        j++;
    }
   }

   for(auto i: arr)
   {
    cout<<" i"<<i<<" ";
   }
   
   
   
    
}
int main()
{

    vector<int> arr = {4, 5, 0, 4, 6, 0, 0, 8};
    vector<int> temp;
    int n = arr.size();

    // int nonz = 0;
    // for (auto i : arr)
    // {
    //     if (i != 0)
    //     {
    //         nonz++;
    //         temp.push_back(i);
    //     }
    // }
    // int z = n - nonz;
    // for (int i = 0; i < z; i++)
    // {
    //     temp.push_back(0);
    // }
    
   
    // for (auto i : temp)
    // {
    //     cout << " I: " << i << endl;
    // }
    MOveZerosOptimised(arr);

    return 0;
}