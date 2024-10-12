
#include <bits/stdc++.h>
using namespace std;

 int hammingWeight(int n) {
    
        vector<int> arr;
        int i=0;
        while(n>=1)
         {   arr.push_back(n%2);
             n=n/2;
        
        }
        int cnt =0;
        for(auto i: arr){
            if(i==1){
                cnt++;
            }
        }
        return cnt;
        
    }

int main() {
    
   int res=  hammingWeight(11);
   cout<<res<<endl;;
    return 0;
}
