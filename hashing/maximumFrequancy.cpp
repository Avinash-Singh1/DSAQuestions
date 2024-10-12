
#include <bits/stdc++.h>
using namespace std;

int main(){
   
   
   vector<int> nums={1,1,2,2,3,3,4,5};
   map<int,int> mpp;
  
   for (int num : nums) {
            mpp[num]++;
    }
    int maxfreq=0;
    for(auto i: mpp)
    {
        // cout<<i.first<<" "<<i.second<<endl;
       maxfreq= max(maxfreq,i.second);
    }

    cout<<"maxfreq: "<<maxfreq<<endl;

    int numofMaxelement=0;
    for(auto i: mpp)
    {
      if(i.second==maxfreq)
      {
        numofMaxelement++;
      }
    }

    cout<<numofMaxelement;

 return 0;  
}