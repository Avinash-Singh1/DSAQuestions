
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    v.erase(v.begin() + 1, v.begin() + 3);

    for (auto it : v)
    {
        cout << "second loop: " << it << endl;
    }
    v.insert(v.begin(), 3000);
    for (auto it : v)
    {
        cout << "second2 loop: " << it << endl;
    }

    return 0;
}