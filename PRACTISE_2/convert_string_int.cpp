
#include <bits/stdc++.h>
using namespace std;
int convert_s_int(string s){
    int i =0;
    int n =s.length();
    int ans = 0;
    // whitespaces
    if(i<n && s[i] == ' '){
        i++;
    }
    // handle sign
    int sign =1;
    if(i<n && (s[i]=='+' || s[i]=='-'))
    {
        sign = (sign== '-')?-1:1;
        i++;
    }

    // convert string to int
    while(i<n && isdigit(s[i]))
    {
        ans= ans*10 + (s[i]-'0');
        if(ans * sign >INT_MAX) return INT_MAX;
        if(ans * sign < INT_MIN) return INT_MIN;
        
        i++;
    }
    return static_cast<int>(ans*sign);
}
int main(){
   string s=" 1337c0d3";
cout<<"enter your number string\n";
// cin>>s;
// cout<<"your number string is "<<s<<endl;
int result = convert_s_int(s);
cout<<"Result: "<<result<<endl;

 return 0;  
}