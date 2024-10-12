
#include <bits/stdc++.h>
using namespace std;

int main(){
   
  
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  int i=0; int j=0;
  vector<int> Unionarr;

  while (i<n && j<m)
  {
    if (arr1[i] <= arr2[j])
    {
        if(Unionarr.size()==0 || Unionarr.back() != arr1[i]){
            Unionarr.push_back(arr1[i]);
        }
         i++;
    }else{
        if(Unionarr.size()==0 || Unionarr.back() != arr2[j]){
            Unionarr.push_back(arr2[j]);
        }
        j++;
    }
  }

  while (i<n)
  {
    if(Unionarr.size()==0 || Unionarr.back()!= arr1[i])
    {
    Unionarr.push_back(arr1[i]);
    }
    i++;
  }
   while (j<m)
  {
    if(Unionarr.size()==0 || Unionarr.back()!= arr2[j]){
      Unionarr.push_back(arr2[j]);
    }
    j++;
  }
  
    for(auto i : Unionarr)
    {
        cout<<" unionarr: "<<i<<endl;
    }

 return 0;  
}