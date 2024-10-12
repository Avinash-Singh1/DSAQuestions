


#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr) {
    int n =arr.size();
   for(int i =0; i<n;i++){
        if(i==0)
        {
            if(arr[i]!=arr[i+1]) return i;
        }
        else if(i == n-1)
        {
            if(arr[i]!=arr[i]-1) return i;
        }
        else{
            if(arr[i]!= arr[i-1] && arr[i]!=arr[i+1])
            {
                return i;
            }
        }
   }
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}

