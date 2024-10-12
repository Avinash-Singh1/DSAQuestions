
#include <bits/stdc++.h>
using namespace std;
vector<int> intersectionofarr(vector<int>a,vector<int> b){
    int n =a.size(); int m =b.size();
    int i =0, j=0;
   
    vector<int> ans;
    while(i<n && j<m){
        if(a[i]<b[j]){
            // ans.push_back(a[i]);
            i++;
        }
        else if(a[i]>b[j]){
            //  ans.push_back(b[j]);
            j++;
        }
        else{
           ans.push_back(a[i]);
           i++;j++;
        }
    }
       for(auto i : ans){
    cout<<i<<" ";
   }
    return ans;
}
int main(){
   
 vector<int> a={1,22,3,55,6,7}  ;
 vector<int> b={22,55,7,1} ;
 sort(a.begin(),a.end()) ;
 sort(b.begin(),b.end()) ;
 cout<<"sorted b: \n";
 for(auto i: b)
 {
    cout<<i<<" ";
 }
 cout<<"\n";
vector<int> result = intersectionofarr(a,b);
cout<<"result: "<<endl;
   for(auto i : result){
    cout<<i<<" ";
   }
 return 0;  
}