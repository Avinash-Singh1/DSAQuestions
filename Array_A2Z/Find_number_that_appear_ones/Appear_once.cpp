
#include <bits/stdc++.h>
using namespace std;

int main(){
   
vector<int> arr={22,22,11 ,11,67,45,67}  ;

for (auto i : arr)
{
    cout<<" "<<i;
}

int cnt=0;
int num;
for (int i = 0; i < arr.size(); i++)
{
     num =arr[i];
    for (int j = 0; j < arr.size(); j++)
    {
        if(arr[j]==num)
        {
            cnt++;
        }
    }
    if(cnt==1)
    {
        cout<<endl<<num<<" is unique";
    }
    cnt=0;
    
}


   
 return 0;  
}