
#include <bits/stdc++.h>
using namespace std;

int main(){
   
vector<int> arr={22,22,11 ,11,67,45,67}  ;
int xorr=0;
for(auto i: arr)
{
   xorr =xorr^i;
}
cout<<xorr<<endl;

   
 return 0;  
}