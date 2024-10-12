
#include <bits/stdc++.h>
using namespace std;
int partion(vector<int>& arr, int l, int h){
    int pivot = arr[h];
    int pindex = l;
    for(int i = l+1; i <= h; i++){
        if(arr[i]<pivot){
            swap(arr[i],arr[pindex]);
            pindex++;
        }
       
    }
    swap(arr[h],arr[pindex]);
    return pindex;
}

void quickSort(vector<int>& arr, int l,int h )
{
    if(l<h)
    {
        int p = partion(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1, h);
    }
}
int main(){
   
 vector<int> arr={34,6,7};

    quickSort(arr,0,arr.size()-1);
 
 vector<string> str_nums;
  for (int i = arr.size() - 1; i >= 0; i--) {
    str_nums.push_back(to_string(arr[i]));
}
string s ;
for(auto i:str_nums)
{
    s.append(i);
}
cout<<s;
   
 return 0;  
}