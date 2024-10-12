#include<bits/stdc++.h>

using namespace std;
void findfirst(int l, int h, int key, vector < int > & v,int &first){
    if(l>h) return ;

    int mid= l+(h-l)/2;
    if(v[mid]==key){
        first =mid;
        h= mid-1;
        return findfirst(l,h,key,v,first);
    }
    else if(v[mid]>key){
        h= mid-1;
        return findfirst(l,h,key,v,first);

    }
    else{
        l= mid+1;
        return findfirst(l,h,key,v,first);

    }
}
void findlast(int l, int h,int key, vector < int > & v,int &last){
    if(l>h) return ;

    int mid= l+(h-l)/2;
    if(v[mid]==key){
        last =mid;
        l= mid+1;
       return findlast(l,h,key,v,last);
    }
    else if(v[mid]>key){
        h= mid-1;
        return findlast(l,h,key,v,last);
    }
    else{
        l= mid+1;
        return findlast(l,h,key,v,last);
    }

}
vector<int> solve(int n, int key, vector < int > & v) {
    int first=-1;int last=-1;
   findfirst(0,n-1,key,v,first);
   findlast(0,n-1,key,v,last);
   cout<<"total occurence: "<<(last-first)+1<<endl;
   return {first,last};

}

int main() {
  int n = 8;
  int key = 13;
  vector < int > v = {3,4,13,13,13,20,20,40};
   
  // returning the last occurrence index if the element is present otherwise -1
//   cout << solve(n, key, v) << "\n";
 vector<int> ans =solve(n, key, v) ;

 for(auto i: ans){
    cout<<" "<<i;
 }


  return 0;
}