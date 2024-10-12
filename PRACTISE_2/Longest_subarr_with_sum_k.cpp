
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int cnt = 0;
    int target = -10;
    vector<int> arr = {10, 2, -2, -20, 10};
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {

            sum = sum + arr[j];
            if (sum == target)
            {
                cout << "hi" << endl;
                cnt++;
            }
        }
    }

    cout << "s:  " << cnt << endl;

    return 0;
}