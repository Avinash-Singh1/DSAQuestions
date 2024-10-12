
#include <bits/stdc++.h>
using namespace std;
int isCheck(vector<string> products, vector<float> productPrices, vector<string> productSold, vector<float> soldPrice)
{
    int cnt =0;int j =0;
    unordered_map<string,float>p_map;
    for(auto i:products ){
        p_map[i]=productPrices[j];
        j++;
    }
    for(int i=0;i<productSold.size();i++){
        if(p_map.find(productSold[i])!= p_map.end()){
            if(soldPrice[i]!=p_map[productSold[i]]){
                cnt++;
            }
        }
    }
    return cnt;
    
}
int main()
{
    vector<string> products = {"eggs", "milk", "cheese"};
    vector<float> productPrices = {2.89, 3.29, 5.79};
    vector<string> productSold = {"eggs", "eggs", "cheese", "cheese", "milk"};
    vector<float> soldPrice = {2.89, 2.99, 5.97, 7.6, 3.29};
    int no_error = isCheck(products, productPrices, productSold, soldPrice);
    cout<<"number of errors: "<<no_error<<endl;
    return 0;
}