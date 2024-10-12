
#include <bits/stdc++.h>
using namespace std;

void findTriplets(int price[], int n, int d)
{
   
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           for(int k=j+1;k<n;k++){
            int sum =price[i]+price[j]+price[k];
            if(sum%d==0){
                cnt++;
            }
           }

        }
    }
    cout<<cnt<<endl;
}
int main()
{

    int n = 5;
    int d = 5;
    int prices[n] = {3, 3, 4, 7, 8};
    findTriplets( prices,  n,  d);
    return 0;
}