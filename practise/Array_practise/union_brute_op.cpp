
#include <bits/stdc++.h>
using namespace std;
void BruteUnion()
{
    int a[] = {1, 1, 2, 3};
    int b[] = {2, 3, 4, 4, 6};
    int n1 = 4;
    int n2 = 5;
    int i = 0;
    int j = 0;
    set<int> unioraarr;
    for (int i = 0; i < n1; i++)
    {
        unioraarr.insert(a[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        unioraarr.insert(b[i]);
    }

    for (auto i : unioraarr)
    {
        cout << " " << i << endl;
    }
}
void Optimised()
{
    int arr[] = {1, 1, 2, 3};
    int arr2[] = {2, 3, 4, 4, 6};
    int n1 = 4;
    int n2 = 5;
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n1 && j < n2)
    {

        if (arr[i] <= arr2[j])
        {
            if (ans.size() == 0 || ans.back() != arr[i])
            {
                ans.push_back(arr[i]);
            }

            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != arr2[j])
            {
                ans.push_back(arr2[j]);
            }

            j++;
        }
    }

    while (i < n1)
    {
        if (ans.size() == 0 || ans.back() != arr[i])
        {
            ans.push_back(arr[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (ans.size() == 0 || ans.back() != arr2[j])
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }

    for (auto i : ans)
    {
        cout << " " << i << endl;
    }
}

int main()
{

    // BruteUnion();
    Optimised();
    return 0;
}