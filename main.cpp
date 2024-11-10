
#include <bits/stdc++.h>
using namespace std;

int main(){
   
   string name="avinash is a good boy";
    istringstream stream(name);
    string word;
    string s = "";
    stack<string>st;

    while(stream>>word){
        // cout<<" "<<word<<" ";
        st.push(word);
    }

    while(!st.empty()){
        s+=st.top();
        st.pop();
        if(!st.empty()){
            s+=" ";
        }
    }

    cout<<" "<<s<<" "<<endl;
   
 return 0;  
}