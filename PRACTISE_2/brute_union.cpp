
#include <bits/stdc++.h>
using namespace std;
set<int> bruteUnion(vector<int> arr, vector<int> arr2){
     set<int> result;
    for(auto i: arr)
    {
        result.insert(i);
    }
    for(auto i: arr2)
    {
        result.insert(i);
    }

    return result;
}  

vector<int> OptimisedUnion(vector<int> arr, vector<int> arr2){
    int i =0; int j =0;
    int n1=arr.size();
    int n2=arr2.size();
    vector<int>uarr;

    while(i<n1 && j<n2)
    {
        if(arr[i]<=arr2[j])
        {
                    if(uarr.size()==0 || uarr.back()!=arr[i]){
                        uarr.push_back(arr[i]);
                       
                    }
                     i++;
        }
        else{
            if(uarr.size()==0 || uarr.back()!=arr2[j]){
                uarr.push_back(arr2[j]);
                
            }
            j++;
        }
    }

    while(i<n1)
    {
              if(uarr.size()==0 || uarr.back()!=arr[i]){
                        uarr.push_back(arr[i]);
                    }
                        i++;
    }

    while(j<n2)
    {
              if(uarr.size()==0 || uarr.back()!=arr2[j]){
                        uarr.push_back(arr2[j]);
                    }
                        j++;
    }

     return uarr;
}
int main()
{

   cout<<"Your Arrays: \n";
   vector<int> arr={1,1,2,3,4,5};
   vector<int> arr2={2,3,4,4,5,6};
    for(auto i :arr){
        cout<< " "<<i<<" ";
    }
    cout<<"\n";
     for(auto i :arr2){
        cout<< " "<<i<<" ";
    }
    cout<<"\n";


    set<int> result= bruteUnion(arr,arr2);
    cout<<"Final Union Brute Force\n";
    for(auto i : result){
        cout<< " "<<i<<" ";
    }
    cout<<"\nFinal Union OptimisedUnion Force\n";
    vector<int> result2= OptimisedUnion(arr,arr2);
    for(auto i : result2){
        cout<< " "<<i<<" ";
    }



    return 0;
}