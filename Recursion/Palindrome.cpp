
#include <bits/stdc++.h>
using namespace std;

int main(){
   cout<<"Enter the string"<<endl;
    string s; 
    cin>>s;
int n=s.length();
    
 int flag = true;
for(int i =0; i<n/2;i++)
{
   if(s[i]!=s[n-i-1])
   {
    flag = false;
   }
}
    cout << "You are " << (flag  ? "Palindrome." : "not a Palindrome.") << endl;
     return 0;  
}