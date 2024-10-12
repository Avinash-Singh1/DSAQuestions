
#include <bits/stdc++.h>
using namespace std;
vector<int> moveallZeros_optimised(vector<int> arr, int n)
{
    
    int j = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    cout<<"j: "<<j<<endl;

    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }

    for(auto i: arr){
        cout<<" "<<i <<endl;
    }
}
int main()
{

    vector<int> arr = {4, 5, 0, 4, 6, 0, 0, 8};

    vector<int> result;
    moveallZeros_optimised(arr, arr.size());

    // vector<int> temp;
    // int n = arr.size();
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] != 0)
    //     {
    //         temp.push_back(arr[i]);
    //     }
    // }

    // for (int i = 0; i < temp.size(); i++)
    // {
    //     arr[i] = temp[i];
    // }
    // int no_of_zeos = n - temp.size();
    // cout << "no of Zeros: " << no_of_zeos << " temp: " << temp.size() << endl;
    // for (int i = 4 + 1; i < n; i++)
    // {
    //     arr[i] = 0;
    // }

    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }

    return 0;
}