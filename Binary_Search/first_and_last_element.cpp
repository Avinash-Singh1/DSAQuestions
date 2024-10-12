
#include <bits/stdc++.h>
using namespace std;
int First(vector<int> arr, int l, int h, int tar)
{
    int first = 0;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] == tar)
        {
            first = mid;
            h = mid - 1;
        }
        else if (arr[mid] > tar)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return first;
}

int Last(vector<int> arr, int l, int h, int tar)
{
    int last = 0;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] == tar)
        {
            last = mid;
            l = mid + 1;
        }
        else if (arr[mid] > tar)
        {
            h = mid - 1;
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
    int result[] = {First(arr,0,n-1,8),Last(arr,0,n-1,8)};
    for(auto i: result){
        cout << "result: " << i << endl;
    }

    return 0;
}