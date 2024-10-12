
#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;
    int n = s.size();
    int hash[256]={0};
    for (char c : s)
    {
        hash[c]++;
        cout<<"char: "<<c<<endl;
    }

    cout << "Enter the  query to Find " << endl;
    char c;
    cin >> c;

cout << "The frequency of " << c << " is " << hash[c];
    return 0;
}