
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
      int arr[] = {1, 2, 3, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);


    // int sum = 0;
    int targ = 12;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         for (int k = i; k < j; k++)
    //         {
    //             sum += arr[i];
    //             if (sum == targ)
    //             {
    //                 cout << "sum is " << sum << " at index " << i << " " << j << " " << k << endl;
    //                 break;
    //             }
    //         }
    //     }
    // }

    // better
    // for (int i = 0; i < n; i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < n; j++)
    //     {

    //         sum += arr[i];
    //         if (sum == targ)
    //         {
    //             cout << "sum is " << sum << " at index " << i << " " << j << " " << endl;
    //             break;
    //         }
    //     }
    // }

    // optimal code
    // int k =9;

    unordered_map<int,int> mpp;
    int sum = 0;
    int maxlength=0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        if(sum==targ){
            cout<<"index: "<<i+1<<endl;
        }

        if(mpp.find(sum-targ)!=mpp.end())
        {
            maxlength=max(maxlength,i-mpp[sum-targ]);
        }

        if(mpp.find(sum)!= mpp.end()){
            mpp[sum]=i;
        }
    }
    cout<<"maxlength "<<maxlength<<endl;
    return 0;
}