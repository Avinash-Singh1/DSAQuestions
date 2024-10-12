
#include <bits/stdc++.h>
using namespace std;

int compressstring_oppo(vector<char>& s, int n)
{
    

    int j = 0;
    for (int i = 0; i < n; )
    {
        char curr_char = s[i];
        int cnt = 0;
        while (i < n && s[i] == curr_char)
        {
            cnt++;
            i++;
        }
        s[j++] = curr_char;

        if (cnt > 1)
        {
            string temp = to_string(cnt);
            for (char c : temp)
            {
                s[j++] = c;
            }
        }
    }
    return j; 
}
int main()
{

    vector<char> s = {'a', 'a', 'a','a','a','a','a','a','a','a','a','a','a','a','a','a', 'b', 'b','b'};
    int n = s.size();
    int resultlen = compressstring_oppo(s, n);
    // for (int i = 0; i < resultlen; i++)
    // {
    //     s[i];
    // }
    
    cout<<resultlen<<endl;
    for (int i = 0; i < resultlen; i++)
    {
        cout<<s[i];
    }
    

    return 0;
}