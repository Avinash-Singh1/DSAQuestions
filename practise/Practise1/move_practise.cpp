

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {4, 5, 0, 4, 6, 0, 0, 8};
    vector<int> temp;
    int n = arr.size();

   for (int i = 0; i < n; i++)
   {
    if(arr[i]!= 0)
    {
        temp.push_back(arr[i]);
    }
   }
   int zeros = n-temp.size();
   for (int i = 0; i < zeros; i++)
   {
    temp.push_back(0);
   }
   cout << "Array after moving zeros: "<<endl;
   for(auto i : temp)
   {
    cout<<" "<<i<<" ";
   }
   
   
   
    

    return 0;
}