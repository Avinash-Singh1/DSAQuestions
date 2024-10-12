
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    vector<int> temp;
    int n = arr.size();
    cout << "size: " << arr.size() << endl;

    int d = 3;

    for (int i = 0; i < d; i++)
    {
        temp.push_back(arr[i]);
        // cout<<"temp: "<<arr[i]<<endl;
    }

    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
        // cout<<"val:"<<arr[i]<<endl;
    }

    for (int i = n - d; i < n; i++)
    {
        // arr.push_back(temp[i]);
        // arr[n-i+1]=temp[i];
        arr[i] = temp[i - (n - d)];
    }

    cout << "final New Array:" << endl;
    // cout<<"size: "<<arr.size()<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "arr[i]: " << arr[i] << endl;
    }

    return 0;
}