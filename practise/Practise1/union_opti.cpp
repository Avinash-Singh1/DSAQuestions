
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[] = {1, 1, 2, 3};
    int b[] = {2, 3, 4, 4, 6};
    int n1 = 4;
    int n2 = 5;
    int i =0; int j = 0;
    vector<int> unioraarr;
    while (i < n1 && j < n2)
    {
        if(a[i]<=b[j])
        {
            if(unioraarr.size()==0 || unioraarr.back() != a[i])
            {
                unioraarr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if(unioraarr.size()==0 || unioraarr.back() != b[j])
            {
                unioraarr.push_back(b[j]);
            }
            j++;
        }
    }

    while(i<n1)
    {
         if(unioraarr.size()==0 || unioraarr.back() != a[i])
            {
                unioraarr.push_back(a[i]);
            }
            i++;
    }

    while(j<n2)
    {
         if(unioraarr.size()==0 || unioraarr.back() != b[j])
            {
                unioraarr.push_back(b[j]);
            }
            j++;
    }


    for(auto i : unioraarr)
    {
        cout<<" i: "<<i<<" ";
    }

    return 0;
}