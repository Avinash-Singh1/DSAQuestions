
#include <bits/stdc++.h>
using namespace std;

int main(){
   
  vector<int> arr={1,2,4,0,5};
  int n=arr.size(); int sum =0;
  cout<<"n: "<<n<<endl;
  int xorr =0;
  int xorr2 =0;
  for(int i =1;i<=n;i++)
  {
    xorr^=i ;
  }
   for(int i =0;i<n;i++)
  {
    xorr2^=arr[i] ;
  }
  int result =xorr ^ xorr2;
  cout<<"result "<<result<<endl;


   
 return 0;  
}