
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector <int> arr){

    int n = arr.size();
    int minp=arr[0];
    int maxprofit= 0;
    for(int i=1;i<n;i++){
        minp=min(minp,arr[i]);
        int profit = arr[i]-minp;
        maxprofit = max(maxprofit,profit);
    }
    return maxprofit;
}
int main(){
   
vector<int> prices = {7, 1, 5, 3, 6, 4};
vector<int> prices = {7, 1, 5, 3, 6, 4};
cout << "Maximum Profit: " << maxProfit(prices) << std::endl;
 return 0;

}