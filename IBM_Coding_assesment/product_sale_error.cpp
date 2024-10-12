
#include <bits/stdc++.h>
using namespace std;
int priceCheck(vector<string>products,vector<float> productsprice,vector<string> productSold, vector<float> soldprice){
    int countError=0;
    unordered_map<string,float> productsprice_map;

    for(int i=0; i<products.size();i++)
    {
        productsprice_map[products[i]]=productsprice[i];
    }

    for(int j =0; j<productSold.size();j++){
        if(productsprice_map.find(productSold[j])!= productsprice_map.end()){
            if(soldprice[j]!=productsprice_map[productSold[j]]){
                countError++;
            }
        }
    }

    return countError;
} 
int main(){
std::vector<std::string> products = {"eggs", "milk", "cheese"};
std::vector<float> productPrices = {2.89, 3.29, 5.79};
std::vector<std::string> productSold = {"eggs", "eggs", "cheese","cheese", "milk"};
std::vector<float> soldPrice = {2.89, 2.99, 5.97,7.6, 3.29};

int errors = priceCheck(products, productPrices, productSold, soldPrice);
cout<<"errors: "<<errors<<endl;
   
   
 return 0;  
}