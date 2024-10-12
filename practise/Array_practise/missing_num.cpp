
#include <bits/stdc++.h>
using namespace std;
void optimised_missing(){
  vector<int> arr={1,2,4,5};
  int n=arr.size();
  int xorr=0;
  int xorr2=0;
  for(int i=0;i<n-1;i++){
    xorr=xorr^ arr[i];
    xorr2= xorr2^(i+1);
  }
   xorr =xorr^n;
   xorr2=xorr2^xorr;
  cout<<xorr2<<endl;
}
int main(){
   
  vector<int> arr={1,2,4,0,5};
  int n=arr.size();
  cout<<"optimised missing:\n";
  optimised_missing();
//   cout<<n<<endl;
  map<int,int> mpp;
  for (size_t i = 0; i < n; i++)
  {
    mpp[i]=arr[i]!=0?1:0;
  }
  
//   cout<<"map size: "<<mpp.size();
    for(auto i: mpp){
        if(i.second ==0 && i.first!=0)
        {
            cout<<i.second<<" missing number "<<i.first<<endl;
            break;
        }
    }


   
 return 0;  
}