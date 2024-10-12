
#include <bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int> greed,vector<int> cookieSize){
   int l=0;// it will point size of each cookie
   int r=0; // it will point to each child which is content;
   int m= cookieSize.size();
   sort(greed.begin(),greed.end());
   sort(cookieSize.begin(),cookieSize.end());
   while(l<m)
   {
     if(greed[r]<=cookieSize[l]){
        r++;
     }
        l++;
   } 
   return r;
}
int main(){
   
     vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookieSize = {4, 2, 1, 2, 1, 3};
    
    cout << "Array Representing Greed: ";
    for(int i = 0; i < greed.size(); i++){
        cout << greed[i] << " ";
    }
    cout << endl;
    cout << "Array Representing Cookie Size: ";
    for(int i = 0; i < cookieSize.size(); i++){
        cout << cookieSize[i] << " ";
    }
    
    int ans = findContentChildren(greed, cookieSize);
    
    cout << endl << "No. of kids assigned cookies "<< ans;
    cout << endl;

    return 0;
}