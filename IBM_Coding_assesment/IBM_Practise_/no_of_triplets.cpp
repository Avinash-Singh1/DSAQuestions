
#include <bits/stdc++.h>
using namespace std;
int no_of_Triple(vector<int> arr, int d)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum % d == 0)
                {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
int main()
{

    vector<int> arr = {3, 3, 4, 7, 8};
    //  vector<int>arr={5,6,3,4,3};
    //  vector<int>arr={5,7,3,4,4,3};
    int d = 5;
    int no_of_divisble = no_of_Triple(arr, d);
    cout << "Number of triplets divisible by " << d << " is " << no_of_divisble;

    return 0;
}