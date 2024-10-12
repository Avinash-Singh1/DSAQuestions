
#include <bits/stdc++.h>
using namespace std;

string  compressstring(string s,int n){
    string ans;
    for(int i=0;i<n;i=i+2){
        char c = s[i];
        int num =s[i+1]-'0';
        for (int i = 0; i < num; i++)
        {
            ans+=c;
        }
        
    }
    return ans;
    
}
int main(){
   
 string s = "a3b2f6";
 int n = s.length();
 string result =compressstring(s,n);
 cout<<"Result: "<<result<<endl;
   
 return 0;  
}