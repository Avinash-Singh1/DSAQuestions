
#include <bits/stdc++.h>
using namespace std;
int getMaximumEvenSum(vector<int> arr, int n)
{
    int Even_sum =0; int n =arr.size();
    for(int i=0; i<n;i++)
    {
        if(arr[i]>0){
            Even_sum+=arr[i];
        }
    }

    if(Even_sum%2==0)
    {
        return Even_sum;
    }

    // if sum is not even convert it to even by adding odd pos or neg number
    int ans=INT_MIN;
    for(int i=0; i<n;i++){
        if(arr[i]%2 !=0)
        {
            if(arr[i]>0)
            {
                ans=max(ans,Even_sum+arr[i]);

            }else{
                ans=max(ans,Even_sum+arr[i]);
            }
        }
    }

}
int main()
{

    vector<int> arr = {-1, -2, -3, 8, 7};
    int n = 5;
    cout << getMaximumEvenSum(arr, n);
    return 0;
}