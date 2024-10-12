
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {2, 4, 3, 5, 1, 7};
    int n = arr.size();
    vector<int> ans(n,0);


    for (int i = 0; i < n; i++)
    {
        int cnt =0;
        for (int j = 0; j < i; j++)
        {
            if(arr[i]<=arr[j]){
                cnt-=abs(arr[i]-arr[j]);
            }
            else{
                 cnt+=abs(arr[i]-arr[j]);
            }
        }
        ans[i]=cnt;
        
    }

    for(auto i:ans){
        cout<<" "<<i;
    }
    

    return 0;
}