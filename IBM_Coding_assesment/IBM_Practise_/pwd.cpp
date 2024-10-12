

#include <bits/stdc++.h>
using namespace std;

int getMinFlips(string pwd){
    int n = pwd.length();
    int cnt =0;
    for (int i = 0; i < n; i=i+2)
    {
        string substring = pwd.substr(i,min(i+2,n)-i);
        if(substring.find('0') != string::npos && substring.find('1') != string::npos){
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    string pwd = "1110011000";
    int result = getMinFlips(pwd);
    cout<<"Minimum number of flips required: "<< result<<endl;

    return 0;
}