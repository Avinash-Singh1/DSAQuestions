
#include <bits/stdc++.h>
using namespace std;

int main(){
   
   vector<int> g1;
   g1.push_back(1);
   g1.push_back(2);
   g1.push_back(3);
   g1.emplace_back(300);
   for(auto i=g1.begin(); i!=g1.end();i++){
    cout<<"*i: "<<*i;
   }

   for (int i = 10; i < 20; i=i+2)
   {
    g1.push_back(i);
   }


   for(auto i=g1.begin(); i!=g1.end();i++){
    cout<<*i<<endl;
   }
   

   
 return 0;  
}