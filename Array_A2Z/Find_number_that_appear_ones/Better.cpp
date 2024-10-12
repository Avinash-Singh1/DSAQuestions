
#include <bits/stdc++.h>
using namespace std;

int main(){
   
vector<int> arr={22,22,11 ,11,67,45,67}  ;
map<int,int> mpp;
for (auto i : arr)
{
    mpp[i]++;
}

for(auto i: mpp)
{
    cout<<"moo: "<<i.second<<endl;
    if(i.second==1)
    {
        cout<<"found "<<i.first<<endl;
    }
}

   
 return 0;  
}