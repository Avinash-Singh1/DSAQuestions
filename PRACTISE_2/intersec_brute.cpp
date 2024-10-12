
#include <bits/stdc++.h>
using namespace std;
vector<int> bruteinter(vector<int> arr,vector<int> arr2){
    vector<int> ans;
    int n=arr.size();
    int m=arr2.size();
    vector<int> vis(m,0);

    for(auto i: arr)
    {
        for(int j = 0;j<m;j++){
            if(i==arr2[j] && vis[j] ==0)
            {
                ans.push_back(i);
                vis[j]=1;
                break;
            }
        }
    }
    return ans;
}

 vector<int> OptimisedUnion(vector<int> arr, vector<int> arr2)
{
    int n =arr.size();
    int m =arr2.size();
    int i=0; int j=0;
    vector<int> ans;

    while(i<n && j<m)
    {
        if(arr[i]==arr2[j])
        {
            ans.push_back(arr[i]);
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
}
int main(){
   
   cout<<"Your Arrays: \n";
   vector<int> arr={1,1,1,2,3,4,5};
   vector<int> arr2={2,3,4,1,4,5,5,5,6};
    for(auto i :arr){
        cout<< " "<<i<<" ";
    }
    cout<<"\n";
    for(auto i :arr2){
        cout<< " "<<i<<" ";
    }
    cout<<"\n";

  vector<int> result =  bruteinter(arr,arr2);
  cout<<"Brute Intersection Result\n";
  for(auto i :result){
    cout<< " "<<i<<" ";
  }

cout<<"\nOptimised: \n";
vector<int> ans= OptimisedUnion(arr,arr2);
  for(auto i: ans)
  {
    cout<<" "<<i<<" ";
  }
   
 return 0;  
}