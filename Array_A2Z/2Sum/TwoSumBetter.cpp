
#include <bits/stdc++.h>
using namespace std;

int main(){
   
 vector<int> arr ={2,6,5,8,11} ;
 int n =5;
 int target =14;

map<int,int> mpp;
for(int i =0; i<n;i++){

    int a = arr[i];
    int more = target -a;
    if(mpp.find(more)!= mpp.end()){
        cout<< "Yes"<<endl;
    }

    mpp[a]=i;

}
 return 0;  
}