
#include <bits/stdc++.h>
using namespace std;


int SearchEleemnt(vector<int> arr, int l, int h, int tar)
{
    // int last = 0;
    while (l <= h)
    {

        int mid = l + (h - l) / 2;
        if(arr[l]==arr[mid] && arr[mid] == arr[h]){
            continue;
        }
        if(arr[mid]==tar) return mid;
        // left sorted
        else if (arr[l] <= arr[mid])
        {
           if(arr[l]< tar && tar < arr[mid])
           {
            h= mid-1;
           }
           else{
            l =mid+1;
           }
        }
        else
        {
             if(arr[mid]<tar && tar < arr[h]){
                l = mid+1;
             }
             else{
                h = mid-1;
             }
            
        }
    }
    // return last;
}


int main()
{

    vector<int> arr = {23,45,67,88,5, 7,7, 8, 10,11};
    int n = arr.size();
    int result= SearchEleemnt(arr,0,n-1,8);
    
    cout << "result: " << result << endl;
    

    return 0;
}