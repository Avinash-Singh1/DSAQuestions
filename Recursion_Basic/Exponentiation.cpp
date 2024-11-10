
#include <bits/stdc++.h>
using namespace std;
int findResult(int n ,int m){
    if(m==0)return 1;

    return n* findResult(n,m-1);
}
int main(){
   
 int n=5; int m =3;

 cout<<"resulr: "<<findResult(n,m) <<" "<<endl; 
   
 return 0;  
}