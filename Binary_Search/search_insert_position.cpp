
#include <bits/stdc++.h>
using namespace std;


int Last(vector<int> arr, int l, int h, int tar)
{
    int last = 0;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] >= tar)
        {
            last = mid;
            h = mid -1;
        }
       
        else
        {
            l = mid + 1;
        }
    }
    return last;
}


int main()
{

    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int n = arr.size();
    int result= Last(arr,0,n-1,8);
    
    cout << "result: " << result << endl;
    

    return 0;
}