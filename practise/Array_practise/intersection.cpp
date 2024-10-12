
#include <bits/stdc++.h>
using namespace std;
void optimiesedintersection()
{
    int a[] = {1,2,2,3,3,4,5,6};
    int b[] = {1,2, 3, 4, 4,6};
    int n1 = 7;
    int n2 = 6;
    vector<int> ans;
    vector<int> visited(n2,0);
    int i=0; int j=0;
    while(i<n1 && j<n2){
        if(a[i]==b[j]){
            ans.push_back(a[i]);
            i++; j++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    for(auto i: ans){
        cout<<" "<<i<<endl;
    }

   
}
int main(){
   
    // int a[] = {1, 1,1, 2, 4,4,6};
    // int b[] = {1,2, 3, 4, 4,6};
    // int n1 = 7;
    // int n2 = 6;
    // vector<int> ans;
    // vector<int> visited(n2,0);

    // for(int i =0; i<n1;i++){
    //     for(int j =0; j<n2;j++){
    //         if(a[i]==b[j] && visited[j]!=1){
    //             ans.push_back(a[i]);
    //             visited[j] = 1;
    //             break;
    //         }
    //         if(a[i]<b[j]) break;
    //     }
    // }
    // for(auto i: ans)
    // {
    //     cout<<" "<<i<<endl;
    // }
  optimiesedintersection();

   
 return 0;  
}